#ifndef GETFIVESTARS_API_RESPONSE_H
#define GETFIVESTARS_API_RESPONSE_H

#include "Response.h"
#include "Request.h"

namespace getfivestars {
    namespace api {

        class Response {
        protected:
            getfivestars::api::Params response;
        public:
            Response(getfivestars::api::Params);
            getfivestars::api::Params getResponse();
        };
    }
}

#endif