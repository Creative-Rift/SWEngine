/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: GameObject.inl
*/

template<ClassComponent Cpt, typename... Args>
inline Cpt& sw::GameObject::createComponent(Args... values)
{
    auto managerName = std::string(typeid(Cpt).name());
    sw::AManager<Cpt>& manager = m_scene.getManager<sw::AManager<Cpt>>(managerName.append("Manager"));

    //if (manager.hasComponent(m_name))
    //    sw::Speech::Warning(sw::Log::warning516(FUNCTION, m_name, managerName)); // TODO: add log
    return (m_scene.getManager<sw::AManager<Cpt>>(managerName).createComponent(m_id, values...));
}

template<ClassComponent Cpt>
inline bool sw::GameObject::hasComponent() const
{
    auto managerName = typeid(Cpt).name();
    return (m_scene.getManager(managerName).hasComponent(m_id));
}

template <ClassComponent Cpt>
inline Cpt& sw::GameObject::getComponent()
try
{
    auto managerName = std::string(typeid(Cpt).name());
    return (m_scene.getManager<sw::AManager<Cpt>>(managerName.append("Manager"))[m_name]);
}
catch (sw::Error& err) {
    throw sw::Error("Component not found");
}