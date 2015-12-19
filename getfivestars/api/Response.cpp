#include "Response.h"

getfivestars::api::Response::Response(getfivestars::api::Params response) {
    this->response = response;
}

getfivestars::api::Params getfivestars::api::Response::getResponse() {
    return this->response;
}