#ifndef util_container_h
#define util_container_h

#include <vector>
#include <algorithm>

namespace oasis
{
    namespace util
    {
        class container
        {
            public:
                class object
                {
                    friend class container;

                    private:
                        bool _owned;
                        container* _owner;

                        virtual void destroy() = 0;

                    protected:
                        bool owned();
                        container& owner();
                };

            protected:
                std::vector<object const*> _data;

                void add(object& object_);
                void destroy(object& object_);
        };
    }
}

#endif
