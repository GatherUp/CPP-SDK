#ifndef GETFIVESTARS_API_JSON_H
#define GETFIVESTARS_API_JSON_H

#include <json/json.h>
#include <string>
#include "Request.h"

namespace getfivestars {
    namespace api {

        class Json {
        public:
            static std::string paramsToJson(getfivestars::api::Params);
            static getfivestars::api::Params jsonToParams(std::string);
        };
    }
}

#endif
