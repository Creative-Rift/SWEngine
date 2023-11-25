/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: Script.hpp
*/

#ifndef SHIPWRECK_ENGINE_SCRIPT_HPP
#define SHIPWRECK_ENGINE_SCRIPT_HPP

#include "base/Component.hpp"

namespace sw {

    class Script : public Component {
        public:
            explicit Script(GameObject& gameObject);
            virtual void onStart();
            virtual void onUpdate();
    };

} // sw

#endif //SHIPWRECK_ENGINE_SCRIPT_HPP
