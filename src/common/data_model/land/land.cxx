#include "./land.hxx"

#include <iostream>

namespace ZG::Panel
{

Land::Land (const Land::LandFields & fields) : fields{fields} {}

void from_json (const nlohmann::json & json, Land & land)
{
    try { json.at("fields").get_to(land.fields); } catch (nlohmann::json::exception e) { std::cout << e.what() << "\n"; }
}

void to_json (nlohmann::json & json, const Land & land)
{
    json = nlohmann::json
    {
        {"fields", land.fields}
    };
}

}
