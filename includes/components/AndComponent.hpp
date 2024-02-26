/*
** EPITECH PROJECT, 2024
** AndComponent.hpp
** File description:
** Header for AndComponent
*/

#include "../AComponent.hpp"

#ifndef ANDCOMPONENT_HPP_
    #define ANDCOMPONENT_HPP_


    namespace nts {
        class AndComponent : public nts::AComponent{
            public:
                AndComponent();
                ~AndComponent();

                nts::Tristate compute(std::size_t pin) override;

        };
    }

#endif /* !ANDCOMPONENT_HPP_ */
