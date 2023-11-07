/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: Singleton.inl
*/

template <typename T>
T* sw::Singleton<T>::m_instance{nullptr};
template <typename T>
std::mutex sw::Singleton<T>::m_mutex{};

template <typename T>
inline T *Singleton<T>::GetInstance()
{
    std::lock_guard<std::mutex> lock(m_mutex);
    if (m_instance == nullptr)
        m_instance = new T();
    return m_instance;
}
