/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: Singleton.hpp
*/

#ifndef SHIPWRECK_ENGINE_SINGLETON_HPP
#define SHIPWRECK_ENGINE_SINGLETON_HPP

#include <mutex>

namespace sw {
    class Singleton {
        private:
            static Singleton *m_instance;
            static std::mutex mutex_;

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
            static Singleton *GetInstance();
    };
} // SW

#endif //SHIPWRECK_ENGINE_SINGLETON_HPP
