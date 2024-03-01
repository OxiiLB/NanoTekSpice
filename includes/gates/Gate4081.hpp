/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Gate4081
*/

#ifndef GATE4081_HPP_
    #define GATE4081_HPP_

    #include "../AComponent.hpp"

    namespace nts {
        class And4 : virtual public nts::AComponent {
            public:
                And4();
                ~And4();

                nts::Tristate compute(std::size_t pin) override;
            protected:

        };
    }

#endif /* !GATE4081_HPP_ */
