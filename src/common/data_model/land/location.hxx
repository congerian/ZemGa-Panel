#pragma once

namespace ZG::Panel::LandInner{

class Location {
    
private:

    double lon;
    double lat;

public:

    Location (const double & lat, const double & lon);
    Location (const Location & other) = default;
    Location () = default;
    double getLon() const;
    double getLat() const;

public:

    friend void from_json (const nlohmann::json & json, Location & location);

};

}
