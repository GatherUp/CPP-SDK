#ifndef GETFIVESTARS_API_CURL_CLIENT_H
#define GETFIVESTARS_API_CURL_CLIENT_H

#include "Client.h"
#include <string>
#include <curl/curl.h>

namespace getfivestars {
    namespace api {
        static size_t curlWriteCallback(void *, size_t, size_t, void *);

        class CurlClient : public getfivestars::api::Client {
        private:
            std::string readBuffer;
        public:
            CurlClient(getfivestars::api::Request *);
            getfivestars::api::Response sendRequest();
        };
    }
}

#endif