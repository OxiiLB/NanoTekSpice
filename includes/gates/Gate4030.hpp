/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Gate4030
*/

#ifndef GATE4030_HPP_
    #define GATE4030_HPP_

    #include "../AComponent.hpp"

    namespace nts {
        class Xor4 : virtual public nts::AComponent {
            public:
                Xor4();
                ~Xor4();

                nts::Tristate compute(std::size_t pin) override;
            protected:

        };
    }

#endif /* !GATE4030_HPP_ */
