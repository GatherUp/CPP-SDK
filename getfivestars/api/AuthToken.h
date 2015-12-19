#ifndef GETFIVESTARS_API_AUTH_TOKEN_H
#define GETFIVESTARS_API_AUTH_TOKEN_H

#include <string>
#include <iomanip>
#include <sstream>
#include <openssl/sha.h>
#include "Request.h"

namespace getfivestars {
    namespace api {

        class AuthToken {
        private:
            std::string sha256(std::string str);
        protected:
            std::string clientId;
            std::string privateKey;
        public:
            AuthToken(std::string, std::string);
            void signRequest(getfivestars::api::Request *);
        };
    }
}

#endif