#include "ServerGroup.hpp"
#include "./../utils/utils.hpp"

#define READY_FOR_REQUEST 1
#define CHUNKED_RECEIVE 2
#define BODYBUFF_RECEIVE 3
#define READY_TO_RESPONSE 4
#define CURRENTLY_RESPONDING 5

ServerGroup::ServerGroup(Config &config)
{
	serversCount = config.getServers().size();
	for (size_t i = 0; i < serversCount; i++)
	{
		servers.push_back(ServerUnit(config.getServers().at(i)));
	}
	std::cout << "all server has been initialized\n";
	contentType = ft::initilizeContentTypes();
}

ServerGroup::~ServerGroup()
{}

void	ServerGroup::startServers()
{
	fd_set	readSet;
	fd_set	writeSet;
	int		maxFd = 0;

	FD_ZERO(&readSet);
	FD_ZERO(&writeSet);
	std::list<ServerUnit>::iterator servIt = servers.begin();
	std::list<ServerUnit>::iterator servEnd = servers.end();
	while (servIt != servEnd)
	{
		servIt->startListening();
		int	serverSocket = servIt->getSocket();
		if (serverSocket > maxFd)
		{
			maxFd = serverSocket;
		}
		FD_SET(serverSocket, &readSet);
		// FD_SET(serverSocket, &writeSet);
		++servIt;
	}
	while (true)
	{
		fd_set	copyReadSet;
		fd_set	copyWriteSet;
		FD_COPY(&readSet, &copyReadSet);
		FD_COPY(&writeSet, &copyWriteSet);
		int	activity = select(maxFd + 1, &copyReadSet, &copyWriteSet, NULL, NULL);
		servIt = servers.begin();
		while (servIt != servEnd)
		{
			if (FD_ISSET(servIt->getSocket(), &copyReadSet))
			{
				int clientSocket = servIt->acceptNewClient();
				FD_SET(clientSocket, &readSet);
				FD_SET(clientSocket, &writeSet);
				if (clientSocket > maxFd)
					maxFd = clientSocket;
				std::cout << "new connection: " << clientSocket << std::endl;
			}
			std::vector<Client>::iterator clientIt = servIt->getClients().begin();
			std::vector<Client>::iterator clientEnd = servIt->getClients().end();
			while (servIt->getClients().size() && clientIt != clientEnd)
			{
				if (FD_ISSET(clientIt->getSocket(), &copyReadSet) &&
					(clientIt->getStatus() == READY_FOR_REQUEST ||
						clientIt->getStatus() == CHUNKED_RECEIVE))
				{
					std::cout << "client with socket: " << clientIt->getSocket() << " has request\n";
					if (clientIt->recieveRequest(contentType) == 0)
					{
						FD_CLR(clientIt->getSocket(), &readSet);
						FD_CLR(clientIt->getSocket(), &writeSet);
						servIt->deleteClient(clientIt++);
						continue;
					}
				}
				if (FD_ISSET(clientIt->getSocket(), &copyWriteSet)
						&& clientIt->getStatus() == READY_TO_RESPONSE)
				{
					clientIt->sendResponse();
				}
				++clientIt;
			}
			++servIt;
		}
	}
}

std::list<ServerUnit> &ServerGroup::getServers()
{
	return servers;
}
