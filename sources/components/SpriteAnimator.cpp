/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: SpriteAnimator.cpp
*/

#include <iostream>

#include "components/SpriteAnimator.hpp"
#include "gameobject/GameObject.hpp"
#include "components/Sprite.hpp"

sw::SpriteAnimator::SpriteAnimator(sw::GameObject &gameObject) :
        sw::Component(gameObject),
        m_rect(),
        m_displayRect(),
        m_lastFrame(0.0),
        m_endFrame(-1),
        m_loopDelay(0.0f),
        m_isPlaying(false),
        m_loop(false),
        m_framePerSecond(0.2),
        m_spr(gameObject.getComponent<sw::Sprite>()),
        m_type(ANIM_SPRITE),
        m_playOnStart(true)
{
    m_displayRect = {0, 0, static_cast<float>(m_spr.texture()->getWidth()),
                     static_cast<float>(m_spr.texture()->getHeight())};
    // gameObject.scene().eventManager["Start"].subscribe(m_gameObject.name(), this, &SpriteAnimator::playOnStart);
}

void sw::SpriteAnimator::playOnStart()
{
    if (m_playOnStart)
        play();
}

bool sw::SpriteAnimator::isPlaying() const
{
    return (m_isPlaying);
}

void sw::SpriteAnimator::play()
{
    m_isPlaying = true;
}

void sw::SpriteAnimator::pause()
{
    m_isPlaying = false;
}

void sw::SpriteAnimator::reset()
{
    m_isPlaying = false;
    m_displayRect = {0, 0, static_cast<float>(m_rect.y), static_cast<float>(m_rect.x)};
}

sw::SpriteAnimator &sw::SpriteAnimator::setLoop(bool loop, float delay)
{
    m_loop = loop;
    m_loopDelay = delay;
    return (*this);
}

sw::SpriteAnimator &sw::SpriteAnimator::setLine(int line, int end)
{
    if (line * m_rect.y >= m_spr.texture()->getHeight()) {
        std::cout << "The line line is out of range!\n";
        return (*this);
    }
    m_endFrame = (end == -1) ? (int) (m_spr.texture()->getWidth() / m_rect.x) + 1 : end;
    m_displayRect.top = (float) line * (float) m_rect.y;
    return (*this);
}

sw::SpriteAnimator &sw::SpriteAnimator::setRect(sw::Vector2u rect)
{
    m_rect = rect;
    m_displayRect.height = (float) m_rect.y;
    m_displayRect.width = (float) m_rect.x;
    m_endFrame = (int) (m_spr.texture()->getWidth() / m_rect.x) + 1;
    m_spr.setTextureRect(m_displayRect);
    return (*this);
}

sw::SpriteAnimator &sw::SpriteAnimator::setFPS(float fps)
{
    m_framePerSecond = 1.0f / fps;
    return (*this);
}

sw::SpriteAnimator &sw::SpriteAnimator::setPlayOnStart(bool value)
{
    m_playOnStart = value;
    return (*this);
}

const bool &sw::SpriteAnimator::isLoop() const
{
    return (m_loop);
}

const sw::Vector2u &sw::SpriteAnimator::getRect() const
{
    return (m_rect);
}

const float &sw::SpriteAnimator::getLoopDelay() const
{
    return (m_loopDelay);
}

const float &sw::SpriteAnimator::getFPS() const
{
    return (m_framePerSecond);
}

sw::SpriteAnimator &sw::SpriteAnimator::setAnimType(sw::SpriteAnimator::AnimType type)
{
    m_type = type;
    return (*this);
}

sw::SpriteAnimator::AnimType &sw::SpriteAnimator::getAnimType()
{
    return (m_type);
}

const bool &sw::SpriteAnimator::getPlayOnStart()
{
    return (m_playOnStart);
}