/*
** EPITECH PROJECT, 2024
** FalseComponent.hpp
** File description:
** Header for false component
*/


#ifndef FALSECOMPONENT_HPP_
    #define FALSECOMPONENT_HPP_

    #include "../AComponent.hpp"

    namespace nts {
        class FalseComponent : virtual public nts::AComponent {
            public:
                FalseComponent();
                ~FalseComponent();

                nts::Tristate compute(std::size_t pin) override;
        };
    }

#endif /* !FALSECOMPONENT_HPP_ */
