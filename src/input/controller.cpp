#include "input/controller.h"

namespace oasis
{
    namespace input
    {
        void controller::input(sf::Event event_)
        {
            for (unsigned int i = 0; i < container::_data.size(); i ++)
            {
                ((gameInput*)container::_data[i])->input(event_);
            }
        }
    }
}
