#include "./land_edit.hxx"

#include <iostream>

namespace ZG::Panel 
{

LandEditRequest::LandEditRequest (
    const std::string  &  token,
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
    const Land::DataField & preview,
    const Land::Location  &  location,
    const std::vector < Land::DataField >  &  docs,
    const std::vector < Land::DataField >  &  photos,
    const std::vector < Land::Location >  &  borderLocs
) : token       {token},
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
    preview     {preview},
    docs        {docs},
    photos      {photos},
    borderLocs  {borderLocs},
    location    {location}
{

}

void from_json (const nlohmann::json & json, LandEditRequest & landEditRequest)
{
    try { json.at("token").get_to(landEditRequest.token); } catch (nlohmann::json::exception e) { std::cout << e.what() << "\n"; }
    try { json.at("id").get_to(landEditRequest.id); } catch (nlohmann::json::exception e) { std::cout << e.what() << "\n"; }
    try { json.at("name").get_to(landEditRequest.name); } catch (nlohmann::json::exception e) { std::cout << e.what() << "\n"; }
    try { json.at("description").get_to(landEditRequest.description); } catch (nlohmann::json::exception e) { std::cout << e.what() << "\n"; }
    try { json.at("reglament").get_to(landEditRequest.reglament); } catch (nlohmann::json::exception e) { std::cout << e.what() << "\n"; }
    try { json.at("kadastr").get_to(landEditRequest.kadastr); } catch (nlohmann::json::exception e) { std::cout << e.what() << "\n"; }
    try { json.at("usage").get_to(landEditRequest.usage); } catch (nlohmann::json::exception e) { std::cout << e.what() << "\n"; }
    try { json.at("type").get_to(landEditRequest.type); } catch (nlohmann::json::exception e) { std::cout << e.what() << "\n"; }
    try { json.at("district").get_to(landEditRequest.district); } catch (nlohmann::json::exception e) { std::cout << e.what() << "\n"; }
    try { json.at("address").get_to(landEditRequest.address); } catch (nlohmann::json::exception e) { std::cout << e.what() << "\n"; }
    try { json.at("square").get_to(landEditRequest.square); } catch (nlohmann::json::exception e) { std::cout << e.what() << "\n"; }
    try { json.at("price").get_to(landEditRequest.price); } catch (nlohmann::json::exception e) { std::cout << e.what() << "\n"; }
    try { json.at("preview").get_to(landEditRequest.preview); } catch (nlohmann::json::exception e) { std::cout << e.what() << "\n"; }
    try { json.at("docs").get_to(landEditRequest.docs); } catch (nlohmann::json::exception e) { std::cout << e.what() << "\n"; }
    try { json.at("photos").get_to(landEditRequest.photos); } catch (nlohmann::json::exception e) { std::cout << e.what() << "\n"; }
    try { json.at("borderLocs").get_to(landEditRequest.borderLocs); } catch (nlohmann::json::exception e) { std::cout << e.what() << "\n"; }
    try { json.at("location").get_to(landEditRequest.location); } catch (nlohmann::json::exception e) { std::cout << e.what() << "\n"; }
}

void to_json (nlohmann::json & json, const LandEditRequest & landEditRequest)
{
    json = nlohmann::json
    {
        {"token", landEditRequest.token},
        {"id", landEditRequest.id},
        {"name", landEditRequest.name},
        {"description", landEditRequest.description},
        {"reglament", landEditRequest.reglament},
        {"kadastr", landEditRequest.kadastr},
        {"usage", landEditRequest.usage},
        {"type", landEditRequest.type},
        {"district", landEditRequest.district},
        {"address", landEditRequest.address},
        {"square", landEditRequest.square},
        {"price", landEditRequest.price},
        {"preview", landEditRequest.preview},
        {"docs", landEditRequest.docs},
        {"photos", landEditRequest.photos},
        {"borderLocs", landEditRequest.borderLocs},
        {"location", landEditRequest.location}
    };
}

}