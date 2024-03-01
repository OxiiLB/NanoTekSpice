/*
** EPITECH PROJECT, 2024
** Circuit.cpp
** File description:
** Circuit class
*/

#include <iostream>
#include <memory>
#include <map>
#include "IComponent.hpp"

#ifndef CIRCUIT_HPP_
    #define CIRCUIT_HPP_

    class Circuit : virtual public nts::IComponent{
        public:
            Circuit();
            ~Circuit();

        // Methods
        public:
            void simulate();
            void display();
            void addComponent(std::string name, std::unique_ptr<nts::IComponent> &component);
            nts::IComponent *getComponent(std::string name);
            void simulate(std::size_t tick);
            nts::Tristate compute(std::size_t pin);
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
            std::pair<std::size_t, nts::IComponent *> getLink(std::size_t pin) const;

        // Getters & Setters
            int getTick();
            void setTick(int tick);

        // Variables
        protected:
            std::map<std::string, std::unique_ptr<nts::IComponent>> _components;
            int _tick;
    };

#endif /* !CIRCUIT_HPP_ */
