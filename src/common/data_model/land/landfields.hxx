#pragma once

#include "./land.hxx"

namespace ZG::Panel::LandInner{

class LandFields {
private:
    const long          id;
    const std::string   name;
    const std::string   description;
    const std::string   reglament;
    const std::string   kadastr;
    const std::string   usage;
    const std::string   type;
    const std::string   district;
    const std::string   address;
    const double        square;
    const double        price;
    const URLField      previewURL;

    const std::vector <URLField> docURLs;
    const std::vector <URLField> photos;
    const std::vector <Location> borderLocs;
public:
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
        const std::vector <URLField>  &  docURLs,
        const std::vector <URLField>  &  photos,
        const std::vector <Location>  &  borderLocs
    );

    LandFields (LandFields && other) = delete;
    LandFields (const LandFields & other) = default;

    long          getId () const;
    std::string   getName () const;
    std::string   getDescription () const;
    std::string   getReglament () const;
    std::string   getKadastr () const;
    std::string   getUsage () const;
    std::string   getType () const;
    std::string   getDistrict () const;
    std::string   getAddress () const;
    double        getSquare () const;
    double        getPrice () const;
    URLField      getPreviewURL () const;

    const std::vector <URLField> getDocURLs () const;
    const std::vector <URLField> getPhotos () const;
    const std::vector <Location> getBorderLocs () const;
};

}
