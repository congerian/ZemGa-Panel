#pragma once

namespace ZG::Panel::LandInner{


class Location {
public:
    double lon{};
    double lat{};

    Location (const double & lat, const double & lon);
    Location (const Location & other) = default;
    Location () = default;

public:

    friend void from_json (const nlohmann::json & json, Location & location);
    friend void to_json   (nlohmann::json & json, const Location & location);

};

void from_json (const nlohmann::json & json, Location & location);
void to_json   (nlohmann::json & json, const Location & location);

}
