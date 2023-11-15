/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: chrono.hpp
*/

#ifndef SHIPWRECK_ENGINE_CHRONO_HPP
#define SHIPWRECK_ENGINE_CHRONO_HPP

#include <chrono>

namespace sw {

    class Chrono {

    public:
        enum State {
            WAIT, LAUNCH
        };

        /// @brief Default Constructor
        /// You can define the constructor status, whether or not it should
        /// be run when created.
        ///
        /// @param state 'LAUNCH' if you want to start the chrono directly after
        /// have been created, 'WAIT' otherwise.
        explicit Chrono(State state = WAIT);

        /// @brief Default Destructor of a chrono.
        ~Chrono() = default;

        /// @brief Start the chrono.
        void start();

        /// @brief Stop the chrono.
        void stop();

        /// @brief Make a checkpoint. Then, you can either get the time since
        /// the start or the last checkpoint.
        void tour();

        /// @brief Get the time since the last checkpoint (call to the tour function).
        ///
        /// @return The time in second.
        double getElapsedTime() const;

        /// @brief Get the time since the start of the chrono (call to the start function).
        ///
        /// @return The time in second.
        double getTotalTime() const;

        /// @brief Get the status of the chrono.
        ///
        /// @return True if it is running, false otherwise.
        [[nodiscard]] bool isRunning() const;

    private:
        /// @brief The start time point of a chrono.
        /// It is set at all call to the start method.
        std::chrono::time_point <std::chrono::steady_clock> m_start;

        /// @brief The tour time point of a chrono.
        /// It is set at all call to the tour method.
        std::chrono::time_point <std::chrono::steady_clock> m_tour;

        /// @brief The last time point of a chrono. It is corresponding to
        /// either the current time or the time you stoped or paused the chrono.
        /// It is set when the time is get.
        mutable std::chrono::time_point <std::chrono::steady_clock> m_end;

        /// @brief The status of the chrono.
        /// If it is true, the chrono is running. If it is false, the chrono
        /// is either paused or stopped.
        bool m_isRunning;

    }; // class Chrono

#include "Chrono.inl"

} // SW

#endif //SHIPWRECK_ENGINE_CHRONO_HPP
