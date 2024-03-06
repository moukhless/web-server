/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Request.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:54:29 by del-yaag          #+#    #+#             */
/*   Updated: 2024/03/05 15:54:30 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Request.hpp"

Request::Request( void ) {

    this->sendedcontent = 0;
}

Request::~Request( void ) { }

int Request::getsendedcontent( void ) const {

    return this->sendedcontent;
}

void Request::setsendedcontent( int const &sendedcontent ) {

    this->sendedcontent = sendedcontent;
}

void Request::setRecString( std::string recString ) {

    this->recString += recString;
}
std::string Request::getRecString( void ) {

    return (this->recString);
}

void Request::setMethod( std::string method ) {

    this->method = method;
}
std::string Request::getMethod( void ) {

    return (this->method);
}

void Request::setPath( std::string path ) {

    this->path = path;
}
std::string Request::getPath( void ) {

    return (this->path);
}

std::string Request::getHeader( void ) {

    return (this->header);
}
void Request::setHeader( std::string header ) {

    this->header = header;
}

std::string Request::getBody( void ) {

    return (this->body);
}
void Request::setBody( std::string body ) {

    this->body = body;
}

std::string Request::getConnection( void ) {

    return (this->connection);
}
void Request::setConnection( std::string connection ) {

    this->connection = connection;
}

int Request::getRequestBodySize( void ) {

    std::string subString = "\r\n\r\n";

    size_t found = recString.find(subString);
    if (found != std::string::npos) {
        return (recString.length() - (found + subString.length()));
    }
    else
        return (0);
}

void Request::parseRequest( void ) {

}

int Request::setRequestHeader( void ) {

    std::string subString = "\r\n\r\n";

    size_t found = recString.find(subString);
    if (found != std::string::npos) {
        this->header = recString.substr(0, found + subString.length());
        // std::cout << "header request: " << this->header << std::endl;
        return (1);
    }
    else
        return (0);
}

void Request::parseRequestHeader( void ) {

    std::string requestLine;
	std::istringstream recbuffStream(recString);

    /*   get server   */

    //get request line "GET / HTTP/1.1"
	std::getline(recbuffStream, requestLine);


    //parse request line
	std::istringstream methodStream(requestLine);
	std::getline(methodStream, method, ' ');
	std::getline(methodStream, path, ' ');
	path.erase(0, 1);
}

std::string Request::getValue( std::string key ) {

    std::string line;
    std::istringstream recbuffStream(recString);

    while (std::getline(recbuffStream, line))
    {
        std::string part;
        std::istringstream lineStream(line);
        std::getline(lineStream, part, ' ');
        if (part == key) {
            std::getline(lineStream, part);
            return (part);
        }
    }
    return ("");
}