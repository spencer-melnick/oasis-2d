#ifndef app_h
#define app_h

#define GLEW_BUILD

#include <string>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "input/controller.h"

namespace oasis
{
    namespace app
    {
        class app
        {
            private:
                bool _fullscreen;
                std::string _name;
                sf::VideoMode _video;
                sf::VideoMode _wvideo;

            public:
                sf::RenderWindow window;

                app();

                void create();
                void create(std::string name_);
                void setFull(bool fullscreen_);
                void toggleFull();
                void input(oasis::input::controller& controller_);
        };
    }
}

#endif
