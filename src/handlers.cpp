#include <Poco/Net/HTTPServerRequest.h>

#include <resource_handler.hpp>
#include <handlers.hpp>

Poco::Net::HTTPRequestHandler *CommonRequestHandler::createRequestHandler(const Poco::Net::HTTPServerRequest &request)
{
    if (request.getURI() == "/status")
    {
        return new ResourceHandler(resource_);
    }

    return nullptr;
}