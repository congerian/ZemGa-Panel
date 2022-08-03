#pragma once

#include <string>

namespace ZG::Panel::LandInner{

class URLField {
    private:
        const std::string name;
        const std::string description;
        const std::string URL;
    public:
        URLField (
            const std::string& name,
            const std::string& desription,
            const std::string& URL
        );
        URLField (URLField && other) = delete;
        URLField (const URLField & other) = default;
        std::string getName () const;
        std::string getDescription () const;
        std::string getURL () const;
};

}
