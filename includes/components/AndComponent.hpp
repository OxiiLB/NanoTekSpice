/*
** EPITECH PROJECT, 2024
** AndComponent.hpp
** File description:
** Header for AndComponent
*/


#ifndef ANDCOMPONENT_HPP_
    #define ANDCOMPONENT_HPP_

    #include "../AComponent.hpp"

    namespace nts {
        class AndComponent : virtual public nts::AComponent{
            public:
                AndComponent();
                ~AndComponent();

                nts::Tristate compute(std::size_t pin) override;
        };
    }

#endif /* !ANDCOMPONENT_HPP_ */
