/*
** EPITECH PROJECT, 2024
** FalseComponent.hpp
** File description:
** Header for false component
*/

#include "../AComponent.hpp"

#ifndef FALSECOMPONENT_HPP_
    #define FALSECOMPONENT_HPP_


    namespace nts {
        class FalseComponent : public nts::AComponent {
            public:
                FalseComponent();
                ~FalseComponent();

                nts::Tristate compute(std::size_t pin) override;
        };
    }

#endif /* !FALSECOMPONENT_HPP_ */
