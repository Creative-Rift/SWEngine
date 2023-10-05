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
            /// @brief The message of the Error
            const std::string m_message;

        public:
            Error() = delete;
            Error(Error &&) = delete;
            Error& operator=(Error const &) = delete;
            Error& operator=(Error&&) = delete;

            /// @brief Default Constructor
            ///
            /// @param message The message
            explicit Error(const std::string&& message);

            /// @brief Copy constructor
            ///
            /// @param other The error to copy
            Error(const Error& other);

            /// @brief Default Destructor
            ~Error() override = default;

            /// @brief Return the message
            ///
            /// @return The Error message
            [[nodiscard]] const std::string& getMessage() const;

            /// @brief Return the message
            ///
            /// @return The Error message
            [[nodiscard]] const char* what() const noexcept override;

    }; // class Error

    #include "Error.inl"

} // sw

#endif // SHIPWRECK_ENGINE_ERROR_HPP
