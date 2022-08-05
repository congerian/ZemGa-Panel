#pragma once

#include <string>

#include <nlohmann/json.hpp>

namespace ZG::Panel::LandInner{


class URLField {
public:
    std::string name{};
    std::string description{};
    std::string URL{};
    
    URLField (
        const std::string & name,
        const std::string & description,
        const std::string & URL
    );

    URLField (const URLField & other) = default;
    URLField () = default;

    friend void from_json (const nlohmann::json & json, URLField & urlField);
    friend void to_json   (nlohmann::json & json, const URLField & urlField);

};

void from_json (const nlohmann::json & json, URLField & urlField);
void to_json   (nlohmann::json & json, const URLField & urlField);

}