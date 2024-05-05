#include <iostream>

#include <Poco/Net/HTTPRequestHandler.h>
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTMLForm.h>

#include "mother_handler.hpp"


void MotherHandler::handleRequest(Poco::Net::HTTPServerRequest &req,
                                  Poco::Net::HTTPServerResponse &res)
{
    Poco::Net::HTMLForm form(req);
    std::ostream &reply = res.send();
    /*
    if (form.has("presented-param")) {
       reply << "presented param is " << form.get("presented-param") << std::endl;
       // Also works well
       // reply << "presented param is " << form["presented-param"] << std::endl;
    }

    reply << "dummy param is "
       << form.get("dummy-param", "default Dummy Param")
       << std::endl;

    reply << "***************** All parametrs ****************" << std::endl;

    for (auto i : form) {
       reply << i.first << "\tis\t" << i.second << std::endl;
    }
    */
    res.setStatus(Poco::Net::HTTPServerResponse::HTTP_OK);
}
