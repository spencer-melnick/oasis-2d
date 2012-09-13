#include "keymap.h"

namespace oasis
{
    namespace input
    {
        keyEnum::keyEnum()
        {
            _keys["None"] = key::Unknown;
            _keys["A"] = key::A;
            _keys["B"] = key::B;
            _keys["C"] = key::C;
            _keys["D"] = key::D;
            _keys["E"] = key::E;
            _keys["F"] = key::F;
            _keys["G"] = key::G;
            _keys["H"] = key::H;
            _keys["I"] = key::I;
            _keys["J"] = key::J;
            _keys["K"] = key::K;
            _keys["L"] = key::L;
            _keys["M"] = key::M;
            _keys["N"] = key::N;
            _keys["O"] = key::O;
            _keys["P"] = key::P;
            _keys["Q"] = key::Q;
            _keys["R"] = key::R;
            _keys["S"] = key::S;
            _keys["T"] = key::T;
            _keys["U"] = key::U;
            _keys["V"] = key::V;
            _keys["W"] = key::W;
            _keys["X"] = key::X;
            _keys["Y"] = key::Y;
            _keys["Z"] = key::Z;
            _keys["0"] = key::Num0;
            _keys["1"] = key::Num1;
            _keys["2"] = key::Num2;
            _keys["3"] = key::Num3;
            _keys["4"] = key::Num4;
            _keys["5"] = key::Num5;
            _keys["6"] = key::Num6;
            _keys["7"] = key::Num7;
            _keys["8"] = key::Num8;
            _keys["9"] = key::Num9;
            _keys["Esc"] = key::Escape;
            _keys["LCtrl"] = key::LControl;
            _keys["LShft"] = key::LShift;
            _keys["LAlt"] = key::LAlt;
            _keys["RCtrl"] = key::RControl;
            _keys["RShft"] = key::RShift;
            _keys["RAlt"] = key::RAlt;
            _keys["["] = key::LBracket;
            _keys["]"] = key::RBracket;
            _keys[";"] = key::SemiColon;
            _keys[","] = key::Comma;
            _keys["."] = key::Period;
            _keys["\""] = key::Quote;
            _keys["/"] = key::Slash;
            _keys["\\"] = key::BackSlash;
            _keys["~"] = key::Tilde;
            _keys["="] = key::Equal;
            _keys["-"] = key::Dash;
            _keys["Space"] = key::Space;
            _keys["Enter"] = key::Return;
            _keys["Back"] = key::BackSpace;
            _keys["Tab"] = key::Tab;
            _keys["PUp"] = key::PageUp;
            _keys["PDown"] = key::PageDown;
            _keys["End"] = key::End;
            _keys["Home"] = key::Home;
            _keys["Insrt"] = key::Insert;
            _keys["Del"] = key::Delete;
            _keys["+"] = key::Add;
            _keys["*"] = key::Multiply;
            _keys["Left"] = key::Left;
            _keys["Right"] = key::Right;
            _keys["Up"] = key::Up;
            _keys["Down"] = key::Down;
            _keys["Num0"] = key::Numpad0;
            _keys["Num1"] = key::Numpad1;
            _keys["Num2"] = key::Numpad2;
            _keys["Num3"] = key::Numpad3;
            _keys["Num4"] = key::Numpad4;
            _keys["Num5"] = key::Numpad5;
            _keys["Num6"] = key::Numpad6;
            _keys["Num7"] = key::Numpad7;
            _keys["Num8"] = key::Numpad8;
            _keys["Num9"] = key::Numpad9;
            _keys["F1"] = key::F1;
            _keys["F2"] = key::F2;
            _keys["F3"] = key::F3;
            _keys["F4"] = key::F4;
            _keys["F5"] = key::F5;
            _keys["F6"] = key::F6;
            _keys["F7"] = key::F7;
            _keys["F8"] = key::F8;
            _keys["F9"] = key::F9;
            _keys["F10"] = key::F10;
            _keys["F11"] = key::F11;
            _keys["F12"] = key::F12;
            _keys["F13"] = key::F13;
            _keys["F14"] = key::F14;
            _keys["F15"] = key::F15;
        }

        keycode keyEnum::get(std::string key_)
        {
            return _keys[key_];
        }

        std::string keyEnum::name(keycode key_)
        {
            for (std::map<std::string, keycode>::iterator i = _keys.begin(); i != _keys.end(); i ++)
            {
                if (i->second == key_)
                    return i->first;
            }
            return std::string("N/A");
        }

        keycode& keymap::operator[](const std::string& key_)
        {
            if (config::_values.find(key_) == config::_values.end())
            {
                config::_values[key_] = key::Unknown;
            }

            return config::_values[key_];
        }
    }
}
