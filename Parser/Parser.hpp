/*
** EPITECH PROJECT, 2024
** '
** File description:
** Parser
*/

#ifndef PARSER_HPP_
    #define PARSER_HPP_

    #include <string>
    #include <strings.h>
    #include <stdlib.h>
    #include <cstring>
    #include <vector>
    #include <iostream>
    #include "../includes/Circuit.hpp"

    static const int array_size = 15;

    static char comp_type_name_array[array_size][10] = {
        "clock", "and", "xor", "or", "not", "input",
        "output", "false", "true", "4001", "4011",
        "4030", "4069", "4071", "4081"
    };

    static char comp_type_array[array_size][10] = {
        "clock", "and", "xor", "or", "not", "input",
        "output", "false", "true", "nor", "nand",
        "xor4", "inverter", "or4", "and4"
    };

void check_config_file(const std::string &file_name);
int parse_file(Circuit &circuit, const std::string &file_name);

#endif /* !PARSER_HPP_ */
