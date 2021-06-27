#include "Response.hpp"

Response::Response(ParseRequest pars)
{
	_pars = pars;
}

Response::~Response()
{
}

void Response::makeResponseHead(std::map<std::string, std::string> &contentType)
{
	if (_pars.getResponseCode() >= 300 &&  _pars.getResponseCode() <= 307)
	{
		_response.append("HTTP/1.1").append(" ").append(std::to_string(_pars.getResponseCode())).append("\r\n");
		_response.append("Version: ").append("HTTP/1.1").append("\r\n");
		_response.append("Allow: ").append(_pars.getAllowMethods()).append("\r\n");
		_response.append("Location: ").append(_pars.getPath()).append("\r\n");
		// _response.append("Content-Length: 0");
		_response.append("\r\n");
	}
	else
	{
		_response.append("HTTP/1.1").append(" ").append(std::to_string(_pars.getResponseCode())).append("\r\n");
		_response.append("Version: ").append("HTTP/1.1").append("\r\n");
		_response.append("Allow: ").append(_pars.getAllowMethods()).append("\r\n");
		_response.append("Content-Type: ").append(findContentType(_pars.getPath(), contentType)).append("\r\n");
		if (_pars.getResponseCode() == 200)
			_response.append("Content-Length: ").append(std::to_string(_fileSize));
		else
			_response.append("Content-Length: 0");
	_response.append("\r\n\r\n");
	}

	// std::cout << _response << std::endl;

}

void Response::makeResponseBody()
{
	if (_pars.getResponseCode() == 200)
	{
		if (_pars.getMethod().compare("GET") == 0)
		{
			_response.append(_contentFile);
			// _response.append("\r\n\r\n");
			std::cout << "RESPONSE SIZE AFTER APPEND: " << _response.length() << std::endl;
		}
	}
	else
	{
		std::cout << "ploho\n";
		// exit(1);
		//kinut 404
	}
}

std::string& Response::getResponse()
{
	return(_response);
}


std::string Response::getFileExtension(std::string path)
{
	std::string fileExtension;
	int i;
	int last;

	i = 0;
	last = -1;
	while(i < path.length())
	{
		if (path.at(i) == '/')
			last = i;
		i++;
	}
	if (path.length() == 0 || path.length() - 1 == last)
		return (std::string());
	fileExtension = path.substr(last + 1, path.length() - last - 1);
	int res = fileExtension.find(".", 0);
	if (res == -1)
		return (std::string());
	fileExtension = fileExtension.substr(res + 1, fileExtension.length() - res - 1);
	// std::cout << fileExtension << std::endl;
	return (fileExtension);
}

// std::string Response::findContentType(std::string path, std::map<std::string, std::string> &content)
// {
// 	std::string contentType;
// 	std::map<std::string, std::string>::iterator find;
// 	std::string key = getFileExtension(path);
// 	find = content.find(key);
// 	std::cout << "\n\nKEY: " << key << "value: " << find->second << "\n\n";


		// contentType = find->second;
		// return (contentType);
// 	// }
// 	// else
// 	// {
// 	// 	contentType = "text/html";
// 	// 	return (contentType);
// 	// }
// }

std::string Response::findContentType(std::string path, std::map<std::string, std::string> &content)
{
    std::string contentType;
    std::map<std::string, std::string>::iterator find;
    std::string key = getFileExtension(path);
    find = content.find(key);
    if (find != content.end())
        contentType = find->second;
    else
        contentType = "";
    return (contentType);
}

void Response::validRequest()
{
	if (_pars.getMethod().compare("GET") == 0 && (_pars.getResponseCode() < 300 || _pars.getResponseCode() > 307))
	{
		struct stat stat_buf;
		_fd = open(_pars.getPath().c_str(), O_RDWR, 666);
		if (_fd < 0)
		{
			std::cout << "ETO PATHICK" << _pars.getPath() << std::endl;
			std::cout << "file not found\n";
			_pars.setResponseCode(404);
			return ;
		}
    	int rc = fstat(_fd, &stat_buf);
		if (rc == -1)
		{
			std::cout << "cant count file\n";
			_pars.setResponseCode(1);
			return;
		}
		_fileSize = stat_buf.st_size;
		char buf[_fileSize];
		int res = read(_fd, buf, _fileSize);
		if (res < 0)
		{
			std::cout << "error while reading\n";
			exit(1);
		}
		_contentFile.append(std::string(buf, _fileSize));
		close(_fd);
	}
	if (_pars.getMethod().compare("POST") == 0)
	{
		
	}
}

int Response::getFd()
{
	return(_fd);
}

int Response::getFileSize()
{
	return(_fileSize);
}

std::string &Response::getContentFile()
{
	return (_contentFile);
}
