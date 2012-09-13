#include "movable.h"

namespace oasis
{
    namespace game
    {
        motionInput::motionInput(movable& owner_)
        {
            _owner = &owner_;
            setMap();
        }

        void motionInput::setMap()
        {
            _map[movable::left] = "Left";
            _map[movable::right] = "Right";
            _map[movable::up] = "Up";
            _map[movable::down] = "Down";
        }

        void motionInput::input(sf::Event event_)
        {
            switch (event_.type)
            {
            case sf::Event::KeyPressed:
                    for (std::map<movable::motion, std::string>::iterator i = _map.begin(); i != _map.end(); i++)
                    {
                        if (event_.key.code == ((input::controller*)(&object::owner()))->keys[i->second])
                        {
                            switch (i->first)
                            {
                                case movable::left:
                                case movable::right:
                                    if (_owner->horizontal() != i->first)
                                        _owner->setHorizontal(i->first);
                                    return;

                                case movable::up:
                                case movable::down:
                                    if (_owner->vertical() != i->first)
                                        _owner->setVertical(i->first);
                                    return;

                                default:
                                    return;
                            }
                        }
                    }
                    return;

                case sf::Event::KeyReleased:
                    for (std::map<movable::motion, std::string>::iterator i = _map.begin(); i != _map.end(); i++)
                    {
                        if (event_.key.code == ((input::controller*)(&object::owner()))->keys[i->second])
                            switch (i->first)
                            {
                                case movable::left:
                                case movable::right:
                                    if (_owner->horizontal() == i->first)
                                        _owner->setHorizontal(movable::none);
                                    return;

                                case movable::up:
                                case movable::down:
                                    if (_owner->vertical() == i->first)
                                        _owner->setVertical(movable::none);
                                    return;

                                default:
                                    return;
                            }
                    }
                    return;

                default:
                    return;
            }
        }
    }
}
