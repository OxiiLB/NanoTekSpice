/*
** EPITECH PROJECT, 2024
** InputComponent
** File description:
** InputComponent
*/


#ifndef INPUTCOMPONENT_HPP_
    #define INPUTCOMPONENT_HPP_

    #include "../AComponent.hpp"

    namespace nts {
        class InputComponent : virtual public nts::AComponent{
            public:
                InputComponent();
                ~InputComponent();

                nts::Tristate compute(std::size_t pin) override;
                void simulate(std::size_t tick) override;
                void setValue(nts::Tristate value);

            protected:
                nts::Tristate _value;
                nts::Tristate _nextValue;
        };
    }

#endif /* !INPUTCOMPONENT_HPP_ */
