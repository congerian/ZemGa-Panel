#include "./land.hxx"

namespace ZG::Panel {

Land::URLField::URLField (
    const std::string & name,
    const std::string & description,
    const std::string & URL
) : name        {name},
    description {description},
    URL         {URL}
{}

std::string Land::URLField::getName () const {return name;}
std::string Land::URLField::getDescription () const {return description;}
std::string Land::URLField::getURL () const {return URL;}

void LandInner::from_json (const nlohmann::json & json, URLField & urlField)
{
    json.at("name").get_to(urlField.name);
    json.at("description").get_to(urlField.description);
    json.at("URL").get_to(urlField.URL);
}

}