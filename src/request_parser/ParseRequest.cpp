#include "ParseRequest.hpp"

ParseRequest::ParseRequest()
{
    
}
ParseRequest::ParseRequest(std::string req, Server serv)
{
	_server = serv;
    _req = req;
    _flagErr = -1;
	tmpRoot = _server.getRoot();
	_responseCode = 200;	
}
// ParseRequest::ParseRequest(ParseRequest const& src)
// {
//     _req = src._req;
//     _flagErr = src._flagErr;
//     _host = src._host;
//     _method = src._method;
//     _path = src._path;
//     _httpVersion = src._httpVersion;
// }

int ParseRequest::countToChar(std::string str,char ch)
{
    int i;

    i = 0;
    while (str.at(i) != ch)
        i++;
    return (i);
}

int ParseRequest::scipSpace(std::string str)
{
    int i;

    i = 0;
    while(str.at(i) == ' ')
        i++;
    return (i);
}

void ParseRequest::parseStartString()
{
    int i;

    i = 0;
	std::cout << "REEEEQ!!! " << _req << std::endl;
	while (_req.at(i) == '\r' || _req.at(i) == '\n')
		i++;
    if (_req.compare(i, 3, "GET") == 0) 
	{  
        _method = _req.substr(i, 3);
		i = i + 3;
	}
	else if (_req.compare(i, 4, "POST") == 0)
	{
        _method = _req.substr(i, 4);
		i = i + 4;
	}
	else if (_req.compare(i, 6, "DELETE") == 0)
	{
		_method = _req.substr(i, 6);
		i = i + 6;
	}
	else if (_req.compare(i, 4, "HEAD") == 0)
	{
		_method = _req.substr(i, 4);
		i = i + 4;
	}
	else if (_req.compare(i, 3, "PUT") == 0)
	{
		_method = _req.substr(i, 3);
		i = i + 3;
	}
    
	i = i + scipSpace(&_req.at(i));
    _reqPath = _req.substr(i, countToChar(&_req.at(i), ' '));
	// if (_reqPath.at(_reqPath.size() - 1) != '/')
	// 	_reqPath.append("/");
	i = i + countToChar(&_req.at(i), ' ');
	i = i + scipSpace(&_req.at(i));
    _httpVersion = _req.substr(i, countToChar(&_req.at(i), '\r'));
	i = i + countToChar(&_req.at(i), '\r');
	i = i + 2;
    _req.erase(0, i);
}

std::string ParseRequest::cutReqReturnParam(std::string &req, int count)
{
	int countToDel;
	std::string ret;
	if (count != 0)
	{
		countToDel = scipSpace(&_req.at(count));
		req.erase(0, countToDel);
		ret = _req.substr(count, _req.find("\r\n", 0) - count);
	}
	req.erase(0, req.find("\r\n", 0) + 2);
	return (ret);

}

void ParseRequest::parseHeaders()
{
    int i;
	int countToDel;

    i = 0;
	countToDel = 0;
    while(1)
    {
        if (_req.compare(0, 2, "\r\n") == 0)
            return;
        else if (_req.compare(0, 15, "Content-Length:") == 0)
			_contentLength = cutReqReturnParam(_req, 15);
        else if (_req.compare(0, 5, "Host:") == 0)
			_host = cutReqReturnParam(_req, 5);
		else if (_req.compare(0, 13, "Content-Type:") == 0)
			_contentType = cutReqReturnParam(_req, 13);
		else if (_req.compare(0, 8, "Referer:") == 0)
			_referer = cutReqReturnParam(_req, 8);
		else if (_req.compare(0, 18, "Transfer-Encoding:") == 0)
			_transferencoding = cutReqReturnParam(_req, 18);
		else if (_req.compare(0, 5, "Date:") == 0)
			_date = cutReqReturnParam(_req, 5);
        else
			cutReqReturnParam(_req, 0);
    }
}


void ParseRequest::validStartString()
{
    if (_method.empty() || (_method.compare("POST") != 0 && _method.compare("DELETE") != 0 && _method.compare("GET") != 0 && _method.compare("PUT") != 0 && _method.compare("HEAD") != 0))
    {
        std::cout << "Dont know this method\n";
        _responseCode = 405;
    }
    if (_httpVersion.empty() || _httpVersion.length() != 8 || _httpVersion.compare(0, 4, "HTTP") != 0 || _httpVersion.compare(5, 3, "1.1") != 0)
    {
        std::cout << "Bad protocol\n";
        _responseCode = 1;
    }
}

// void cutLocation(Location loca)
// {
// 	_reqPath.erase(0, loca.getUri().length());
// }

void ParseRequest::makePath(Location loca)
{
	std::string tmp;
	if (!loca.getLocRoot().empty())
	{
		tmpRoot = loca.getLocRoot();
	}
	tmp.append(tmpRoot).append(_reqPath.erase(0, loca.getUri().length()));

	

	struct stat stat_buf;
	int rc = stat(tmp.c_str(), &stat_buf);
	if (rc == -1)
	{
		std::cout << tmp << std::endl;
		_responseCode = 400;
		return;
	}
	if (_method.compare("GET") == 0 && stat_buf.st_mode & 0040000)
	{
		// _path.append(tmpRoot).append(loca.getTryFiles());
		if (tmp[tmp.length() - 1] == '/')
			tmp.erase(tmp.length() - 1);
		_path.append(tmp).append(loca.getTryFiles());
		return ;
	}
	// if (_method.compare("POST") == 0 && _reqPath.compare("/") == 0)	 //odno i toje
	// {
	// 	_path.append(tmpRoot).append("/index.html");
	// 	return ;
	// }
    _path.append(tmpRoot).append(_reqPath);
	std::cout << "paath" << _path << std::endl;
}

int ParseRequest::getStatus()
{
	return(_status);
}


std::size_t ParseRequest::getLocation(std::vector <Location> locs)
{
	
	for (size_t i = 0; i < locs.size(); i++)
	{
		if (_reqPath.find(locs.at(i).getUri()) == 0)
			return (i);
	}
	std::cout << "NE NASHEL!\n";
	return (-1);
}

bool ParseRequest::isMethodAllowed(std::string method, std::vector <std::string> methods)
{
	for (size_t i = 0; i < methods.size(); i++)
		_allowMethods.append(methods.at(i) + " ");
	_allowMethods.erase(_allowMethods.size() - 1);	
	for (size_t i = 0; i < methods.size(); i++)
	{
		if (methods.at(i).compare(method) == 0)
		{
			std::cout << methods.at(i) << std::endl;
			std::cout <<method << std::endl;
			return (true);
		}
	}
	// std::cout << "AAAAAAA\n" << method << std::endl;
	// if (method.compare("HEAD") == 0)
	// {
	// 	_responseCode = 503;
	// 	return (false);
	// }
	_responseCode = 405;
	
	_status = 4;
	return (false);
}

void ParseRequest::setStatusAndPrepareFd()
{
	std::vector <Location> locs = _server.getLocations();
	size_t ret = getLocation(locs);
	
	if (ret == -1)
	{
		_responseCode = 404;
		_status = 4;
		return ;
	}
	if (locs[ret].getRedirect() != nullptr)
	{
		std::cout << "REQPATH" << _reqPath <<std::endl;
		std::cout <<locs[ret].getUri() << std::endl;
		std::cout << "REDIRECT!\n";
		std::istringstream(locs[ret].getRedirect()[0]) >> _responseCode;
		_path = locs[ret].getRedirect()[1];
		_status = 4;
		return ;
	}
	makePath(locs[ret]);
	// chdir(tmpRoot.c_str());
	if (_method.compare("POST") == 0) // && isMethodAllowed(_method, locs[ret].getMethods()))
	{
		if (!isMethodAllowed(_method, locs[ret].getMethods()))
		{
			_responseCode = 405;
			_status = 2;
			return;
		}
		std::size_t pos;
		struct stat stat_buf;
		std::string fileName;
		int rc = stat(_path.c_str(), &stat_buf);
		if (rc == -1)
		{
			_responseCode = 400;
			_status = 2;
			return;  //vremenno
		}
		else if (stat_buf.st_mode & 0100000 || stat_buf.st_mode & 0040000)
		{
			_responseCode = 409;  //vremenno
		}
		else
		{
			pos = _path.rfind('/');
			if (pos == std::string::npos || _path.length() == 0 || _path.length() - 1 == pos)
			{
				_responseCode = 400;
				_status = 2;
				return ;
			}
			fileName = _path.substr(pos + 1);
			_fd = open(fileName.c_str(), O_RDWR | O_CREAT, 666);
			if (_fd == -1)
			{
				_responseCode = 400; //vremenno
				_status = 2;
				return ;
			}
			if (_transferencoding.compare("chunked") == 0)
				_status = 2;
			else
				_status = 3;
		}
	}
	if (_method.compare("GET") == 0 && isMethodAllowed(_method, locs[ret].getMethods()))
	{
		std::cout << "PATH     " << _path << std::endl;
		_status = 4;
	}
	if (_method.compare("HEAD") == 0 && isMethodAllowed(_method, locs[ret].getMethods()))
	{
		std::cout << "PATH     " << _path << std::endl;
		_status = 4;
	}
}

void ParseRequest::setResponseCode(int responseCode)
{
	_responseCode = responseCode;
}


std::string ParseRequest::getPath()
{
	return(_path);
}

std::string ParseRequest::getRequest()
{
    return (_req);
}

int ParseRequest::getFlagErr()
{
    return (_flagErr);
}
std::string ParseRequest::getMethod()
{
    return (_method);
}
std::string ParseRequest::getReqPath()
{
    return (_path);
}
std::string ParseRequest::getHttpVersion()
{
    return (_httpVersion);
}
std::string ParseRequest::getHost()
{
    return (_host);
}

ParseRequest::~ParseRequest()
{
}

int ParseRequest::getResponseCode()
{
	return (_responseCode);
}

std::string ParseRequest::getAllowMethods()
{
	return (_allowMethods);
}

int ParseRequest::getFd()
{
	return (_fd);
}