/*
** EPITECH PROJECT, 2024
** Prompt.cpp
** File description:
** prompt
*/

#include "../includes/prompt.hpp"
#include "../includes/Circuit.hpp"
#include "../includes/components/InputComponent.hpp"
#include "../includes/components/ClockComponent.hpp"
#include "../ErrorHandling/ErrorHandling.hpp"
#include <csignal>

bool ISLOOPING;

prompt::prompt()
{
    this->_exit = false;
}

prompt::~prompt()
{
}

void prompt::exit()
{
    this->_exit = true;
}


std::pair<std::string, nts::Tristate> prompt::parse_input(std::string input)
{
    std::size_t pos = input.find("=");
    if (pos == std::string::npos)
        throw nts::InvalidCommandException();
    std::string name = input.substr(0, pos);
    // check if input name exists !!!
    std::string value = input.substr(pos + 1);
    if (value == "0")
        return std::make_pair(name, nts::Tristate::False);
    else if (value == "1")
        return std::make_pair(name, nts::Tristate::True);
    else if (value == "U")
        return std::make_pair(name, nts::Tristate::Undefined);
    else
        throw nts::InvalidValueException();
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
        ISLOOPING = true;
    else {
        try {
            std::pair pair = this->parse_input(this->_input);
            nts::InputComponent *inputComp = dynamic_cast<nts::InputComponent *>(circuit.getComponent(pair.first));
            nts::ClockComponent *clockComp = dynamic_cast<nts::ClockComponent *>(circuit.getComponent(pair.first));
            if (inputComp != nullptr) {
                inputComp->setValue(pair.second);
            } else if (clockComp != nullptr) {
                clockComp->setValue(pair.second);
            } else {
                std::cerr << "Component " << pair.first << " is not an input" << std::endl;
            }
        } catch(const std::exception& e) {
            std::cerr << e.what() << '\n';
        }
    }
}

void signalHandler(int signum)
{
    if (signum == SIGINT) {
        ISLOOPING = false;
    }
}

void prompt::loop(Circuit &circuit)
{
    signal(SIGINT, signalHandler);
    while (ISLOOPING == true) {
        if (this->_input == "display" || this->_input == "loop") {
            this->_input = "simulate";
        } else {
            this->_input = "display";
        }
        this->launch_command(circuit);
    }
}

void prompt::run(Circuit &circuit)
{
    while (this->_exit != true) {
        this->loop(circuit);
        std::cout << "> ";
        if (!std::getline(std::cin, this->_input) && std::cin.eof())
            break;
        this->launch_command(circuit);
    }
}
