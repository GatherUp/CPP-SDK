#ifndef GETFIVESTARS_API_CLIENT_H
#define GETFIVESTARS_API_CLIENT_H

#include "Request.h"
#include "Response.h"

namespace getfivestars {
    namespace api {

        class Client {
        protected:
            getfivestars::api::Request *request;
        public:
            static const std::string URL;
            Client(getfivestars::api::Request *);
            virtual getfivestars::api::Response sendRequest() = 0;
        };
    }
}

#endif