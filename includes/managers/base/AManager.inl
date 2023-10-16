/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: AManager.inl
*/

template<ClassComponent Cpt>
inline sw::AManager<Cpt>::AManager(const std::string& managerName, Scene& sceneRef) :
m_name{managerName},
m_scene{sceneRef},
m_isLoad{false},
m_isActive{true},
m_components{},
m_componentsLayers{},
m_deleteComponent{}
{}

template<ClassComponent Cpt>
inline sw::AManager<Cpt>::~AManager()
{
    m_components.clear();
    m_componentsLayers.clear();
}

template<ClassComponent Cpt>
std::string sw::AManager<Cpt>::name() const
{ return (m_name); }

template<ClassComponent Cpt>
sw::Scene& sw::AManager<Cpt>::scene() const
{ return (m_scene); }

template <ClassComponent Cpt>
inline bool sw::AManager<Cpt>::isActive() const
{ return (m_isActive); }

template <ClassComponent Cpt>
inline void sw::AManager<Cpt>::setActive(bool value)
{ m_isActive = value; }

template<ClassComponent Cpt>
bool sw::AManager<Cpt>::isLoad() const
{ return m_isLoad; }

template<ClassComponent Cpt>
inline void sw::AManager<Cpt>::load()
try
{
    if (m_isLoad) {
        /// TODO: add Log
        return;
    }
    m_isLoad = true;
}
catch (sw::Error& error)
{
    /// TODO: add Log
    throw sw::Error("Error during the load process [" + m_name + "]" + error.what());
}

template<ClassComponent Cpt>
inline void sw::AManager<Cpt>::update()
try
{
    if (!m_isLoad) {
        /// TODO: add Log
        return;
    }
    deleteRequestedComponents();
    onUpdate();
}
catch (sw::Error& error)
{
    /// TODO: add Log
    throw sw::Error("Error during the update process [" + m_name + "]" + error.what());
}

template<ClassComponent Cpt>
inline void sw::AManager<Cpt>::unload()
try
{
    if (!m_isLoad) {
        /// TODO: add Log
        return;
    }
    m_components.clear();
    m_componentsLayers.clear();
    m_isLoad = false;
}
catch (sw::Error& error)
{
    /// TODO: add Log
    throw sw::Error("Error during the unload process [" + m_name + "]" + error.what());
}

template <ClassComponent Cpt>
template <typename... Args>
inline Cpt& sw::AManager<Cpt>::createComponent(const std::string& gameObjectName, Args... values)
{
    if (!m_scene.hasGameObject(gameObjectName))
        throw sw::Error("GameObject [" + gameObjectName + "] doesn't exist");
    //if (m_components.contains(gameObjectName))
        /// TODO: add Log

    auto &go = m_scene.getGameObjectByName(gameObjectName);
    auto it = m_components.try_emplace(go.id(), std::make_shared<Cpt>(go, values...));
    if (it.second)
        m_componentsLayers.emplace_front(std::make_pair(0, go.id()));
    return (*(it.first->second));
}

template<ClassComponent Cpt>
inline bool sw::AManager<Cpt>::hasComponent(const std::string& gameObjectName) const
{
    auto &go = m_scene.getGameObjectByName(gameObjectName);
    return (m_components.contains(go.id()));
}

template<ClassComponent Cpt>
inline bool sw::AManager<Cpt>::hasComponent(const boost::uuids::uuid &gameObjectId) const
{
    return (m_components.contains(gameObjectId));
}

template<ClassComponent Cpt>
inline void sw::AManager<Cpt>::deleteComponent(const std::string& gameObjectName)
{
    auto &go = m_scene.getGameObjectByName(gameObjectName);

    if (!m_components.contains(go.id())) {
        /// TODO: add Log
        return;
    }
    m_deleteComponent.emplace(go.id());
}

template<ClassComponent Cpt>
inline void sw::AManager<Cpt>::deleteComponent(const boost::uuids::uuid &gameObjectId)
{
    if (!m_components.contains(gameObjectId)) {
        /// TODO: add Log
        return;
    }
    m_deleteComponent.emplace(gameObjectId);
}

template<ClassComponent Cpt>
inline void sw::AManager<Cpt>::setLayer(const std::string& gameObjectName, int value)
{
    auto &go = m_scene.getGameObjectByName(gameObjectName);

    if (!m_components.contains(go.id())) {
        /// TODO: add Log
        return;
    }
    for (auto& [layer, id] : m_componentsLayers)
        if (m_components[id]->gameObjectName() == gameObjectName) {
            layer = value;
            break;
        }
    m_componentsLayers.sort();
}

template<ClassComponent Cpt>
inline void sw::AManager<Cpt>::setLayer(const boost::uuids::uuid &gameObjectId, int value)
{
    if (!m_components.contains(gameObjectId)) {
        /// TODO: add Log
        return;
    }
    for (auto& [layer, id] : m_componentsLayers)
        if (id == gameObjectId) {
            layer = value;
            break;
        }
    m_componentsLayers.sort();
}

template<ClassComponent Cpt>
inline int sw::AManager<Cpt>::getLayer(const std::string& gameObjectName) const
{
    auto &go = m_scene.getGameObjectByName(gameObjectName);

    if (m_components.contains(go.id()))
        for (auto& [layer, id] : m_componentsLayers)
            if (m_components.at(id)->gameObjectName() == gameObjectName)
                return (layer);
    throw sw::Error("Component [" + gameObjectName + "] not found");
}

template<ClassComponent Cpt>
inline int sw::AManager<Cpt>::getLayer(const boost::uuids::uuid &gameObjectId) const
{
    if (m_components.contains(gameObjectId))
        for (auto& [layer, id] : m_componentsLayers)
            if (id == gameObjectId)
                return (layer);
    throw sw::Error("Component not found"); /// TODO add id in message
}

template<ClassComponent Cpt>
inline Cpt& sw::AManager<Cpt>::getComponent(const std::string& gameObjectName)
try
{
    auto &go = m_scene.getGameObjectByName(gameObjectName);

    return (*m_components.at(go.id()));
}
catch (std::out_of_range&) {
    throw sw::Error("Component not found"); // TODO add GameObject name
}

template<ClassComponent Cpt>
void sw::AManager<Cpt>::eraseComponents()
{
    for (auto& [id, _] : m_components)
        deleteComponent(id);
}

template<ClassComponent Cpt>
void sw::AManager<Cpt>::deleteRequestedComponents()
{
    for (auto id : m_deleteComponent) {
        m_components.erase(id);
        for (auto& [layer, layerId] : m_componentsLayers)
            if (layerId == id) {
                m_componentsLayers.remove(std::pair<int, boost::uuids::uuid>(layer, id));
                break;
            }
    }
    m_deleteComponent.clear();
}