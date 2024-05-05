#include <Poco/Net/HTTPServerRequest.h>

#include <mother_handler.hpp>
#include <handlers.hpp>

CommonRequestHandler::CommonRequestHandler()
{
}

Poco::Net::HTTPRequestHandler *CommonRequestHandler::createRequestHandler(
    const Poco::Net::HTTPServerRequest &request)
{
    if (request.getURI() == "/mother/")
    {
        return new MotherHandler();
    }
    return nullptr; // Does everybody use C++11?
}