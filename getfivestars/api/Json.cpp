#include "Json.h"

std::string getfivestars::api::Json::paramsToJson(getfivestars::api::Params params) {
    json_object *jobj = json_object_new_object();

    for (getfivestars::api::Params::iterator iterator = params.begin(); iterator != params.end(); iterator++) {
        json_object *jstring = json_object_new_string(iterator->second.c_str());
        json_object_object_add(jobj, iterator->first.c_str(), jstring);
    }

    return json_object_to_json_string(jobj);
}

getfivestars::api::Params getfivestars::api::Json::jsonToParams(std::string json) {
    getfivestars::api::Params params;

    json_object *jobj = json_tokener_parse(json.c_str());

    json_object_object_foreach(jobj, key, val) {
        params[std::string(key)] = json_object_get_string(val);
    }

    return params;
}