#include "entity.h"

namespace oasis
{
    namespace game
    {
        void world::tick()
        {
            for (unsigned int i = 0; i < _data.size(); i++)
            {
                ((entity*)_data[i])->tick();
            }
        }
    }
}
