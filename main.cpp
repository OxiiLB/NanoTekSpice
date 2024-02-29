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
#include "includes/prompt.hpp"

int main (int ac, char **av)
{
    Circuit circuit;
    prompt prompt;
    try {
        if (ac < 2) {
            throw nts::NoFileException();
        } else {
            check_config_file(av[1]);
            // check_command_line();
        }
        parse_file(circuit, av[1]);
        prompt.run(circuit);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}

