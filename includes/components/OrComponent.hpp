/*
** EPITECH PROJECT, 2024
** OrComponent.hpp
** File description:
** OrComponent
*/

#ifndef ORCOMPONENT_HPP_
    #define ORCOMPONENT_HPP_
    
    #include "../AComponent.hpp"

    namespace nts {
        class OrComponent : virtual public nts::AComponent{
        public:
            OrComponent();
            ~OrComponent();

            nts::Tristate compute(std::size_t pin) override;

        };
    }

#endif /* !ORCOMPONENT_HPP_ */
