/*
** EPITECH PROJECT, 2024
** Or4
** File description:
** Or4
*/

#ifndef GATE4071_HPP_
    #define GATE4071_HPP_

    #include "../AComponent.hpp"

    namespace nts {
        class Or4 : public nts::AComponent{
            public:
                Or4();
                ~Or4();

                nts::Tristate compute(std::size_t pin);
            protected:
        };
    }

#endif /* !GATE4071_HPP_ */
