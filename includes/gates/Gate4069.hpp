/*
** EPITECH PROJECT, 2024
** Gate4069
** File description:
** Gate4069
*/

#ifndef GATE4069_HPP_
    #define GATE4069_HPP_

    #include "../AComponent.hpp"

    namespace nts {
        class Inverter : virtual public nts::AComponent{
            public:
                Inverter();
                ~Inverter();

                nts::Tristate compute(std::size_t pin) override;
            protected:
        };
    }

#endif /* !GATE4069_HPP_ */
