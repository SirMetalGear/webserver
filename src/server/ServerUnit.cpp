#include "ServerUnit.hpp"

ServerUnit::ServerUnit(Server &serverConfig) : config(serverConfig),
		port(serverConfig.getPort()), host(serverConfig.getHost())
{
	initializeSocket();
    std::cout << "host: |" << host << "|\n";
    std::cout << "port: |" << port << "|\n";
}

ServerUnit::~ServerUnit()
{}

void	ServerUnit::initializeSocket()
{
	int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (serverSocket == -1)
	{
		std::cerr << "socket creation failed!\n";
	}
	this->serverSocket = serverSocket;
}

int	ServerUnit::acceptNewClient()
{
	struct sockaddr_in clientAddr;
	socklen_t sizeOfClientAddr = sizeof(clientAddr);
	int clientSocket = accept(serverSocket, (sockaddr *)&clientAddr, &sizeOfClientAddr);
	if (clientSocket == -1)
	{
		std::cerr << "client socket failed!\n";
	}
	if (fcntl(clientSocket, F_SETFL, O_NONBLOCK) < 0)
	{
		std::cerr << "fcntl error\n";
	}
	clients.push_back(Client(clientSocket, clientAddr, config));
	return clientSocket;
}

void	ServerUnit::startListening()
{
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	// addr.sin_addr.s_addr = inet_addr(host.c_str());
	addr.sin_addr.s_addr = INADDR_ANY;
    std::cout << "s.addr: " << addr.sin_addr.s_addr << "\n";
	setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR, &addr, sizeof(addr));
	if (bind(serverSocket, (sockaddr *)&addr, sizeof(addr)) == -1)
	{
		std::cerr << "binding failed!\n";
        std::cout << strerror(errno) << std::endl;
	}
	listen(serverSocket, SOMAXCONN);
	std::cout << "Server is listening: " << serverSocket << " socket!\n";
}

std::vector<Client>	&ServerUnit::getClients()
{
	return clients;
}

int	ServerUnit::getSocket()
{
	return serverSocket;
}

void	ServerUnit::deleteClient(std::vector<Client>::iterator clientIt)
{
	clients.erase(clientIt);
}