/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: Chrono.inl
*/

inline sw::Chrono::Chrono(State state) :
    m_isRunning(false)
{
    if (state == LAUNCH) {
        m_isRunning = true;
        start();
    }
}

inline void sw::Chrono::start()
{
    m_start = std::chrono::steady_clock::now();
    m_end = m_start;
    m_tour = m_start;
    m_isRunning = true;
}

inline void sw::Chrono::stop()
{
    m_end = std::chrono::steady_clock::now();
    m_isRunning = false;
}

inline void sw::Chrono::tour()
{
    m_tour = std::chrono::steady_clock::now();
}

inline double sw::Chrono::getElapsedTime() const
{
    if (m_isRunning)
        m_end = std::chrono::steady_clock::now();
    double step = (double)std::chrono::duration_cast<std::chrono::milliseconds>(m_end - m_tour).count();
    return (step / 1000);
}

inline double sw::Chrono::getTotalTime() const
{
    if (m_isRunning)
        m_end = std::chrono::steady_clock::now();
    double step = (double)std::chrono::duration_cast<std::chrono::milliseconds>(m_end - m_start).count();
    return (step / 1000);
}

inline bool sw::Chrono::isRunning() const
{
    return (m_isRunning);
}