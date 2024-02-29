/*
** EPITECH PROJECT, 2024
** Prompt.cpp
** File description:
** prompt
*/

#include "../includes/prompt.hpp"
#include "../includes/Circuit.hpp"
#include "../includes/components/InputComponent.hpp"
#include "../ErrorHandling/ErrorHandling.hpp"

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

std::pair<std::string, std::size_t> prompt::parse_input(std::string input)
{
    std::size_t pos = input.find("=");
    if (pos == std::string::npos)
        throw nts::InvalidCommandException();
    std::string name = input.substr(0, pos);
    std::string value = input.substr(pos + 1);
    return std::make_pair(name, std::stoi(value));
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
    else {
        std::pair pair = this->parse_input(this->_input);
        // std::cout << "Setting " << pair.first << " to " << pair.second << std::endl;
        dynamic_cast<nts::InputComponent *>(circuit.getComponent(pair.first))->setValue(static_cast<nts::Tristate>(pair.second));
    }
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
