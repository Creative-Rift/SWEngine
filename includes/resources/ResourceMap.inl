/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: ResourceMap.inl
*/

template<typename T>
inline std::shared_ptr <T> sw::ResourceMap<T>::operator[](std::string name)
{
    if (!this->contains(name)) {
        std::cerr << name << " texture not found" << std::endl;
        throw sw::Error(name + " model not found");
    }
    return (this->find(name)->second);
}

template<typename T>
inline std::shared_ptr <T> sw::ResourceMap<T>::operator[](std::string name) const
{
    if (!this->contains(name)) {
        std::cerr << name << " texture not found" << std::endl;
        throw sw::Error(name + " model not found");
    }
    return (this->find(name)->second);
}

template<typename T>
template <typename... Args>
inline void sw::ResourceMap<T>::createResource(std::string name, Args... args)
{
    this->try_emplace(name, args...);
}
