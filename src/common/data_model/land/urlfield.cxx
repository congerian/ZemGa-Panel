#include "./land.hxx"

namespace ZG::Panel {

Land::URLField::URLField (
    const std::string & name,
    const std::string & desription,
    const std::string & URL
) : name        {name},
    description {description},
    URL         {URL}
{}

std::string Land::URLField::getName () const {return name;}
std::string Land::URLField::getDescription () const {return description;}
std::string Land::URLField::getURL () const {return URL;}

}