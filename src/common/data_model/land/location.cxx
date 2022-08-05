#include "./land.hxx"

#include <iostream>

namespace ZG::Panel {

Land::Location::Location 
(
    const double & lat, 
    const double & lon
) : lat {lat},
    lon {lon} 
{}

void LandInner::from_json (const nlohmann::json & json, Location & location)
{
    try { json.at("lon").get_to(location.lon); } catch (nlohmann::json::exception e) { std::cout << e.what() << "\n"; }
    try { json.at("lat").get_to(location.lat); } catch (nlohmann::json::exception e) { std::cout << e.what() << "\n"; }
}

void LandInner::to_json (nlohmann::json & json, const Location & location)
{
    json = nlohmann::json
    {
        {"lat", location.lat},
        {"lon", location.lon}
    };
}

}
