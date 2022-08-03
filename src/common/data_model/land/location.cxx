#include "./land.hxx"

namespace ZG::Panel {

Land::Location::Location 
(
    const double & lat, 
    const double & lon
) : lat {lat},
    lon {lon} 
{}

double Land::Location::getLon() const {return lon;}
double Land::Location::getLat() const {return lat;}

void LandInner::from_json (const nlohmann::json & json, Location & location)
{
    json.at("lon").get_to(location.lon);
    json.at("lat").get_to(location.lat);
}

}
