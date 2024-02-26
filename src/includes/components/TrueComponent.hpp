/*
** EPITECH PROJECT, 2024
** TrueComponent.hpp
** File description:
** Header for false component
*/

#include "../AComponent.hpp"

#ifndef TRUECOMPONENT_HPP_
    #define TRUECOMPONENT_HPP_

    namespace nts {
        class TrueComponent : public nts::AComponent {
            public:
                TrueComponent();
                ~TrueComponent();

                nts::Tristate compute(std::size_t pin) override;
        };
    }

#endif /* !TRUECOMPONENT_HPP_ */
