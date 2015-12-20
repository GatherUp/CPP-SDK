#ifndef GETFIVESTARS_API_JSON_REQUEST_H
#define GETFIVESTARS_API_JSON_REQUEST_H

#include <string>
#include <json/json.h>
#include "Request.h"
#include "Json.h"

namespace getfivestars {
    namespace api {

        class JsonRequest : public getfivestars::api::Request {
        public:
            JsonRequest(std::string, std::string);
        };
    }
}

#endif
