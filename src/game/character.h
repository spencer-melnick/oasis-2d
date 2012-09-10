#ifndef game_character_h
#define game_character_h

#include <iostream>

#include "entity.h"

#include "input/controller.h"
#include "app/app.h"
#include "graphics/sprite.h"

namespace oasis
{
    namespace game
    {
        class charInput: public input::gameInput
        {
            private:
                bool _moving;
                float& _xvel, &_yvel;
                float _speed;

            public:
                charInput(float& xvel_, float& yvel_) : _xvel(xvel_), _yvel(yvel_){};

                void input(sf::Event event_) {};
                void tick();
        };

        class character: public entity
        {
            protected:
                enum mode
                {
                    standing,
                    walking,
                    numStates
                };

                float _xvel, _yvel;

                graphics::sprite _image;
                charInput _input;

                app::app& _app;

            public:
                float x, y;
                mode state;

                character(graphics::sprite::animation& image_, app::app& app_, input::controller& controller_) : _image(image_), _input(_xvel, _yvel), _app(app_) {controller_.add(_input);};

                void tick();
                void destroy();
        };
    }
}

#endif
