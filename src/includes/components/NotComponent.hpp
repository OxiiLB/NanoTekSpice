/*
** EPITECH PROJECT, 2024
** NotComponent.hpp
** File description:
** Header for NotComponent
*/

#include "../AComponent.hpp"

#ifndef NOTCOMPONENT_HPP_
    #define NOTCOMPONENT_HPP_

    namespace nts {
        class NotComponent : public nts::AComponent{
            public:
                NotComponent();
                ~NotComponent();

                nts::Tristate compute(std::size_t pin) override;

        };
    }

#endif /* !NOTCOMPONENT_HPP_ */
