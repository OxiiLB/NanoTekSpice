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
            void addComponent(std::string type, nts::IComponent *component);
            nts::IComponent *getComponent(std::string name);

        // Getters & Setters
            int getTick();
            void setTick(int tick);

        // Variables
        protected:
            std::map<std::string, nts::IComponent *> _components;
            int _tick;
    };

#endif /* !CIRCUIT_HPP_ */
