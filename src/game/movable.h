#ifndef game_moveable_h
#define game_moveable_h

#include <string>
#include <map>

#include <SFML/Window.hpp>

#include "entity.h"
#include "input/controller.h"

namespace oasis
{
    namespace game
    {
        class movable: public entity
        {
            public:
                enum motion
                {
                    none,
                    left,
                    right,
                    up,
                    down,
                    num
                };

            private:
                virtual void setVert(motion state_) {};
                virtual void setHoriz(motion state_) = 0;

            protected:
                motion _vert;
                motion _horiz;

            public:
                void setVertical(motion state_) {setVert(state_); _vert = state_;};
                void setHorizontal(motion state_) {setHoriz(state_); _horiz = state_;};
                motion vertical() {return _vert;};
                motion horizontal() {return _horiz;};
        };

        class motionInput: public input::gameInput
        {
            protected:
                movable* _owner;
                std::map<movable::motion, std::string> _map;

                virtual void setMap();

            public:
                motionInput(movable& owner_);

                void input(sf::Event event_);
                void tick();
        };
    }
}

#endif
