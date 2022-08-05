#pragma once

#include <string>

#include <nlohmann/json.hpp>

namespace ZG::Panel::LandInner{

class DataField {
public:
    std::string name{};
    std::string extension{};
    std::string data{};
    std::string description{};
    
    DataField (
        const std::string & name,
        const std::string & extension,
        const std::string & data,
        const std::string & description
    );

    DataField (const DataField & other) = default;
    DataField () = default;

    friend void from_json ( const nlohmann::json & json, DataField & dataField );
    friend void to_json   ( nlohmann::json & json, const DataField & dataField );

};

void from_json ( const nlohmann::json & json, DataField & dataField );
void to_json   ( nlohmann::json & json, const DataField & dataField );

}