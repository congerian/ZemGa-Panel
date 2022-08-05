#include "./contact.hxx"

#include <nlohmann/json.hpp>
#include <iostream>

namespace ZG::Panel {

Contact::Client::Client 
(
    const long & id,
    std::string & landId,
    std::string & message,
    std::string & phoneNumber,
    std::string & name,
    std::string & requestTime
) : id { id },
    landId { landId },
    message { message },
    phoneNumber { phoneNumber },
    name { name },
    requestTime { requestTime }
{}

void ContactInner::from_json (const nlohmann::json & json, Contact::Client & contact)
{
    try { json.at("id").get_to(contact.id); } catch ( nlohmann::json::exception e ) { std::cout << e.what() << "\n"; }
    try { json.at("land_id").get_to(contact.landId); } catch ( nlohmann::json::exception e ) { std::cout << e.what() << "\n"; }
    try { json.at("message").get_to(contact.message); } catch ( nlohmann::json::exception e ) { std::cout << e.what() << "\n"; }
    try { json.at("phone_number").get_to(contact.phoneNumber); } catch ( nlohmann::json::exception e ) { std::cout << e.what() << "\n"; }
    try { json.at("name").get_to(contact.name); } catch ( nlohmann::json::exception e ) { std::cout << e.what() << "\n"; }
    try { json.at("request_time").get_to(contact.requestTime); } catch ( nlohmann::json::exception e ) { std::cout << e.what() << "\n"; }
}

void ContactInner::to_json   ( nlohmann::json & json, const Contact::Client & contact )
{
    json = nlohmann::json 
    {
        {"id", contact.id},
        {"land_id", contact.landId},
        {"message", contact.message},
        {"phone_number", contact.phoneNumber},
        {"name", contact.name},
        {"request_time", contact.requestTime}
    };
}

}