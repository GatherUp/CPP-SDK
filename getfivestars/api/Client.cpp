#include "Client.h"

const std::string getfivestars::api::Client::URL = "https://getfivestars.com/api";

getfivestars::api::Client::Client(getfivestars::api::Request *request) {
    this->request = request;
}