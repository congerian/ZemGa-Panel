#include "./contact.hxx"

#include <nlohmann/json.hpp>
#include <iostream>

namespace ZG::Panel {

Contact::Contact 
(
    const Client & client
) : client { client }
{}

void from_json (const nlohmann::json & json, Contact & contact)
{
    try { json.at("client").get_to(contact.client); } catch ( nlohmann::json::exception e ) { std::cout << e.what() << "\n"; }
}

void to_json   ( nlohmann::json & json, const Contact & contact )
{
    json = nlohmann::json {{"client", contact.client}};
}

}