/*
** EPITECH PROJECT, 2024
** Gate4011.hpp
** File description:
** Gate4011
*/

#ifndef GATE4011_HPP_
    #define GATE4011_HPP_

    #include "../AComponent.hpp"

    namespace nts {
        class Nand : virtual public nts::AComponent{
            public:
                Nand();
                ~Nand();

                nts::Tristate compute(std::size_t pin) override;
            protected:

        };
    }

#endif /* !GATE4011_HPP_ */
