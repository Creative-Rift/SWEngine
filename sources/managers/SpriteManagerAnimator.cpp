/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: SpriteManagerAnimator.cpp
*/

#include "managers/SpriteAnimatorManager.hpp"
#include "gameobject/GameObject.hpp"

void sw::SpriteAnimatorManager::onUpdate()
{
    // double currentTime = sw::OpenGLModule::m_chrono.getTotalTime();
    double currentTime = 0;

    for (auto&[_, obj]: m_components) {
        if (!obj->isActive() || !obj->gameObject().isActive())
            continue;
        if (!obj->isPlaying()) {
            if (obj->isLoop() && (currentTime - obj->m_lastFrame) > obj->getLoopDelay()) {
                obj->m_isPlaying = true;
                obj->m_displayRect.width = static_cast<float>(obj->m_rect.x);
                obj->m_displayRect.height = static_cast<float>(obj->m_rect.y);
            }
        } else if ((currentTime - obj->m_lastFrame) > obj->getFPS()) {
            if (obj->getAnimType() == sw::SpriteAnimator::ANIM_LINE)
                animLine((*obj), currentTime);
            else if (obj->getAnimType() == sw::SpriteAnimator::ANIM_SPRITE)
                animSprite((*obj), currentTime);
        }
    }
}

void sw::SpriteAnimatorManager::animLine(sw::SpriteAnimator &animator, double &current_time)
{
    if (animator.m_displayRect.left + (float)animator.m_rect.x >= (float)animator.m_spr.texture()->getWidth() ||
        animator.m_displayRect.left / (float)animator.m_rect.x >= (float)animator.m_endFrame) {
        animator.m_displayRect.left = 0;
        animator.m_isPlaying = false;
    } else
        animator.m_displayRect.left += (float)animator.m_rect.x;
    animator.m_lastFrame = current_time;
    animator.m_spr.setTextureRect(animator.m_displayRect);
}

void sw::SpriteAnimatorManager::animSprite(sw::SpriteAnimator &animator, double &current_time)
{
    auto newRect = animator.m_displayRect;

    if (animator.m_displayRect.left + (float)animator.m_rect.x >= (float)animator.m_spr.texture()->getWidth()) {
        newRect.top += (float)animator.m_rect.y;
        newRect.left = 0;
    } else
        newRect.left += (float)animator.m_rect.x;
    animator.m_displayRect = newRect;
    animator.m_lastFrame = current_time;
    animator.m_spr.setTextureRect(animator.m_displayRect);
    if (newRect.top >= (float)animator.m_spr.texture()->getHeight())
        animator.reset();
}
