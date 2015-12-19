#include "getfivestars/api/Request.h"
#include "getfivestars/api/AuthToken.h"
#include "getfivestars/api/CurlClient.h"
#include <iostream>

int main() {
    getfivestars::api::Request request("/business/create");
    getfivestars::api::AuthToken auth_token("324234", "5325325");

    request.set("param1", "val1");
    request.set("param2", "val2");

    auth_token.signRequest(&request);

    getfivestars::api::CurlClient client(&request);
    getfivestars::api::Response response = client.sendRequest();
    
    getfivestars::api::Params params = response.getResponse();
    
    for (getfivestars::api::Params::iterator iterator = params.begin(); iterator != params.end(); iterator++) {
        std::cout << iterator->first << " " << iterator->second << "\n";
    }

    return 0;
}