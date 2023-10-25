/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: Transform.hpp
*/

#ifndef SHIPWRECK_ENGINE_TRANSFORM_HPP
#define SHIPWRECK_ENGINE_TRANSFORM_HPP

#include "glm/glm.hpp"

#include "SWEngine.hpp"
#include "components/base/Component.hpp"
#include "utils/Vector3.hpp"
#include "utils/Vector2.hpp"

namespace sw {

    class GameObject;

    class SW_MODULE_EXPORT Transform : public Component {
        public:

            /// @brief Default constructor
            explicit Transform(sw::GameObject &gameObject);

            /// @brief Set the position of a GameObject.
            ///
            /// @param position sw::Vector 3
            void setPosition(const sw::Vector3f& position);

            /// @brief Set the position of a GameObject. Z axis set to 0.
            ///
            /// @param position sw::Vector 2
            void setPosition(const sw::Vector2f& position);

            /// @brief Set the position of a GameObject.
            ///
            /// @param x float
            /// @param y float
            /// @param z float
            void setPosition(float x, float y, float z = 0);

            /// @brief Move a GameObject.
            ///
            /// @param offset sw::Vector3
            void move(const sw::Vector3f& position);

            /// @brief Move a GameObject. Z axis set to 0.
            ///
            /// @param offset sw::Vector3
            void move(const sw::Vector2f& position);

            /// @brief Move a GameObject.
            ///
            /// @param x float
            /// @param y float
            /// @param z float
            void move(float x, float y, float z = 0);

            /// @brief Get the (local) position of the GameObject.
            ///
            /// \return sw::Vector3f
            const sw::Vector3f& getPosition() const noexcept;

            /// @brief Get the global (world) position of the GameObject.
            /// (Include its parents)
            ///
            /// \return
            const sw::Vector3f& getGlobalPosition() const noexcept;

            /// @brief Define the scale of the GameObject.
            ///
            /// @param scale sw::Vector3f
            void setScale(const sw::Vector3f& scaleVec);

            /// @brief Define the scale of the GameObject. Z axis set to 1.
            ///
            /// @param scale sw::Vector2f
            void setScale(const sw::Vector2f& scaleVec);

            /// @brief Define the scale of the GameObject.
            ///
            /// @param x float
            /// @param y float
            /// @param z float
            void setScale(float x, float y, float z = 1);

            /// @brief Scale the GameObject.
            ///
            /// @param scale sw::Vector3f
            void scale(const sw::Vector3f& scaleVec);

            /// @brief Scale the GameObject.
            ///
            /// @param scale sw::Vector2f
            void scale(const sw::Vector2f& scaleVec);

            /// @brief Scale the GameObject.
            ///
            /// @param x flat
            /// @param y flat
            /// @param z flat
            void scale(const float x, const float y, const float z = 1);

            /// @brief Get (local) scale of the GameObject.
            ///
            /// \return sw::Vector3f
            const sw::Vector3f& getScale() const noexcept;

            /// @brief Get global (world) scale of the GameObject.
            ///
            /// \return sw::Vector3f
            const sw::Vector3f& getGlobalScale() const noexcept;

            /// @brief Define the rotation of the GameObject.
            ///
            /// \param angle     float - in degrees
            /// \param rotationX float - X axis rotation
            /// \param rotationY float - Y axis rotation
            /// \param rotationZ float - Z axis rotation
            void setRotation(float angle, float rotationX = 0, float rotationY = 1, float rotationZ = 0);

            /// @brief Rotate the GameObject.
            ///
            /// \param angle     float - in degrees
            /// \param rotationX float - X axis rotation
            /// \param rotationY float - Y axis rotation
            /// \param rotationZ float - Z axis rotation
            void rotate(float angle, float rotationX = 0, float rotationY = 1, float rotationZ = 0);

            /// @brief Get the (local) rotation axis.
            ///
            /// \return sw::Vector3f
            const sw::Vector3f& getRotationAxis() const noexcept;

            /// @brief Get the rotation angle in degree.
            ///
            /// \return float
            const float& getAngle() const noexcept;

            /// @brief Get the global (world) rotation axis.
            ///
            /// \return sw::Vector3f
            const sw::Vector3f& getGlobalRotationAxis();

            /// @brief Get current matrix.
            ///
            /// \return glm::mat4
            const glm::mat4& getMatrix() noexcept;

            /// @brief Get the current global matrix.
            ///
            /// \return glm::mat4
            const glm::mat4& getGlobalMatrix();

            /// @brief Return the position of the given point, transform by
            /// the Matrix Component (local).
            ///
            /// @param point - point's position
            sw::Vector3f getTransformPoint(const sw::Vector3f& point);

            /// @brief Return the position of the given point, transform by
            /// the Matrix Component (local).
            ///
            /// @param x - coordinate of the point to transform.
            /// @param y - coordinate of the point to transform.
            /// @param z - coordinate of the point to transform.
            sw::Vector3f getTransformPoint(float x, float y, float z = 1);

            /// @brief Return the position of the given point, transform by
            /// the Matrix Component (global).
            ///
            /// @param point - point's position
            sw::Vector3f getGlobalTransformPoint(const sw::Vector3f& point);

            /// Return the position of the given point, transform by
            /// the Matrix Component (global).
            ///
            /// @param x - coordinate of the point to transform.
            /// @param y - coordinate of the point to transform.
            /// @param z - coordinate of the point to transform.
            sw::Vector3f getGlobalTransformPoint(float x, float y, float z = 1);

        private:
            glm::mat4 m_matrix;                 // Matrix(4x4) for local transform
            glm::mat4 m_globalMatrix;           // Matrix(4x4) for global transform (include all parent)
            sw::Vector3f m_position;            // Local Position of the GameObject
            sw::Vector3f m_globalPosition;      // Global position of the GameObject (include all parent)
            sw::Vector3f m_scale;               // Local Scale of the GameObject
            sw::Vector3f m_globalScale;         // Global Scale of the GameObject (include all parent)
            float m_angle;                      // Rotation angle
            sw::Vector3f m_rotationAxis;        // Local Vector which define the axis rotation
            sw::Vector3f m_globalRotationAxis;  // Global Vector which define the axis rotation (include all parent)

    }; // class Transform

} // sw

#endif //SHIPWRECK_ENGINE_TRANSFORM_HPP
