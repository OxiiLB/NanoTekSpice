/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-alea.chlodnik
** File description:
** main
*/

#include <iostream>
#include "ErrorHandling/ErrorHandling.hpp"
#include "FileHandling/FileHandling.hpp"
#include "Tools/BasicTools.hpp"
#include "includes/AComponent.hpp"
#include "includes/Circuit.hpp"
#include "includes/components/AndComponent.hpp"
#include "includes/components/ClockComponent.hpp"
#include "includes/components/FalseComponent.hpp"
#include "includes/components/InputComponent.hpp"
#include "includes/components/NotComponent.hpp"
#include "includes/components/OrComponent.hpp"
#include "includes/components/OutputComponent.hpp"
#include "includes/components/TrueComponent.hpp"
#include "includes/components/XorComponent.hpp"
#include "includes/ComponentFactory.hpp"
#include "Parser/Parser.hpp"

int main (int ac, char **av)
{
    Circuit circuit;
    try {
        if (ac < 2) {
            throw nts::NoFileException();
        } else {
            check_config_file(av[1]);
            // check_command_line();
        }
        parse_file(circuit, av[1]);
        //circuit.display();
        //std::cout << "ok" << std::endl; /////////////////
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
}


        // nts::ComponentFactory factory;
        // auto TrueComp = factory.createComponent("True");
        // auto orGate = factory.createComponent("Or");
        // auto clock = factory.createComponent("Clock");

        // orGate->setLink(1, *clock, 1);
        // orGate->setLink(2, *TrueComp, 1);
        // std::cout << "!(" << clock->compute(1) << " && " << TrueComp->compute(1) << ") ->" << orGate->compute(3) << std::endl;
        // clock->simulate(1);
        // std::cout << "!(" << clock->compute(1) << " && " << TrueComp->compute(1) << ") ->" << orGate->compute(3) << std::endl;
        // clock->simulate(2);
        // std::cout << "!(" << clock->compute(1) << " && " << TrueComp->compute(1) << ") ->" << orGate->compute(3) << std::endl;

        // std::cout << std::endl << "--------------------------------CIRCUIT--------------------------------" << std::endl;

        // Circuit circuit;
        // circuit.addComponent("OrGate", orGate.get());
        // circuit.addComponent("Clock", clock.get());
        // circuit.addComponent("True", TrueComp.get());
        // circuit.display();
        // prompt prompt;
        // prompt.run();