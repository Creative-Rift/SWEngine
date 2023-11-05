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
            std::shared_ptr<T> operator[](std::string name);
            std::shared_ptr<T> operator[](std::string name) const;
            template <typename... Args>
            void createResource(std::string name, Args... args);
    };
} // SW

#include "ResourceMap.inl"

#endif //SHIPWRECK_ENGINE_RESOURCEMAP_HPP
