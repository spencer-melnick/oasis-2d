#include "container.h"

namespace oasis
{
    namespace util
    {
        void container::add(object& object_)
        {
            _data.push_back(&object_);
            object_._owned = true;
            object_._owner = this;
        }

        void container::destroy(object& object_)
        {
            std::remove(_data.begin(), _data.end(), &object_);
        }

        bool container::object::owned()
        {
            return _owned;
        }

        container& container::object::owner()
        {
            return *_owner;
        }
    }
}
