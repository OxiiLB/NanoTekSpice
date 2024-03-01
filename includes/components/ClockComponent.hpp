/*
** EPITECH PROJECT, 2024
** ClockComponent
** File description:
** ClockComponent
*/


#ifndef CLOCKCOMPONENT_HPP_
    #define CLOCKCOMPONENT_HPP_

    #include "../AComponent.hpp"

    namespace nts {
        class ClockComponent : virtual public nts::AComponent{
            public:
                ClockComponent();
                ~ClockComponent();

                nts::Tristate compute(std::size_t pin) override;
                void simulate(std::size_t tick) override;
                void setValue(nts::Tristate value);

            // Value
            protected:
                nts::Tristate _value;
                nts::Tristate _nextValue;
        };
    }

#endif /* !CLOCKCOMPONENT_HPP_ */
