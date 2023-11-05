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
            /// \brief Default constructor of the AManager class
            using sw::AManager<Sprite>::AManager;

            /// \brief Default destructor
            ~SpriteManager() override = default;

            /// \brief This function is called one time per frame and update all component \n
            /// stored according their data
            void onUpdate() override;

        private:
            /// \brief This function update the Vertex of the sprite anf flip them is needed
            ///
            /// \param sprite Get a reference to the Sprite
            static void updateInvert(sw::Sprite &sprite);

            /// \brief This function update all vertex according the parameters of the Sprite \n
            /// He change the Vertex texture coordinate according to the rect
            ///
            /// \param sprite Get a reference to the Sprite
            static void defineRect(sw::Sprite &sprite);

    }; // class SpriteManager
} // SW

#endif //SHIPWRECK_ENGINE_SPRITEMANAGER_HPP
