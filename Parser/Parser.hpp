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

    static char comp_type_array[8][10] = {
        "clock", "and", "or", "xor", "not", "input", "output"
    };

void check_config_file(const std::string &file_name);
void parse_file(Circuit &circuit, const std::string &file_name);

#endif /* !PARSER_HPP_ */
