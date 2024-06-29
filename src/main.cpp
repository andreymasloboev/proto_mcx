#include <Poco/Util/ServerApplication.h>
#include <Poco/Util/ServerApplication.h>
#include <Poco/Net/HTTPServer.h>

#include <handlers.hpp>

class Listener : public Poco::Util::ServerApplication
{
    virtual int main(const std::vector<std::string> &args)
    {
        Poco::Net::HTTPServerParams *params = new Poco::Net::HTTPServerParams();
        params->setMaxQueued(50);
        params->setMaxThreads(4);

        Poco::Net::ServerSocket socket(9001);

        Poco::Net::HTTPServer server(new CommonRequestHandler(), socket, params);

        server.start();
        waitForTerminationRequest();
        server.stop();

        return 0;
    }
};

POCO_SERVER_MAIN(Listener)