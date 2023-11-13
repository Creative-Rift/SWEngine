/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: Chronos.inl
*/

inline sw::Chronos::Chronos(State state) :
    m_isRunning(false)
{
    if (state == Lauch) {
        m_isRunning = true;
        start();
    }
}

inline void sw::Chronos::start()
{
    m_start = std::chrono::steady_clock::now();
    m_end = m_start;
    m_tour = m_start;
    m_isRunning = true;
}

inline void sw::Chronos::stop()
{
    m_end = std::chrono::steady_clock::now();
    m_isRunning = false;
}

inline void sw::Chronos::tour()
{
    m_tour = std::chrono::steady_clock::now();
}

inline double sw::Chronos::getElapsedTime() const
{
    if (m_isRunning)
        m_end = std::chrono::steady_clock::now();
    double step = (double)std::chrono::duration_cast<std::chrono::milliseconds>(m_end - m_tour).count();
    return (step / 1000);
}

inline double sw::Chronos::getTotalTime() const
{
    if (m_isRunning)
        m_end = std::chrono::steady_clock::now();
    double step = (double)std::chrono::duration_cast<std::chrono::milliseconds>(m_end - m_start).count();
    return (step / 1000);
}

inline bool sw::Chronos::isRunning() const
{
    return (m_isRunning);
}