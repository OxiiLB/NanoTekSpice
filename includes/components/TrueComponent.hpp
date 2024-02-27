/*
** EPITECH PROJECT, 2024
** TrueComponent.hpp
** File description:
** Header for false component
*/


#ifndef TRUECOMPONENT_HPP_
    #define TRUECOMPONENT_HPP_

    #include "../AComponent.hpp"

    namespace nts {
        class TrueComponent : virtual public nts::AComponent {
            public:
                TrueComponent();
                ~TrueComponent();

                nts::Tristate compute(std::size_t pin) override;
        };
    }

#endif /* !TRUECOMPONENT_HPP_ */
