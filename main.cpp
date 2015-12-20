#include "getfivestars/api/JsonRequest.h"
#include "getfivestars/api/AuthToken.h"
#include "getfivestars/api/CurlClient.h"
#include "getfivestars/api/Json.h"
#include <iostream>

using namespace std;
using namespace getfivestars;
using namespace getfivestars::api;

int main() {
    JsonRequest request("/business/create", "{'param1':'value1', 'param2':'value2'}");
    AuthToken auth_token("324234", "5325325");

    auth_token.signRequest(&request);

    CurlClient client(&request);
    Response response = client.sendRequest();

    if (response.getStatus()) {
        Params params = response.getResponse();
        for (Params::iterator iterator = params.begin(); iterator != params.end(); iterator++) {
            cout << iterator->first << " " << iterator->second << "\n";
        }
    } else {
        cout << response.getErrorCode() << " " << response.getErrorMessage() << "\n";
    }

    return 0;
}