#pragma once

#include "./client.hxx"

#include <string>

#include <nlohmann/json.hpp>

namespace ZG::Panel{

class Contact {
public:    
    using Client = ContactInner::Client;

    Client client {};

    Contact (
        const Client & client
    );

    Contact (const Contact & other) = default;
    Contact () = default;

    friend void from_json ( const nlohmann::json & json, Contact & dataField );
    friend void to_json   ( nlohmann::json & json, const Contact & dataField );

};

void from_json ( const nlohmann::json & json, Contact & dataField );
void to_json   ( nlohmann::json & json, const Contact & dataField );

}