/*
** EPITECH PROJECT, 2024
** NotComponent.hpp
** File description:
** Header for NotComponent
*/


#ifndef NOTCOMPONENT_HPP_
    #define NOTCOMPONENT_HPP_

    #include "../AComponent.hpp"

    namespace nts {
        class NotComponent : virtual public nts::AComponent{
            public:
                NotComponent();
                ~NotComponent();

                nts::Tristate compute(std::size_t pin) override;

        };
    }

#endif /* !NOTCOMPONENT_HPP_ */
