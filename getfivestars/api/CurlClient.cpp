#include "CurlClient.h"
#include "Json.h"

static size_t getfivestars::api::curlWriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    ((std::string*)userp)->append((char*) contents, size * nmemb);
    return size * nmemb;
}

getfivestars::api::CurlClient::CurlClient(getfivestars::api::Request *request) : getfivestars::api::Client(request) {
}

getfivestars::api::Response getfivestars::api::CurlClient::sendRequest() {
    CURL *curl = curl_easy_init();

    std::string url = getfivestars::api::Client::URL + this->request->getAction();
    this->readBuffer = "";
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, getfivestars::api::Json::paramsToJson(this->request->getParameters()).c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, getfivestars::api::curlWriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &this->readBuffer);

    curl_easy_perform(curl);
    curl_easy_cleanup(curl);

    getfivestars::api::Params params = getfivestars::api::Json::jsonToParams(this->readBuffer);
    getfivestars::api::Response response(params);
    return response;
}