/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: Singleton.hpp
*/

#ifndef SHIPWRECK_ENGINE_SINGLETON_HPP
#define SHIPWRECK_ENGINE_SINGLETON_HPP

#include <mutex>

namespace sw {
    template<typename T>
    class Singleton {
        private:
            static T *m_instance;
            static std::mutex m_mutex;

        protected:
            /// @brief Default constructor
            Singleton() = default;

            /// @brief Default destructor
            ~Singleton() = default;

        public:
            /// Singletons should not be cloneable.
            Singleton(Singleton &other) = delete;

            ///Singletons should not be assignable.
            void operator=(const Singleton &) = delete;

            /// @brief Return the instance of the singleton.
            /// Create the singleton on the first call of this function.
            ///
            /// \return Type of the Singleton
            static T *GetInstance();
    };

#include "Singleton.inl"

} // SW

#endif //SHIPWRECK_ENGINE_SINGLETON_HPP
