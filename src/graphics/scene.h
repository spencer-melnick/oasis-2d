#ifndef graphics_scene_h
#define graphics_scene_h

#include <SFML/Graphics.hpp>

#include "util/container.h"

namespace oasis
{
    namespace graphics
    {
        class image: public util::container::object
        {
            protected:
                float _x, _y;

            public:
                virtual sf::Drawable& target() = 0;
                virtual void setPosition(float x_, float y_) {};
                virtual void setScale(float x_, float y_) {};
                virtual void destroy() {};
        };

        class scene: public util::container
        {
            public:
                void add(image& object_) {util::container::add(object_);};
                void destroy(image& object_) {util::container::destroy(object_);};
        };
    }
}
