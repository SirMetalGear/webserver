#include "Client.hpp"

#define READY_FOR_REQUEST 1
#define CHUNKED_RECEIVE 2
#define BODYBUFF_RECEIVE 3
#define READY_TO_RESPONSE 4
#define CURRENTLY_RESPONDING 5
#define LENGTH_RECEIVING 10
#define BUF_RECEIVING 11
#define BUFFER_SIZE 10240

Client::Client(int socket, struct sockaddr_in &sockAddr, Server &config)
: serverConfig(config), clientSocket(socket), clientAddr(sockAddr),
					status(READY_FOR_REQUEST), chunkedStatus(LENGTH_RECEIVING)
{
	this->requestHeader.reserve(BUFFER_SIZE);
}

Client::~Client()
{}

int	Client::getSocket()
{
	return clientSocket;
}

int	Client::getStatus()
{
	return status;
}

void	Client::sendResponse()
{
	int sent = send(clientSocket, response.c_str(), response.length(), 0);
	std::cout << "sent: " << sent << " out of: " << response.length() << std::endl;
	if (sent - response.length() == 0)
	{
		status = READY_FOR_REQUEST;
		this->requestHeader.clear();
		this->requestBody.clear();
		this->response.clear();
	}
}

void	Client::parseRequestHeader(std::map<std::string, std::string> &contentType)
{
    ParseRequest pars(this->requestHeader, serverConfig);
    pars.parseStartString();
    pars.parseHeaders();
	pars.validStartString();
	pars.setStatusAndPrepareFd();
	status = pars.getStatus();
	if (status == CHUNKED_RECEIVE)
	{
		// saveFileFd = pars.getFd();
	}
	// status = READY_TO_RESPONSE;
	Response resp(pars);
	resp.validRequest();
    resp.makeResponseHead(contentType);
    resp.makeResponseBody();
	this->response = resp.getResponse();
	std::cout << "RESPONSE - " << response << std::endl;
}

int	Client::recieveRequest(std::map<std::string, std::string> &contentType)
{
	std::cout << "receiving...\n";
	char buf[BUFFER_SIZE];
	int received = recv(clientSocket, buf, BUFFER_SIZE, 0);
	if (received == -1)
	{
		std::cerr << "error with recv\n";
		return -1;
	}
	if (received == 0)
	{
		std::cout << "connection closed\n";
		return 0;
	}
	if (status == READY_FOR_REQUEST)
	{
		requestHeader.append(buf, received);
		bzero(buf, received);
		size_t headerAndBodySplitter;
		headerAndBodySplitter = requestHeader.find("\r\n\r\n");
		if (headerAndBodySplitter != std::string::npos)
		{
			requestHeader = requestHeader.substr(0, headerAndBodySplitter + 4);
			if (headerAndBodySplitter + 4 < requestHeader.size())
			{
				requestBody = requestHeader.substr(headerAndBodySplitter + 4);
			}
			std::cout << "request header BEFORE parsing" << requestHeader << std::endl;
			if (requestHeader != "0")
				parseRequestHeader(contentType);
		}
	}
	if (status == CHUNKED_RECEIVE && *buf != '\0')
	{
		std::cout << "\n\nCHUUUNKKEEEEEEED\n\n";
		if (!requestBody.empty())
		{
			chunkedRequestBuf.append(requestBody);
			requestBody.clear();
		}
		else
		{
			chunkedRequestBuf.append(buf, received);
		}
		size_t splitter;
		while ((splitter = chunkedRequestBuf.find("\r\n\r\n")) != std::string::npos)
		{
			if (chunkedStatus == LENGTH_RECEIVING)
			{
				chunkedRequestLength = chunkedRequestBuf.substr(0, splitter);
				chunkedLineLength = std::strtol(chunkedRequestLength.c_str(), NULL, 10);
				if (chunkedLineLength == 0)
				{
					// close(saveFileFd);
					chunkedRequestBuf.clear();
					chunkedRequestLength.clear();
					chunkedSaveLine.clear();
					status = READY_TO_RESPONSE;
					return 1;
				}
				chunkedSaveLine.reserve(chunkedLineLength);
				chunkedRequestBuf = chunkedRequestBuf.substr(splitter + 4);
				chunkedStatus = BUF_RECEIVING;
				continue;
			}
			if (chunkedStatus == BUF_RECEIVING)
			{
				chunkedSaveLine.append(chunkedRequestBuf.substr(0, chunkedLineLength));
				chunkedRequestBuf = chunkedRequestBuf.substr(splitter + 4);
				// int res = write(saveFileFd, chunkedSaveLine.c_str(), chunkedLineLength);
				// if (res < 0)
				// {
				// 	std::cerr << "ERROR WHILE SAVING FILE WITH CHUNKED LINE\n";
				// 	exit(1);
				// }
				chunkedStatus = LENGTH_RECEIVING;
				continue;
			}
		}
	}
	return 1;
}
