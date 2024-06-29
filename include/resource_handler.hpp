#pragma once

#include <Poco/Net/HTTPRequestHandler.h>
#include <memory>
#include <resource.hpp>

class ResourceHandler : public Poco::Net::HTTPRequestHandler
{
public:
    ResourceHandler(std::shared_ptr<Resource> res) : resource_{res} {}

    void handleRequest(Poco::Net::HTTPServerRequest &req, Poco::Net::HTTPServerResponse &res) override final;

private:
    std::shared_ptr<Resource> resource_{};
};
