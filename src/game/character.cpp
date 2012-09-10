#include "character.h"

namespace oasis
{
    namespace game
    {
        void charInput::tick()
        {
            /*bool moveL_, moveR_, moveU_, moveD_;

            moveL_ = gameInput::_state.down[sf::Keyboard::A] | gameInput::_state.down[sf::Keyboard::Left];
            moveR_ = gameInput::_state.down[sf::Keyboard::D] | gameInput::_state.down[sf::Keyboard::Right];
            moveU_ = gameInput::_state.down[sf::Keyboard::W] | gameInput::_state.down[sf::Keyboard::Up];
            moveD_ = gameInput::_state.down[sf::Keyboard::S] | gameInput::_state.down[sf::Keyboard::Down];

            if (moveL_ != moveR_)
                _xvel = moveR_ ? _speed : -_speed;
            else
                _xvel = 0;

            if (moveU_ != moveD_)
                _yvel = moveD_ ? _speed : -_speed;
            else
                _yvel = 0;*/
        }

        void character::tick()
        {
            float xvel_, yvel_;
            xvel_ = _xvel;
            yvel_ = _yvel;

            _input.tick();
            _image.tick();

            if (_xvel != 0 && xvel_ != _xvel)
                _image.setScale(_xvel > 0 ? 1 : -1, 1);

            if (_xvel == 0 && xvel_ != 0)
                _image.setRunning(false);

            if (_xvel != 0 && xvel_ == 0)
                _image.setRunning(true);

            x += _xvel;
            y += _yvel;

            _image.setPosition(x, y);

            _app.window.draw(_image.target());
        }

        void character::destroy()
        {
            //_controller.untrack(_input);
        }
    }
}
