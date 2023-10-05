/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: Error.inl
*/

inline sw::Error::Error(const std::string&& message) :
std::exception(),
m_message(message)
{}

inline sw::Error::Error(const sw::Error& other) :
std::exception(),
m_message(other.m_message)
{}

inline const std::string& sw::Error::getMessage() const
{
    return (m_message);
}

inline const char * sw::Error::what() const noexcept
{
    return (m_message.c_str());
}