/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: Concept.hpp
** TODO: Add Scene to concept
*/

#ifndef SHIPWRECK_ENGINE_CONCEPT_HPP
#define SHIPWRECK_ENGINE_CONCEPT_HPP

#include <concepts>

namespace sw {
    class Component;
    class IManager;

    template<class T>
    concept ClassComponent = std::is_base_of<Component, T>::value;

    template<class T>
    concept ClassManager = std::is_base_of<IManager, T>::value;
} // SW

#endif //SHIPWRECK_ENGINE_CONCEPT_HPP
