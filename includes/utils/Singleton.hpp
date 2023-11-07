/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: Singleton.hpp
*/

#ifndef SHIPWRECK_ENGINE_SINGLETON_HPP
#define SHIPWRECK_ENGINE_SINGLETON_HPP

#include <mutex>

namespace sw {
    template <typename T>
    class Singleton {
        private:
            static T *m_instance;
            static std::mutex m_mutex;

        protected:
            Singleton() = default;

            ~Singleton() = default;

        public:
            /// Singletons should not be cloneable.
            Singleton(Singleton &other) = delete;

            ///Singletons should not be assignable.
            void operator=(const Singleton &) = delete;

            /**
             * This is the static method that controls the access to the singleton
             * instance. On the first run, it creates a singleton object and places it
             * into the static field. On subsequent runs, it returns the client existing
             * object stored in the static field.
             */
            static T *GetInstance();
    };

#include "Singleton.inl"
} // SW

#endif //SHIPWRECK_ENGINE_SINGLETON_HPP
