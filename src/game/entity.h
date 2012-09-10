#ifndef game_entity_h
#define game_entity_h

#include <vector>

#include "util/container.h"

namespace oasis
{
    namespace game
    {
        class entity: public util::container::object
        {
            public:
                float x, y;

                virtual void tick() = 0;
                virtual void destroy() = 0;
        };

        class world: public util::container
        {
            public:
                void add(entity& entity_) {container::add(entity_);};
                void destroy(entity& entity_) {container::destroy(entity_);};
                void tick();
        };
    }
}

#endif
