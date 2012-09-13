#include "character.h"

namespace oasis
{
    namespace game
    {
        void character::setHoriz(movable::motion state_)
        {
            sf::Vector2f scale_ = _image.getScale();
            switch (state_)
            {
                case left:
                    scale_.x = -fabs(scale_.x);
                    _image.setRunning(true);
                    _image.setScale(scale_.x, scale_.y);
                    return;

                case right:
                    scale_.x = fabs(scale_.x);
                    _image.setRunning(true);
                    _image.setScale(scale_.x, scale_.y);
                    return;

                case none:
                    _image.setRunning(false);
                    return;

                default:
                    return;
            }
        }

        void character::tick()
        {
            _image.tick();
            _image.setPosition(x, y);

            switch (movable::_horiz)
            {
                case left:
                    x -= 5;
                    break;

                case right:
                    x += 5;
                    break;

                default:
                    break;
            }

            switch (movable::_vert)
            {
                case up:
                    y -= 5;
                    break;

                case down:
                    y += 5;
                    break;

                default:
                    break;
            }

            _app.window.draw(_image.target());
        }

        void character::destroy()
        {
            //_controller.untrack(_input);
        }
    }
}
