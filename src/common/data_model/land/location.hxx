#pragma once

namespace ZG::Panel::LandInner{

class Location {
    private:
        const double lon;
        const double lat;
    public:
        Location (const double & lat, const double & lon);
        Location (Location && other) = delete;
        Location (const Location & other) = default;
        double getLon() const;
        double getLat() const;
};

}
