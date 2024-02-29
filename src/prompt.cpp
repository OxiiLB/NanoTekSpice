/*
** EPITECH PROJECT, 2024
** Prompt.cpp
** File description:
** prompt
*/

#include "../includes/prompt.hpp"
#include "../includes/Circuit.hpp"

prompt::prompt()
{
    this->_exit = false;
    this->_isLooping = false;
}

prompt::~prompt()
{
}

void prompt::exit()
{
        this->_exit = true;
}

void prompt::launch_command(Circuit &circuit)
{
    if (this->_input == "display")
        circuit.display();
    else if (this->_input == "simulate")
        circuit.simulate();
    else if (this->_input == "exit")
        this->exit();
    else if (this->_input == "loop")
        this->_isLooping = true;
}


void prompt::run(Circuit &circuit)
{
    while (this->_exit != true) {
        std::cout << "> ";
        if (this->_isLooping == true) {
            if (this->_input == "display" || this->_input == "loop") {
                this->_input = "simulate";
            } else {
                this->_input = "display";
            }
        } else if (!std::getline(std::cin, this->_input) && std::cin.eof()) {
            this->exit();
        }
        this->launch_command(circuit);
    }
}
