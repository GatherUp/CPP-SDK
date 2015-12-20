#ifndef GETFIVESTARS_API_REQUEST_H
#define GETFIVESTARS_API_REQUEST_H

#include <string>
#include <map>

namespace getfivestars {
    namespace api {
        typedef std::map<std::string, std::string> Params;

        class Request {
        protected:
            std::map<std::string, std::string> request;
            std::string action;
        public:
            Request(std::string);
            Request(std::string, getfivestars::api::Params);
            void set(std::string, std::string);
            std::string get(std::string);
            std::map<std::string, std::string> getParameters();
            std::string getAction();
        };
    }
}

#endif
