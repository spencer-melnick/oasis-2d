#include "app.h"

namespace oasis
{
    namespace app
    {
        app::app()
        {
            _fullscreen = false;
            _video = sf::VideoMode::getDesktopMode();
            _wvideo = sf::VideoMode(800, 600);
        }

        void app::create()
        {
            sf::Uint32 style_ = sf::Style::Titlebar | sf::Style::Close | (_fullscreen ? sf::Style::Fullscreen : sf::Style::None);
            sf::VideoMode video_ = _fullscreen ? _video : _wvideo;

            window.create(video_, _name, style_);
            window.setVerticalSyncEnabled(true);
        }

        void app::create(std::string name_)
        {
            _name = name_;
            create();
        }

        void app::setFull(bool fullscreen_)
        {
            _fullscreen = fullscreen_;
            create();
        }

        void app::toggleFull()
        {
            setFull(!_fullscreen);
        }

        void app::input(input::controller& controller_)
        {
            sf::Event event_;

            while (window.pollEvent(event_))
            {
               controller_.input(event_);

                switch (event_.type)
                {
                    case sf::Event::Closed:
                        window.close();
                        break;

                    case sf::Event::KeyReleased:
                        switch (event_.key.code)
                        {
                            case sf::Keyboard::Escape:
                                window.close();
                                break;

                            case sf::Keyboard::F11:
                                toggleFull();
                                break;

                            default:
                                break;
                        }
                    default:
                        break;
                }
            }
        }
    }
}
