#pragma once

#include <string>

#include <nlohmann/json.hpp>

namespace ZG::Panel::ContactInner
{

class Client {
public:    
    long id {};
    std::string landId {};
    std::string message {};
    std::string phoneNumber {};
    std::string name {};
    std::string requestTime {};

    Client 
    (
        const long & id,
        std::string & landId,
        std::string & message,
        std::string & phoneNumber,
        std::string & name,
        std::string & requestTime
    );

    Client (const Client & other) = default;
    Client () = default;

    friend void from_json ( const nlohmann::json & json, Client & dataField );
    friend void to_json   ( nlohmann::json & json, const Client & dataField );

};

void from_json ( const nlohmann::json & json, Client & dataField );
void to_json   ( nlohmann::json & json, const Client & dataField );

}