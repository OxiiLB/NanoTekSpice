/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-alea.chlodnik
** File description:
** FileHandling
*/

#include "FileHandling.hpp"

std::string nts::get_file_content(const std::string &file_name)
{
    std::ifstream file(file_name);

    if (!file.is_open())
        return "";

    std::string file_content;
    std::string line;

    while (std::getline(file, line)) {
        file_content += line + "\n";
    }

    file.close();

    return file_content;
}
