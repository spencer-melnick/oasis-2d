#ifndef input_keymap_h
#define input_keymap_h

#include <map>
#include <string>

#include <SFML/Window.hpp>

#include "util/config.h"

namespace oasis
{
    namespace input
    {
        typedef sf::Keyboard key;
        typedef sf::Keyboard::Key keycode;

        class keyEnum: public util::stringTo<keycode>
        {
            private:
                std::map<std::string, keycode> _keys;

            public:
                keyEnum();
                keycode get(std::string name_);
                std::string name(keycode key_);
        };

        class keymap: public util::config<keycode, keyEnum>
        {
            public:
                keyEnum convert;

                keycode& operator[](const std::string& key_);
                void load(std::string name_) {config::load(name_, convert);};
        };
    }
}

#endif
