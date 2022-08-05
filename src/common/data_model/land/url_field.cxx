#include "./land.hxx"

#include <iostream>

namespace ZG::Panel {

Land::URLField::URLField (
    const std::string & name,
    const std::string & description,
    const std::string & URL
) : name        {name},
    description {description},
    URL         {URL}
{}

void LandInner::from_json (const nlohmann::json & json, URLField & urlField)
{
    try { json.at("name").get_to(urlField.name); } catch (nlohmann::json::exception e) { std::cout << e.what() << "\n"; } 
    try { json.at("description").get_to(urlField.description); } catch (nlohmann::json::exception e) { std::cout << e.what() << "\n"; } 
    try { json.at("URL").get_to(urlField.URL); } catch (nlohmann::json::exception e) { std::cout << e.what() << "\n"; } 
}

void LandInner::to_json (nlohmann::json & json, const URLField & urlField)
{
    json = nlohmann::json
    {
        {"name",        urlField.name},
        {"description", urlField.description},
        {"URL",         urlField.URL}
    };
}

}