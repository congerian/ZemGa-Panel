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

}