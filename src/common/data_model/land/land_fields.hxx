#pragma once

#include "./land.hxx"

namespace ZG::Panel::LandInner{


class LandFields {

public:
    long          id{};
    std::string   name{};
    std::string   description{};
    std::string   reglament{};
    std::string   kadastr{};
    std::string   usage{};
    std::string   type{};
    std::string   district{};
    std::string   address{};
    double        square{};
    double        price{};
    URLField      previewURL{};
    Location      location{};

    std::vector <URLField> docURLs{};
    std::vector <URLField> photos{};
    std::vector <Location> borderLocs{};

    LandFields (
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
    );

    LandFields (const LandFields & other) = default;
    LandFields () = default;

public:

    friend void from_json ( const nlohmann::json & json, LandFields & fields );
    friend void to_json   ( nlohmann::json & json, const LandFields & fields );

};

void from_json (const nlohmann::json & json, LandFields & fields);
void to_json   ( nlohmann::json & json, const LandFields & fields );

}