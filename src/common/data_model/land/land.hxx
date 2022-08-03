#pragma once

#include <string>
#include <vector>

#include "./location.hxx"
#include "./urlfield.hxx"
#include "./landfields.hxx"

namespace ZG::Panel {

class Land {

public:
    using Location = ZG::Panel::LandInner::Location;
    using URLField = ZG::Panel::LandInner::URLField;
    using LandFields = ZG::Panel::LandInner::LandFields;

    Land(LandFields && fields);
    Land(const LandFields & fields);
    Land(Land&& other) = default;
    Land(const Land & other) = default;

    LandFields getFields() const;
        
private:
    const LandFields fields;


};

}