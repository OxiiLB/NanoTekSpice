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
                virtual void simulate(std::size_t tick) override;

            // Value
            protected:
                nts::Tristate _value;
        };
    }

#endif /* !CLOCKCOMPONENT_HPP_ */
