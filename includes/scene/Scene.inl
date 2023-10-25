/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: Scene.inl
*/

template<ClassManager Manager, typename... Args>
inline Manager& sw::Scene::createManager(Args... args)
{
    auto managerName = typeid(Manager).name();
    //if (m_managers.contains(managerName))
    //    sw::Speech::Warning(sw::Log::warning324(FUNCTION, name, managerName)); TODO: add log

    auto it = m_managers.try_emplace(managerName, std::make_unique<Manager>(managerName, *this, args...));
    return (static_cast<Manager&>(*(it.first->second)));
}

template<ClassManager Manager>
inline Manager& sw::Scene::getManager(const std::string& managerName)
try
{
    return (static_cast<Manager&>(*m_managers.at(managerName)));
}
catch (std::out_of_range&) {
    throw sw::Error("Manager not found");
}
