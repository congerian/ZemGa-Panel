#include "./land.hxx"

namespace ZG::Panel
{
    Land::Land (const Land::LandFields & fields) : fields{fields} {}
    Land::Land (Land::LandFields && fields) : fields{fields} {}
    Land::LandFields Land::getFields () const {return fields;}
}
