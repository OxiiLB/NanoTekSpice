/*
** EPITECH PROJECT, 2024
** OutputComponent
** File description:
** OutputComponent
*/


#ifndef OUTPUTCOMPONENT_HPP_
    #define OUTPUTCOMPONENT_HPP_

    #include "../AComponent.hpp"

    namespace nts {
        class OutputComponent : virtual public nts::AComponent {
            public:
                OutputComponent();
                ~OutputComponent();

                nts::Tristate compute(std::size_t pin) override;
        };
    }

#endif /* !OUTPUTCOMPONENT_HPP_ */
