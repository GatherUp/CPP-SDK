#include "Response.h"

getfivestars::api::Response::Response(getfivestars::api::Params response) {
    if (response.count("errorCode") == 0 || response.count("errorMessage") == 0) {
        response["errorCode"] = "-1";
        response["errorMessage"] = "Unknown error";
    }

    std::stringstream ss(response["errorCode"]);
    int errorCode;
    ss >> errorCode;
    this->errorCode = errorCode;
    this->errorMessage = response["errorMessage"];

    getfivestars::api::Params::iterator it = response.find("errorCode");
    response.erase(it, response.end());
    it = response.find("errorMessage");
    response.erase(it, response.end());

    this->response = response;
}

getfivestars::api::Params getfivestars::api::Response::getResponse() {
    return this->response;
}

bool getfivestars::api::Response::getStatus() {
    return this->getErrorCode() == 0;
}

int getfivestars::api::Response::getErrorCode() {
    return this->errorCode;
}

std::string getfivestars::api::Response::getErrorMessage() {
    return this->errorMessage;
}