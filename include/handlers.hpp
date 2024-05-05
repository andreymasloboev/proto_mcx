// CommonRequestHandler.h
#ifndef SERVER_HANDLERS_H_
#define SERVER_HANDLERS_H_

#include <Poco/Net/HTTPRequestHandlerFactory.h>

class CommonRequestHandler : public Poco::Net::HTTPRequestHandlerFactory
{

public:
    CommonRequestHandler();

    virtual Poco::Net::HTTPRequestHandler *createRequestHandler(
        const Poco::Net::HTTPServerRequest &request);
};

#endif // SERVER_HANDLERS_H_
