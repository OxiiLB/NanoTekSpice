/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-alea.chlodnik
** File description:
** CheckFile
*/

#include "../FileHandling/FileHandling.hpp"
#include "../ErrorHandling/ErrorHandling.hpp"
#include "Parser.hpp"

void check_config_file(const std::string &file_name)
{
    int c = 0;
    int l = 0;
    std::string file = nts::get_file_content(file_name);
    if (file.empty())
        throw std::runtime_error("File not found");
    
    if (file.find(".chipsets:") == std::string::npos) {
        throw nts::NoChipsetSectionException();
    }
    if (file.find(".links:") == std::string::npos)
        throw nts::NoLinkSectionException();

    c = file.find(".chipsets:");

    if (file.find(".chipsets:", c + 1) != std::string::npos)
        throw nts::MultipleChipsetSectionException();

    if (file.find("output") == std::string::npos)
        throw nts::NoOutputException();

    l = file.find(".links:");

    if (file.find(".links:", l + 1) != std::string::npos)
        throw nts::MultipleLinkSectionException();
}
