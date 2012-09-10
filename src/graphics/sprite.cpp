#include "sprite.h"

namespace oasis
{
    namespace graphics
    {
        sprite::animation::animation(const sf::Texture& image_, unsigned int xcount_, unsigned int ycount_, float time_) : _image(image_)
        {
            _count = xcount_ * ycount_;
            _time = time_;

            sf::Vector2u size_ = image_.getSize();

            _xinc = size_.x / xcount_;
            _yinc = size_.y / ycount_;

            for (unsigned int y_ = 0; y_ < ycount_; y_ ++)
            {
                for (unsigned int x_ = 0; x_ < xcount_; x_ ++)
                {
                    _frames.push_back(sf::IntRect(x_ * _xinc, y_ * _yinc, _xinc, _yinc));
                }
            }
        }

        void sprite::tick()
        {
            if (_running)
            {
                if (_time.getElapsedTime().asMilliseconds() >= _image->_time)
                    setFrame(_frame + 1);
            }
        }

        void sprite::setFrame(unsigned int frame_)
        {
            if (frame_ >= _image->_count)
                frame_ = 0;

            _frame = frame_;
            _time.restart();

            _target.setTextureRect(_image->_frames[_frame]);
        }

        void sprite::setImage(animation& image_)
        {
            _image = &image_;
            _target.setTexture(_image->_image);
            setFrame(0);
            _target.setOrigin(_image->_xinc / 2, _image->_yinc / 2);
        }

        void sprite::setRunning(bool running_)
        {
            _running = running_;
            _time.restart();
        }
    }
}
