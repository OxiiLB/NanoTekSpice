/*
** EPITECH PROJECT, 2024
** nts.hpp
** File description:
** nts header
*/

#ifndef ACOMPONENT_HPP_
    #define ACOMPONENT_HPP_

    #include <iostream>
    #include <vector>
    #include "IComponent.hpp"

    namespace nts {
        class AComponent : virtual public nts::IComponent {
            public:
                // Constructor / Destructor
                AComponent();

                // Methods
                virtual void simulate(std::size_t tick) override;
                virtual nts::Tristate compute(std::size_t pin) override = 0;
                void setLink (std::size_t pin , nts::IComponent &other, std::size_t otherPin) override;
                std::pair<std::size_t, nts::IComponent *> getLink(std::size_t pin) const;

            protected:
                std::vector<std::pair<std::size_t, nts::IComponent *>> _links;
        };
    }

#endif /* !ACOMPONENT_HPP_ */
