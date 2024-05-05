#ifndef SERVER_MOTHERHANDLER_H_
#define SERVER_MOTHERHANDLER_H_

#include <iostream>

#include <Poco/Net/HTTPRequestHandler.h>

class MotherHandler : public Poco::Net::HTTPRequestHandler
{
public:
    virtual void handleRequest(Poco::Net::HTTPServerRequest &req,
                               Poco::Net::HTTPServerResponse &res);
};

#endif // SERVER_MOTHERHANDLER_H_