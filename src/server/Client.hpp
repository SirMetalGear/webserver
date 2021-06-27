#ifndef CLIENT_HPP
# define CLIENT_HPP

#include <string>
#include <netinet/in.h>
#include "./../request_parser/Response.hpp"
#include "./../config_parser/Server.hpp"

class Client
{
private:
	int					clientSocket;
	int					status;
	int					saveFileFd;
	int					chunkedStatus;
	Server				serverConfig;
	std::string			response;
	std::string			requestBody;
	std::string			requestHeader; // defined 
	std::string			chunkedRequestLength;
	std::string			chunkedRequestBuf;
	std::string			chunkedSaveLine;
	long				chunkedLineLength;
	struct sockaddr_in	clientAddr;

	ParseRequest &parseHeader(std::map<std::string, std::string> &contentType);
public:
	Client(int socket, struct sockaddr_in &sockAddr, Server &config);
	~Client();
	void	parseRequestHeader(std::map<std::string, std::string> &contentType);
	int		getSocket();
	int		recieveRequest(std::map<std::string, std::string> &contentType);
	int		getStatus();
	void	sendResponse();
};

#endif
