/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: ResourceMap.hpp
*/

#ifndef SHIPWRECK_ENGINE_RESOURCEMAP_HPP
#define SHIPWRECK_ENGINE_RESOURCEMAP_HPP

#include <string>
#include <map>
#include <memory>
#include <iostream>

#include "SWEngine.hpp"
#include "utils/exception/Error.hpp"

namespace sw {

    template<typename T>
    class SW_MODULE_EXPORT ResourceMap : public std::map<std::string, std::shared_ptr<T>> {
        public:
            /// @brief Get an element for the map
            ///
            /// \param name name of the resource
            /// \return Shared pointer of the resource
            std::shared_ptr<T> operator[](std::string name);

            /// @brief Get an element for the map
            ///
            /// \param name name of the resource
            /// \return Shared pointer of the resource
            std::shared_ptr<T> operator[](std::string name) const;

            /// @brief
            ///
            /// \tparam args needed arguments according to the T resource
            /// \param name name of the resource
            /// \param args needed arguments according to the T resource
            template<typename... Args>
            void createResource(std::string name, Args... args);
    };
} // SW

#include "ResourceMap.inl"

#endif //SHIPWRECK_ENGINE_RESOURCEMAP_HPP
