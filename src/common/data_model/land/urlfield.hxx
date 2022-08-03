#pragma once

#include <string>

#include <nlohmann/json.hpp>

namespace ZG::Panel::LandInner{

class URLField {
    
private:

    std::string name;
    std::string description;
    std::string URL;

public:
    
    URLField (
        const std::string & name,
        const std::string & description,
        const std::string & URL
    );

    URLField (const URLField & other) = default;
    URLField () = default;

    std::string getName () const;
    std::string getDescription () const;
    std::string getURL () const;

    friend void from_json (const nlohmann::json & json, URLField & urlField);

};

}