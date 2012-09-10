#ifndef graphics_sprite_h
#define graphics_sprite_h

#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

namespace oasis
{
    namespace graphics
    {
        class sprite
        {
            public:
                class animation
                {
                    friend class sprite;

                    protected:
                        unsigned int _count, _xinc, _yinc;
                        float _time;
                        const sf::Texture& _image;
                        std::vector<sf::IntRect> _frames;

                    public:
                        animation(const sf::Texture& image_, unsigned int xcount_, unsigned int ycount_, float time_);
                };

            private:
                bool _running;
                unsigned int _frame;
                animation* _image;
                sf::Clock _time;
                sf::Sprite _target;

            public:
                sprite(animation& image_) : _running(true) {setImage(image_);};

                void tick();
                void setFrame(unsigned int frame_);
                void setImage(animation& image_);
                void setRunning(bool running_);
                virtual void setPosition(float x_, float y_) {_target.setPosition(x_, y_);};
                virtual void setScale(float x_, float y_) {_target.setScale(x_, y_);};
                sf::Drawable& target() {return _target;};
        };
    }
}

#endif
