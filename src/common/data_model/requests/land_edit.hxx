#pragma once

#include "../land/land.hxx"

namespace ZG::Panel 
{

class LandEditRequest {
public:
    std::string     token{};
    long            id{};
    std::string     name{};
    std::string     description{};
    std::string     reglament{};
    std::string     kadastr{};
    std::string     usage{};
    std::string     type{};
    std::string     district{};
    std::string     address{};
    double          square{};
    double          price{};
    Land::Location  location{};

    Land::DataField preview{};

    std::vector < Land::DataField > docs{};
    std::vector < Land::DataField > photos{};
    std::vector < Land::Location  > borderLocs{};

    LandEditRequest (
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
        const std::vector < Land::Location >   &  borderLocs
    );

    LandEditRequest (const LandEditRequest & other) = default;
    LandEditRequest () = default;

    friend void from_json (const nlohmann::json & json, LandEditRequest & LandEditRequest); 
    friend void to_json   (nlohmann::json & json, const LandEditRequest & LandEditRequest); 
};

    void from_json (const nlohmann::json & json, LandEditRequest & landEditRequest); 
    void to_json   (nlohmann::json & json, const LandEditRequest & LandEditRequest); 
}