/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: SpriteManagerAnimator.hpp
*/

#ifndef SHIPWRECK_ENGINE_SPRITEANIMATORMANAGER_HPP
#define SHIPWRECK_ENGINE_SPRITEANIMATORMANAGER_HPP

#include "base/AManager.hpp"
#include "components/SpriteAnimator.hpp"

namespace sw {

    class SW_MODULE_EXPORT SpriteAnimatorManager : public AManager<SpriteAnimator>{
        public:
            /// \brief Default constructor of the AManager class
            using sw::AManager<SpriteAnimator>::AManager;

            /// \brief Default destructor
            ~SpriteAnimatorManager() override = default;

            /// \brief This function is called one time per frame and update all component \n
            /// stored according their data
            void onUpdate() override;

        private:

            /// \brief Update Animation following rules defined for the Type
            ///        sw::SpriteAnimator::ANIM_LINE
            ///
            /// \param animator Reference to the animator
            /// \param current_time get total time
            static void animLine(SpriteAnimator &animator, double &current_time);

            /// \brief Update Animation following rules defined for the Type
            ///        sw::SpriteAnimator::ANIM_SPRITE
            ///
            /// \param animator Reference to the animator
            /// \param current_time get total time
            static void animSprite(SpriteAnimator &animator, double &current_time);


    }; // class SpriteManagerAnimator

} // sw

#endif //SHIPWRECK_ENGINE_SPRITEANIMATORMANAGER_HPP
