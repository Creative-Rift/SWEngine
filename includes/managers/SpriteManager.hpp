/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: SpriteManager.hpp
*/

#ifndef SHIPWRECK_ENGINE_SPRITEMANAGER_HPP
#define SHIPWRECK_ENGINE_SPRITEMANAGER_HPP

#include "SWEngine.hpp"
#include "base/AManager.hpp"
#include "components/Sprite.hpp"

namespace sw {
    class SW_MODULE_EXPORT SpriteManager : public AManager<Sprite> {
        public:
            /// \brief Default constructor
            using sw::AManager<Sprite>::AManager;

            /// \brief Default destructor
            ~SpriteManager() override = default;

            /// \brief Function called each frame to update all Sprite
            void onUpdate() override;

        private:
            /// \brief Manage orientation
            ///
            /// \param sprite Current updated Sprite
            static void updateInvert(sw::Sprite &sprite);

            /// \brief Update the display rect
            ///
            /// \param sprite Current updated Sprite
            static void defineRect(sw::Sprite &sprite);

    }; // class SpriteManager
} // SW

#endif //SHIPWRECK_ENGINE_SPRITEMANAGER_HPP
