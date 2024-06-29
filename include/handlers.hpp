#pragma once

#include <memory>
#include <Poco/Net/HTTPRequestHandlerFactory.h>
#include <resource.hpp>
class CommonRequestHandler : public Poco::Net::HTTPRequestHandlerFactory
{

public:
    CommonRequestHandler() : resource_{std::make_shared<Resource>()} {}

    virtual Poco::Net::HTTPRequestHandler *createRequestHandler(const Poco::Net::HTTPServerRequest &request) override final;

private:
    std::shared_ptr<Resource> resource_;
};
