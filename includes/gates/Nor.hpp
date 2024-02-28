/*
** EPITECH PROJECT, 2024
** Nor.hpp
** File description:
** Nor.hpp
*/

#ifndef NOR_HPP_
    #define NOR_HPP_

    #include "../AComponent.hpp"

    namespace nts {
        class Nor : virtual public nts::AComponent{
            public:
                Nor();
                ~Nor();

                nts::Tristate compute(std::size_t pin) override;
            protected:
        };
    }

#endif /* !NOR_HPP_ */
