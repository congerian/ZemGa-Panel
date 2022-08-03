#pragma once

#include <string>
#include <vector>

#include <nlohmann/json.hpp>

#include "./location.hxx"
#include "./urlfield.hxx"
#include "./landfields.hxx"

namespace ZG::Panel {

class Land {

public:

    using Location = ZG::Panel::LandInner::Location;
    using URLField = ZG::Panel::LandInner::URLField;
    using LandFields = ZG::Panel::LandInner::LandFields;

    Land (const LandFields & fields);
    Land (const Land & other) = default;
    Land () = default;

    LandFields getFields() const;
        
private:

    LandFields fields;

public:

    friend void from_json (const nlohmann::json & json, Land & land);
    
};


}