/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: Transform.hpp
*/

#ifndef SHIPWRECK_ENGINE_TRANSFORMMANAGER_HPP
#define SHIPWRECK_ENGINE_TRANSFORMMANAGER_HPP

#include "SWEngine.hpp"
#include "base/AManager.hpp"
#include "components/Transform.hpp"

namespace sw {
    class SW_MODULE_EXPORT TransformManager : public sw::AManager<Transform> {
        public:
            using sw::AManager<Transform>::AManager;

            ~TransformManager() override = default;

            void onUpdate() override {};
    }; // class TransformManager

} // sw

#endif //SHIPWRECK_ENGINE_TRANSFORMMANAGER_HPP
