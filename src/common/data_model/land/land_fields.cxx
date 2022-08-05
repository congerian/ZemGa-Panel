#include "./land.hxx"

#include <iostream>

namespace ZG::Panel {

Land::LandFields::LandFields (
    const long         &  id,
    const std::string  &  name,
    const std::string  &  description,
    const std::string  &  reglament,
    const std::string  &  kadastr,
    const std::string  &  usage,
    const std::string  &  type,
    const std::string  &  district,
    const std::string  &  address,
    const double       &  square,
    const double       &  price,
    const URLField     &  previewURL,
    const Location     &  location,
    const std::vector <URLField>  &  docURLs,
    const std::vector <URLField>  &  photos,
    const std::vector <Location>  &  borderLocs
) : 
    id          {id},
    name        {name},
    description {description},
    reglament   {reglament},
    kadastr     {kadastr},
    usage       {usage},
    type        {type},
    district    {district},
    address     {address},
    square      {square},
    price       {price},
    previewURL  {previewURL},
    location    {location},
    docURLs     {docURLs},
    photos      {photos},
    borderLocs  {borderLocs}
{}

void LandInner::from_json (const nlohmann::json & json, LandInner::LandFields & fields)
{
    try { json.at("id").get_to(fields.id); } catch (nlohmann::json::exception e) { std::cout << e.what() << "\n"; }
    try { json.at("name").get_to(fields.name); } catch (nlohmann::json::exception e) { std::cout << e.what() << "\n"; }
    try { json.at("description").get_to(fields.description); } catch (nlohmann::json::exception e) { std::cout << e.what() << "\n"; }
    try { json.at("reglament").get_to(fields.reglament); } catch (nlohmann::json::exception e) { std::cout << e.what() << "\n"; }
    try { json.at("kadastr").get_to(fields.kadastr); } catch (nlohmann::json::exception e) { std::cout << e.what() << "\n"; }
    try { json.at("usage").get_to(fields.usage); } catch (nlohmann::json::exception e) { std::cout << e.what() << "\n"; }
    try { json.at("type").get_to(fields.type); } catch (nlohmann::json::exception e) { std::cout << e.what() << "\n"; }
    try { json.at("district").get_to(fields.district); } catch (nlohmann::json::exception e) { std::cout << e.what() << "\n"; }
    try { json.at("address").get_to(fields.address); } catch (nlohmann::json::exception e) { std::cout << e.what() << "\n"; }
    try { json.at("square").get_to(fields.square); } catch (nlohmann::json::exception e) { std::cout << e.what() << "\n"; }
    try { json.at("price").get_to(fields.price); } catch (nlohmann::json::exception e) { std::cout << e.what() << "\n"; }
    try { json.at("previewURL").get_to(fields.previewURL); } catch (nlohmann::json::exception e) { std::cout << e.what() << "\n"; }
    try { json.at("location").get_to(fields.location); } catch (nlohmann::json::exception e) { std::cout << e.what() << "\n"; }
    try { json.at("docURLs").get_to(fields.docURLs); } catch (nlohmann::json::exception e) { std::cout << e.what() << "\n"; }
    try { json.at("photos").get_to(fields.photos); } catch (nlohmann::json::exception e) { std::cout << e.what() << "\n"; }
    try { json.at("borderLocs").get_to(fields.borderLocs); } catch (nlohmann::json::exception e) { std::cout << e.what() << "\n"; }
}

void LandInner::to_json (nlohmann::json & json, const LandInner::LandFields & fields)
{
    json = nlohmann::json
    {
        {"id", fields.id},
        {"name", fields.name},
        {"description", fields.description},
        {"reglament", fields.reglament},
        {"kadastr", fields.kadastr},
        {"usage", fields.usage},
        {"type", fields.type},
        {"district", fields.district},
        {"address", fields.address},
        {"square", fields.square},
        {"price", fields.price},
        {"previewURL", fields.previewURL},
        {"location", fields.location},
        {"docURLs", fields.docURLs},
        {"photos", fields.photos},
        {"borderLocs", fields.borderLocs}
    };
}

}


