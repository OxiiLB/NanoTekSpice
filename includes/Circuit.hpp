/*
** EPITECH PROJECT, 2024
** Circuit.cpp
** File description:
** Circuit class
*/

#include <iostream>
#include <vector>
#include <memory>
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
            void setInput(std::string name, nts::Tristate value);
            void setLink(std::string name, int pin, std::string to, int toPin);
            void addComponent(std::string type, std::string name);
        // Variables
        private:
            std::vector<std::unique_ptr<nts::IComponent>> _outputs;
            std::vector<std::unique_ptr<nts::IComponent>> _inputs;
    };

#endif /* !CIRCUIT_HPP_ */
