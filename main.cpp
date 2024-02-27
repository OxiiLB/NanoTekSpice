/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-alea.chlodnik
** File description:
** main
*/

#include <iostream>
#include "ErrorHandling/ErrorHandling.hpp"
#include "FileHandling/FileHandling.hpp"
#include "Parser/Parser.hpp"

int main(int ac, char **av)
{
    try {
        if (ac < 2) {
            throw nts::NoFileException();
        } else {
            check_config_file(av[1]);
            // check_command_line();
        }
        parse_file(av[1]);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }

    return 0;
}