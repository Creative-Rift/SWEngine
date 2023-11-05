/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: Singleton.cpp
*/

#include "utils/Singleton.hpp"

sw::Singleton* sw::Singleton::m_instance{nullptr};
std::mutex sw::Singleton::mutex_;

sw::Singleton *sw::Singleton::GetInstance()
{
    std::lock_guard<std::mutex> lock(mutex_);
    if (m_instance == nullptr)
        m_instance = new Singleton();
    return m_instance;
}