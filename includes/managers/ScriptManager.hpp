/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: ScriptManager.hpp
*/

#ifndef SHIPWRECK_ENGINE_SCRIPTMANAGER_HPP
#define SHIPWRECK_ENGINE_SCRIPTMANAGER_HPP

#include "base/AManager.hpp"
#include "components/Script.hpp"

namespace sw {
    class SW_MODULE_EXPORT ScriptManager : public sw::AManager<Script> {
        public:
            using sw::AManager<Script>::AManager;

            void load() override;
            void onUpdate() override;
    }; // class TransformManager
} // SW

#endif //SHIPWRECK_ENGINE_SCRIPTMANAGER_HPP
