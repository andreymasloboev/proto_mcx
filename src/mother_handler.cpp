#include <iostream>

#include <Poco/Net/HTTPRequestHandler.h>
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/Net/HTTPServerRequest.h>

#include "mother_handler.hpp"


void MotherHandler::handleRequest(Poco::Net::HTTPServerRequest &req,
                                  Poco::Net::HTTPServerResponse &res)
{

    std::cout << "Mother request was called" << std::endl;

    std::ostream &reply = res.send();
    reply << "U have called Mother request" << std::endl;
    res.setStatus(Poco::Net::HTTPServerResponse::HTTP_OK);
}