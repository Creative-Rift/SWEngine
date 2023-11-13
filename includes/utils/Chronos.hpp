/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: Chrono.hpp
*/

#ifndef SHIPWRECK_ENGINE_CHRONOS_HPP
#define SHIPWRECK_ENGINE_CHRONOS_HPP

#include <chrono>

namespace sw {

    class Chronos {

    public:
        enum State {
            Wait, Lauch
        };

        /// @brief Default @c Constructor of a @b Chrono.
        /// You can define the constructor status, whether or not it should
        /// be run when created.
        ///
        /// @param state 'Lauch' if you want to start the chrono directly after
        /// have been created, 'Wait' otherwise.
        explicit Chronos(State state = Wait);

        /// @brief Default @c Destructor of a @b Chrono.
        ~Chronos() = default;

        /// @brief Start the @b Chrono.
        void start();

        /// @brief Stop the @b Chrono. Then, if you try get the time, it will
        /// not change.
        void stop();

        /// @brief Make a checkpoint. Then, you can either get the time since
        /// the start or the last checkpoint.
        void tour();

        /// @brief Get the time since the last checkpoint (call to the tour function).
        ///
        /// @return The time in second.
        double getElapsedTime() const;

        /// @brief Get the time since the start of the @b Chrono
        /// (call to the start function).
        ///
        /// @return The time in second.
        double getTotalTime() const;

        /// @brief Get the status of the @b Chrono.
        ///
        /// @return True if it is running, false otherwise.
        [[nodiscard]] bool isRunning() const;

    private:
        /// @brief The start time point of a @b Chrono.
        /// It is set at all call to the start method.
        std::chrono::time_point <std::chrono::steady_clock> m_start;

        /// @brief The tour time point of a @b Chrono.
        /// It is set at all call to the tour method.
        std::chrono::time_point <std::chrono::steady_clock> m_tour;

        /// @brief The last time point of a @b Chrono. It is corresponding to
        /// either the current time or the time you stoped or paused the @b Chrono.
        /// It is set when the time is get.
        mutable std::chrono::time_point <std::chrono::steady_clock> m_end;

        /// @brief The status of the chrono.
        /// If it is true, the chrono is running. If it is false, the chrono
        /// is either paused or stoped.
        bool m_isRunning;

    }; // class Chronos

#include "Chronos.inl"

} // SW

#endif //SHIPWRECK_ENGINE_CHRONOS_HPP
