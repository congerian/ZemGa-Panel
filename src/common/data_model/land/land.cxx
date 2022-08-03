#include "./land.hxx"

namespace ZG::Panel
{

Land::Land (const Land::LandFields & fields) : fields{fields} {}
Land::LandFields Land::getFields () const {return fields;}

void from_json (const nlohmann::json & json, Land & land)
{
    json.at("fields").get_to(land.fields);
}

}
