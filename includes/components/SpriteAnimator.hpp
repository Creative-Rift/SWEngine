/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: SpriteAnimator.hpp
*/

#ifndef SHIPWRECK_ENGINE_SPRITEANIMATOR_HPP
#define SHIPWRECK_ENGINE_SPRITEANIMATOR_HPP

#include "SWEngine.hpp"
#include "base/Component.hpp"
#include "utils/Vector2.hpp"
#include "utils/Rect.hpp"
#include "Sprite.hpp"

namespace sw {

    class SpriteAnimatorManager;

    class SW_MODULE_EXPORT SpriteAnimator : public sw::Component {
        public:
            /// \brief Define the type of the animation
            enum AnimType {
                ANIM_SPRITE,    // One animation on the whole texture
                ANIM_LINE       // One animation per line
            };

            /// \brief Default constructor
            ///
            /// \param gameObject Reference to the gameObject
            explicit SpriteAnimator(sw::GameObject &gameObject);

            /// \brief Play your animation
            void play();

            /// \brief Pause on your animation
            void pause();

            /// \brief Reset your animation (set on first frame)
            void reset();

            /// \brief Return a bool if the animation is currently playing
            ///
            /// \return bool
            [[nodiscard]] bool isPlaying() const;

            /// \brief Define if your animation loop
            ///
            /// \param loop boolean
            /// \param delay delay between two animation
            /// \return reference to your sprite SpriteAnimator
            SpriteAnimator &setLoop(bool loop, float delay = 0);

            /// \brief If you have one animation per line on your texture, you can define
            ///        the line you want and the number of the frame (if you have
            ///        less frame than the length of your texture)
            ///
            /// \param line Number of the line where the animation is
            /// \param end Number of frame in your animation
            /// \return reference to your sprite SpriteAnimator
            SpriteAnimator &setLine(int line, int end = -1);

            /// \brief Define the displayed rect on your texture
            ///
            /// \param rect Rect's size (width, height)
            /// \return reference to your sprite SpriteAnimator
            SpriteAnimator &setRect(sw::Vector2u rect);

            /// \brief Define the speed (number of frame per second) of your animation
            ///
            /// \param fps float
            /// \return reference to your sprite
            SpriteAnimator &setFPS(float fps);

            /// \brief Define the type of your animation. See AnimationType
            ///
            /// \param type Type of your animation
            /// \return reference to your sprite
            SpriteAnimator &setAnimType(AnimType type);

            /// \brief Define if the Animation will play on start
            ///
            /// \param value boolean
            /// \return reference to your sprite
            SpriteAnimator &setPlayOnStart(bool value);

            /// \brief Get if the animation loop
            ///
            /// \return bool
            [[nodiscard]]const bool &isLoop() const;

            /// \brief Get the displayed rect
            ///
            /// \return sw::Rect
            [[nodiscard]]const sw::Vector2u &getRect() const;

            /// \brief Get the delay of your animation loop
            ///
            /// \return float
            [[nodiscard]]const float &getLoopDelay() const;

            /// \brief Get the speed of your animation
            ///
            /// \return float Frame per second
            [[nodiscard]]const float &getFPS() const;

            /// \brief Get the type of your animation
            ///
            /// \return AnimType
            [[nodiscard]]AnimType &getAnimType();

            /// \brief Get if the animation will play on start
            ///
            /// \return bool
            [[nodiscard]]const bool &getPlayOnStart();

        private:
            sw::Vector2u m_rect;
            sw::FloatRect m_displayRect;
            double m_lastFrame;
            int m_endFrame;
            float m_loopDelay;
            bool m_isPlaying;
            bool m_loop;
            bool m_playOnStart;
            float m_framePerSecond;
            AnimType m_type;

            Sprite &m_spr;

            void playOnStart();

            friend SpriteAnimatorManager;

    }; // class SpriteAnimator
} // SW

#endif //SHIPWRECK_ENGINE_SPRITEANIMATOR_HPP
