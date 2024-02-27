/*
** EPITECH PROJECT, 2024
** XorComponent
** File description:
** XorComponent
*/

#ifndef XORCOMPONENT_HPP_
    #define XORCOMPONENT_HPP_

    #include "../AComponent.hpp"

    namespace nts {
        class XorComponent : virtual public nts::AComponent {
            public:
                XorComponent();
                ~XorComponent();

                nts::Tristate compute(std::size_t pin);

            protected:
        };
    }

#endif /* !XORCOMPONENT_HPP_ */
