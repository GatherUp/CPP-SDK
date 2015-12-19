#include "AuthToken.h"

getfivestars::api::AuthToken::AuthToken(std::string clientId, std::string privateKey) {
    this->clientId = clientId;
    this->privateKey = privateKey;
}

void getfivestars::api::AuthToken::signRequest(Request *request) {
    request->set("clientId", this->clientId);
    std::string token = "";

    getfivestars::api::Params params = request->getParameters();
    for (getfivestars::api::Params::iterator iterator = params.begin(); iterator != params.end(); iterator++) {
        token += iterator->first + iterator->second;
    }

    request->set("hash", this->sha256(privateKey + token));
}

// http://stackoverflow.com/questions/2262386/generate-sha256-with-openssl-and-c#answer-2458382
std::string getfivestars::api::AuthToken::sha256(const std::string str) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str.c_str(), str.size());
    SHA256_Final(hash, &sha256);
    std::stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int) hash[i];
    }
    return ss.str();
}