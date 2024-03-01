/*
** EPITECH PROJECT, 2024
** nts.hpp
** File description:
** nts header
*/

#ifndef ICOMPONENT_HPP_
    #define ICOMPONENT_HPP_

    #include <iostream>

    namespace nts {
        enum Tristate {
            Undefined = (-true),
            True = true,
            False = false
        };

        class IComponent {
            public :
                // Constructor / Destructor
                virtual ~IComponent() = default;

                // Methods
                virtual void simulate(std::size_t tick) = 0;
                virtual nts::Tristate compute(std::size_t pin) = 0;
                virtual void setLink (std::size_t pin , nts::IComponent &other, std::size_t otherPin) = 0;
                virtual std::pair<std::size_t, nts::IComponent *> getLink(std::size_t pin) const = 0;
        };
    }

#endif /* !ICOMPONENT _HPP_ */
