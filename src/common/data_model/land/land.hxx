#pragma once

#include <string>
#include <vector>

#include <nlohmann/json.hpp>

#include "./location.hxx"
#include "./url_field.hxx"
#include "./land_fields.hxx"
#include "./data_field.hxx"

namespace ZG::Panel {

class Land {

public:

    using Location      = ZG::Panel::LandInner::Location;
    using URLField      = ZG::Panel::LandInner::URLField;
    using LandFields    = ZG::Panel::LandInner::LandFields;
    using DataField     = ZG::Panel::LandInner::DataField;

    Land (const LandFields & fields);
    Land (const Land & other) = default;
    Land () = default;

    LandFields fields{};
        
private:


public:

    friend void from_json (const nlohmann::json & json, Land & land);
    friend void to_json   (nlohmann::json & json, const Land & land);
    
};

void from_json (const nlohmann::json & json, Land & land);
void to_json   (nlohmann::json & json, const Land & land);

}