#include "Request.h"

getfivestars::api::Request::Request(getfivestars::api::Params request, std::string action) {
    this->request = request;
    this->action = action;
}

getfivestars::api::Request::Request(std::string action) {
    getfivestars::api::Params request;
    this->request = request;
    this->action = action;
}

void getfivestars::api::Request::set(std::string key, std::string val) {
    this->request[key] = val;
}

std::string getfivestars::api::Request::get(std::string key) {
    if (this->request.count(key) > 0) {
        return this->request[key];
    }
    return "";
}

getfivestars::api::Params getfivestars::api::Request::getParameters() {
    return this->request;
}

std::string getfivestars::api::Request::getAction() {
    return this->action;
}