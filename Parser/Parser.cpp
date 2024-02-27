/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-alea.chlodnik
** File description:
** Parser
*/

#include "../ErrorHandling/ErrorHandling.hpp"
#include "../FileHandling/FileHandling.hpp"
#include "../Tools/BasicTools.hpp"
#include "Parser.hpp"

static int get_section_size(const std::string &file_str, const char *section)
{
    int size = 0;
    std::size_t position = file_str.find(section);
    if (position == std::string::npos)
        throw nts::InvalidSectionFormatException();
    int pos = (int)(position);
    for (pos = pos; file_str[pos] != '\n'; pos++);
    pos++;
    for (pos = pos; (file_str[pos] != '.' && file_str[pos + 1] != 'l') && file_str[pos] != '\0'; pos++) {
        if (file_str[pos] == '\n')
            size++;
        if (file_str[pos + 1] == '\0')
            break;
    }
    return size;
}

static char **get_array(const std::string &file_str, const char *section) {
    int i = 0;
    int j = 0;
    int size = get_section_size(file_str, section);
    char **array = (char **)malloc(sizeof(char *) * (size + 1));
    if (!array)
        throw std::runtime_error("Malloc failed");
    std::size_t position = file_str.find(section);
    if (position == std::string::npos)
        throw nts::InvalidSectionFormatException();
    int pos = (int)(position);
    for (pos = pos; file_str[pos] != '\n'; pos++);
    pos++;
    for (pos = pos; (file_str[pos] != '.' && file_str[pos + 1] != 'l') && file_str[pos] != '\0'; pos++) {
        array[i] = (char *)malloc(sizeof(char) * 100);
        if (!array[i])
            throw std::runtime_error("Malloc failed");
        j = 0;
        while (file_str[pos] != '\n' && file_str[pos] != '#' && file_str[pos] != '\0') {
            array[i][j++] = file_str[pos++];
        }
        array[i][j] = '\0';
        if (file_str[pos] == '\n' || file_str[pos] == '#') {
            i++;
        }
        if (file_str[pos] == '\0')
            throw nts::InvalidSectionFormatException();
        if (file_str[pos + 1] == '\0')
            break;
    }
    array[i] = NULL;
    return array;
}


void display_array(char **array) //////////////////////////////////
{
    for (int i = 0; array[i] != NULL; i++) {
        printf("%s\n", array[i]);
    }
}

void parse_file(const std::string &file_name)
{
    std::string file_str = nts::get_file_content(file_name);
    if (file_str.empty())
        throw std::runtime_error("File not found");

    char **chipsets = get_array(file_str, ".chipsets:");
    if (!chipsets)
        throw std::runtime_error("Failed to get chipsets");

    char **links = get_array(file_str, ".links:");
    if (!links)
        throw std::runtime_error("Failed to get links");

    //display_array(chipsets); //////////////////////////////////
    //display_array(links); //////////////////////////////////
}
