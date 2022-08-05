#include "./land.hxx"

#include <nlohmann/json.hpp>
#include <iostream>

namespace ZG::Panel {

Land::DataField::DataField (
    const std::string & name,
    const std::string & extension,
    const std::string & data,
    const std::string & description
) : name        {name},
    extension   {extension},
    data        {data},
    description {description}
{}

void LandInner::from_json (const nlohmann::json & json, DataField & dataField)
{
    try { json.at("name").get_to(dataField.name); } catch (nlohmann::json::exception e) { std::cout << e.what() << "\n"; }
    try { json.at("extension").get_to(dataField.extension); } catch (nlohmann::json::exception e) { std::cout << e.what() << "\n"; }
    try { json.at("data").get_to(dataField.data); } catch (nlohmann::json::exception e) { std::cout << e.what() << "\n"; }
    try { json.at("description").get_to(dataField.description); } catch (nlohmann::json::exception e) { std::cout << e.what() << "\n"; }
}

void LandInner::to_json   ( nlohmann::json & json, const DataField & dataField )
{
    json = nlohmann::json 
    {
        {"name",        dataField.name},
        {"extension",   dataField.extension},
        {"data",        dataField.data},
        {"description", dataField.description}
    };
}

}