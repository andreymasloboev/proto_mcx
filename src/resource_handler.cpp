#include <Poco/Format.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/Net/MediaType.h>

#include "resource_handler.hpp"

using Poco::format;

void ResourceHandler::handleRequest(Poco::Net::HTTPServerRequest &request, Poco::Net::HTTPServerResponse &response)
{
    if (request.getMethod() == Poco::Net::HTTPRequest::HTTP_GET)
    {
        std::string resp_json{};
        format(resp_json, "{\"status\": \"%s\"}", resource_->getStatus());

        response.setContentType(Poco::Net::MediaType{"application/json"});
        response.setStatus(Poco::Net::HTTPServerResponse::HTTP_OK);
        response.send() << resp_json;
        return;
    }

    if (request.getMethod() == Poco::Net::HTTPRequest::HTTP_POST)
    {
        resource_->setStatus(1);
        response.setStatus(Poco::Net::HTTPServerResponse::HTTP_OK);
        response.send();
        return;
    }

    response.setStatus(Poco::Net::HTTPServerResponse::HTTP_BAD_REQUEST);
    response.send();
}
