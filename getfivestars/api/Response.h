#ifndef GETFIVESTARS_API_RESPONSE_H
#define GETFIVESTARS_API_RESPONSE_H

#include <string>
#include <sstream>
#include "Response.h"
#include "Request.h"

namespace getfivestars {
    namespace api {

        class Response {
        protected:
            getfivestars::api::Params response;
            int errorCode;
            std::string errorMessage;
        public:
            Response(getfivestars::api::Params);
            getfivestars::api::Params getResponse();
            bool getStatus();
            int getErrorCode();
            std::string getErrorMessage();
        };
    }
}

#endif