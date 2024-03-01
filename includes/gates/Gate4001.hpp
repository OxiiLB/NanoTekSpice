/*
** EPITECH PROJECT, 2024
** Gate4001.hpp
** File description:
** Gate4001.hpp
*/

#ifndef Gate4001_HPP_
    #define Gate4001_HPP_

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

#endif /* !Gate4001_HPP_ */
