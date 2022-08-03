#include "./land.hxx"

namespace ZG::Panel {

Land::LandFields::LandFields (
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
) : 
    id          {id},
    name        {name},
    description {description},
    reglament   {reglament},
    kadastr     {kadastr},
    usage       {usage},
    type        {type},
    district    {district},
    address     {address},
    square      {square},
    price       {price},
    previewURL  {previewURL},
    docURLs     {docURLs},
    photos      {photos},
    borderLocs  {borderLocs}
{}

long            Land::LandFields::getId () const {return id;}
std::string     Land::LandFields::getName () const {return name;}
std::string     Land::LandFields::getDescription () const {return description;}
std::string     Land::LandFields::getReglament () const {return reglament;}
std::string     Land::LandFields::getKadastr () const {return kadastr;}
std::string     Land::LandFields::getUsage () const {return usage;}
std::string     Land::LandFields::getType () const {return type;}
std::string     Land::LandFields::getDistrict () const {return district;}
std::string     Land::LandFields::getAddress () const {return address;}
double          Land::LandFields::getSquare () const {return square;}
double          Land::LandFields::getPrice () const {return price;}
Land::URLField  Land::LandFields::getPreviewURL () const {return previewURL;}

const std::vector <Land::URLField> Land::LandFields::getDocURLs () const {return docURLs;}
const std::vector <Land::URLField> Land::LandFields::getPhotos () const {return photos;}
const std::vector <Land::Location> Land::LandFields::getBorderLocs () const {return borderLocs;}

void LandInner::from_json (const nlohmann::json & json, LandInner::LandFields & fields)
{
    json.at("id").get_to(fields.id);
    json.at("name").get_to(fields.name);
    json.at("description").get_to(fields.description);
    json.at("reglament").get_to(fields.reglament);
    json.at("kadastr").get_to(fields.kadastr);
    json.at("usage").get_to(fields.usage);
    json.at("type").get_to(fields.type);
    json.at("district").get_to(fields.district);
    json.at("address").get_to(fields.address);
    json.at("square").get_to(fields.square);
    json.at("price").get_to(fields.price);
    json.at("previewURL").get_to(fields.previewURL);
}
}


