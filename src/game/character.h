#ifndef game_character_h
#define game_character_h

#include <cmath>

#include <SFML/Window.hpp>

#include "movable.h"

#include "input/controller.h"
#include "app/app.h"
#include "graphics/sprite.h"

namespace oasis
{
    namespace game
    {
        class character: public movable
        {
            private:
                void setHoriz(movable::motion state_);

            protected:
                graphics::sprite _image;
                motionInput _input;

                app::app& _app;

            public:
                float x, y;

                character(graphics::sprite::animation& image_, app::app& app_, input::controller& controller_) : _image(image_), _input(*(movable*)(this)), _app(app_) {controller_.add(_input); _image.setRunning(false);};

                void tick();
                void destroy();
        };
    }
}

#endif
