/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParseRequest.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglass <sglass@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 16:21:08 by sglass            #+#    #+#             */
/*   Updated: 2021/06/26 13:02:38 by sglass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PARSEREQUEST_H
#define PARSEREQUEST_H
    #include <string>
    #include <iostream>
    #include <sstream>
    #include <cstring>
	#include <sys/stat.h>
	#include <fcntl.h>
	#include <unistd.h>
    #include "../config_parser/Server.hpp"

class ParseRequest
{
    private:
		// std::map<std::string, std::string> _extensions;
        std::string _req;
        Server _server;
        int _flagErr;          //nahera
        std::string _method;
        std::string _reqPath;
        std::string _httpVersion;

        std::string _allowMethods;

		std::string _host;
        std::string _contentLength;
        std::string _contentType;
        std::string _boundary;
        std::string _referer;
        std::string _transferencoding;
        std::string _date;

        std::string tmpRoot;
		// std::string _contentFile;
		std::string _path;
		int _responseCode;
		int _status;
		int _fd;
		// int _fileSize; 


    public:
        ParseRequest(std::string req, Server serv);
        ParseRequest();
        // ParseRequest(ParseRequest const& src);
        ~ParseRequest();
        void parseStartString();
        void parseHeaders();

        void validStartString();
        void makePath(Location loca);
        int getStatus();
        // void validRequest();
        int getFd();
	    // int getFileSize();
        // std::string &getContentFile();
	    void setResponseCode(int responseCode);
		void setStatusAndPrepareFd();
        std::string getPath();

		
        std::string getRequest();
		std::string cutReqReturnParam(std::string& req, int count);

        int countToChar(std::string req,char ch);
        int scipSpace(std::string str);

        int getFlagErr();
        std::string getMethod();
        std::string getReqPath();
        std::string getHttpVersion();
        std::string getHost();
		int getResponseCode();
        std::string getAllowMethods();

        std::size_t getLocation(std::vector <Location> locs);
        bool isMethodAllowed(std::string method, std::vector <std::string> methods);
    };





#endif
