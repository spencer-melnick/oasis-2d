#ifndef input_controller_h
#define input_controller_h

#include <vector>

#include <SFML/Window.hpp>

#include "util/container.h"

namespace oasis
{
    namespace input
    {
        class gameInput: public util::container::object
        {
            public:
                virtual void input(sf::Event event_) = 0;
                virtual void destroy() {};
        };

        class controller: public util::container
        {
            public:
                void input(sf::Event event_);
                void add(gameInput& object_) {container::add(object_);};
                void destroy(gameInput& object_) {container::destroy(object_);};
        };
    }
}

#endif
