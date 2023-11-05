/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: SpriteManager.cpp
*/

#include "managers/SpriteManager.hpp"
#include "gameobject/GameObject.hpp"

void sw::SpriteManager::onUpdate()
{
    // auto &camera = m_scene.getGameObject("MainCamera").getComponent<sw::Camera>("CameraManager");
    // camera.setProjection(sw::Camera::ORTHOGRAPHIC);
    for (auto &[_, id]: m_componentsLayers) {
        auto &object = m_components[id];
        if (!object->isActive() || !object->gameObject().isActive())
            continue;
        // auto &transform = object->gameObject().transform();
        glBindTexture(GL_TEXTURE_2D, object->texture()->getId());
        defineRect(*object);
        object->getShader()->useShader();
        // object->getShader()->setUniMat4("projection", camera.getProjection());
        // object->getShader()->setUniMat4("view", camera.getView());
        // object->getShader()->setUniMat4("model", transform.getGlobalMatrix());
        object->getShader()->setUniInt("hasTexture", 1);
        updateInvert(*object);
        object->m_vertexArray.update();
        glBindVertexArray(object->m_vertexArray.getVAO());
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
        glBindVertexArray(0);
    }
    // camera.setProjection(sw::Camera::PERSPECTIVE);
}

void sw::SpriteManager::updateInvert(sw::Sprite &sprite)
{
    if (sprite.m_invertedX) {
        auto save1 = sprite.m_vertexArray[0].position;
        auto save2 = sprite.m_vertexArray[1].position;
        sprite.m_vertexArray[0].position = sprite.m_vertexArray[3].position;
        sprite.m_vertexArray[1].position = sprite.m_vertexArray[2].position;
        sprite.m_vertexArray[2].position = save2;
        sprite.m_vertexArray[3].position = save1;
    }
    if (sprite.m_invertedY) {
        auto save1 = sprite.m_vertexArray[0].position;
        auto save2 = sprite.m_vertexArray[2].position;
        sprite.m_vertexArray[0].position = sprite.m_vertexArray[1].position;
        sprite.m_vertexArray[2].position = sprite.m_vertexArray[3].position;
        sprite.m_vertexArray[1].position = save1;
        sprite.m_vertexArray[3].position = save2;
    }
}

void sw::SpriteManager::defineRect(sw::Sprite &sprite)
{
    float a = sprite.m_rect.left / static_cast<float>(sprite.texture()->getWidth());
    float b = sprite.m_rect.width / static_cast<float>(sprite.texture()->getWidth());
    float c = sprite.m_rect.top / static_cast<float>(sprite.texture()->getHeight());
    float d = sprite.m_rect.height / static_cast<float>(sprite.texture()->getHeight());

    sprite.m_vertexArray[1].textureCoord = {a + b, c + d};
    sprite.m_vertexArray[0].textureCoord = {a + b, c};
    sprite.m_vertexArray[3].textureCoord = {a, c};
    sprite.m_vertexArray[2].textureCoord = {a, c + d};
    sprite.m_vertexArray[1].position = {(sprite.m_rect.width), 0, 0};
    sprite.m_vertexArray[2].position = {0, 0, 0};
    sprite.m_vertexArray[3].position = {0, (sprite.m_rect.height), 0};
    sprite.m_vertexArray[0].position = {(sprite.m_rect.width), (sprite.m_rect.height), 0};
}