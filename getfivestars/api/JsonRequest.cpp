#include "JsonRequest.h"

getfivestars::api::JsonRequest::JsonRequest(std::string action, std::string json) : getfivestars::api::Request(action) {
    getfivestars::api::Params params = getfivestars::api::Json::jsonToParams(json);
    for (getfivestars::api::Params::iterator iterator = params.begin(); iterator != params.end(); iterator++) {
        this->set(iterator->first, iterator->second);
    }
}
