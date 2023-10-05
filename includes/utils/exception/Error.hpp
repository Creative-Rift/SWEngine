/*
** ShipWreck Engine v0.1, graphical library made to create games
** Current file: Error.hpp
*/

#ifndef SHIPWRECK_ENGINE_ERROR_HPP
#define SHIPWRECK_ENGINE_ERROR_HPP

#include <stdexcept>

namespace sw
{

    class Error : public std::exception
    {

        protected:
            /// @brief The message of the @b Error. It contains more indication
            /// about the occuring @b Error.
            //
            const std::string m_message;
            ///

        public:
            Error() = delete;
            Error(Error &&) = delete;
            Error& operator=(Error const &) = delete;
            Error& operator=(Error&&) = delete;

            /// @brief Default @c Constructor of an @b Error.
            ///
            /// @param message The message transfered by the @b Error.
            /// @param code The unique code of the @b Error.
            //
            explicit Error(const std::string&& message);
            ///

            /// @brief Other @c Constructor of an @b Error. The message and
            /// the code of the given error are use to create the new one.
            ///
            /// @param other The error to copy.
            //
            Error(const Error& other);
            ///

            /// @brief Default @c Destructor of an @b Entity.
            //
            ~Error() override = default;
            ///

            /// @brief Return the message of the @b Error.
            ///
            /// @return The @b Error message.
            //
            [[nodiscard]] const std::string& getMessage() const;
            ///

            /// @brief Return the message of the @b Error.
            ///
            /// @return The @b Error message.
            //
            [[nodiscard]] const char* what() const noexcept override;
            ///

    }; // class Error

    #include "Error.inl"

} // sw

#endif // SHIPWRECK_ENGINE_ERROR_HPP
