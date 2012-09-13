#ifndef util_config_h
#define util_config_h

#include <fstream>
#include <map>
#include <string>

namespace oasis
{
    namespace util
    {
        template <typename T> class stringTo
        {
            public:
                virtual T get(std::string name_) = 0;
                virtual std::string name(T value_) = 0;
        };

        template <typename T, typename I> class config
        {
            protected:
                std::map<std::string, T> _values;

                void load(std::string name_, I proc_)
                {
                    std::ifstream file_;
                    file_.open(name_.c_str());

                    if (!file_.is_open())
                        return;

                    std::string key_, raw_;
                    T value_;

                    while(file_ >> key_ >> raw_)
                    {
                        value_ = proc_.get(raw_);
                        _values[key_] = value_;
                    }
                }
        };
    }
}

#endif
