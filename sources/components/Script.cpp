/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: Script.cpp
*/

#include <iostream>
#include "components/Script.hpp"

sw::Script::Script(sw::GameObject &gameObject) :
        sw::Component(gameObject)
{}

void sw::Script::onStart()
{
    std::cout << "Start Script" << std::endl;
}

void sw::Script::onUpdate()
{}