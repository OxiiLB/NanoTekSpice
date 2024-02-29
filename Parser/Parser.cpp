/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-alea.chlodnik
** File description:
** Parser
*/

#include "../ErrorHandling/ErrorHandling.hpp"
#include "../FileHandling/FileHandling.hpp"
#include "../Tools/BasicTools.hpp"
#include "../includes/AComponent.hpp"
#include "../includes/components/AndComponent.hpp"
#include "../includes/components/ClockComponent.hpp"
#include "../includes/components/FalseComponent.hpp"
#include "../includes/components/InputComponent.hpp"
#include "../includes/components/NotComponent.hpp"
#include "../includes/components/OrComponent.hpp"
#include "../includes/components/OutputComponent.hpp"
#include "../includes/components/TrueComponent.hpp"
#include "../includes/components/XorComponent.hpp"
#include "../includes/ComponentFactory.hpp"
#include "Parser.hpp"

class Circuit;

static int get_section_size(const std::string &file_str, const char *section)
{
    int size = 0;
    std::size_t position = file_str.find(section);
    if (position == std::string::npos)
        throw nts::InvalidSectionFormatException();
    int pos = (int)(position);
    for (pos = pos; file_str[pos] != '\n'; pos++);
    pos++;
    for (pos = pos; file_str[pos] != '.' && file_str[pos] != '\0'; pos++) {
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
    for (pos = pos; file_str[pos] != '.' && file_str[pos] != '\0'; pos++) {
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

static int get_comp_type(char *str)
{
    int i = 0;
    for (i = 0; i < 21; i++) {
        if (strstr(str, comp_type_array[i]) != NULL)
            return i;
    }
    return -1;
}

static char *get_name(char *name, char *str)
{
    int i = 0;
    int j = 0;
    for (i = 0; str[i] != ' '; i++);
    i++;
    for (i = i; str[i] != '\0'; i++) {
        name[j] = str[i];
        j++;
    }
    name[j] = '\0';
    return name;
}

static std::string get_comp_name(char *str)
{
    int i = 0;
    std::string name;
    for (i = 0; str[i] != ' '; i++);
    i++;
    for (i = i; str[i] != ':'; i++) {
        name += str[i];
    }
    return name;
}

static std::size_t get_comp_pin_num(char *str)
{
    int i = 0;
    int res = 0;
    for (i = 0; str[i] != ' '; i++);
    for (i = i; str[i] != ':'; i++);
    i++;
    res = (str[i] - '0');
    return ((std::size_t)(res));
}

static std::string get_other_name(char *str)
{
    int i = 0;
    std::string name;
    for (i = 0; str[i] != ':'; i++) {
        name += str[i];
    }
    return name;
}

static std::size_t get_other_pin_num(char *str)
{
    int i = 0;
    for (i = 0; str[i] != ':'; i++);
    i++;
    return ((std::size_t)(str[i]));
}

static int check_in_out(char **chipsets, std::string name)
{
    for (int i = 0; chipsets[i] != NULL; i++) {
        if (strstr(chipsets[i], name.c_str()) != NULL) {
            if (strstr(chipsets[i], "input") != NULL)
                return 1;
            if (strstr(chipsets[i], "output") != NULL)
                return 0;
        }
    }
    return -1;
}

void fill_circuit(Circuit &circuit, char **chipsets, char **links)
{
    int i = 0;
    int j = 0;
    std::size_t comp_pin = 0;
    std::size_t other_pin = 0;
    std::string comp;
    std::string other;
    nts::ComponentFactory factory;
    for (i = 0; chipsets[i + 1] != NULL; i++) {
        char *comp_name = (char *)malloc(sizeof(char) * 20);
        j = get_comp_type(chipsets[i]);
        comp_name = get_name(comp_name, chipsets[i]);
        std::unique_ptr<nts::IComponent> comp = factory.createComponent(comp_type_array[j - 1]);
        circuit.addComponent(comp_name, comp);
        comp_name = NULL;
        free(comp_name);
    }
    for (i = 0; links[i] != NULL; i++) {
        comp = get_comp_name(links[i]);
        comp_pin = get_comp_pin_num(links[i]);
        other = get_other_name(links[i]);
        other_pin = get_other_pin_num(links[i]);
        if (check_in_out(chipsets, other) == 1) {
           circuit.getComponent(comp)->setLink(comp_pin, *(circuit.getComponent(other)), other_pin);
        } else if (check_in_out(chipsets, other) == 0) {
           circuit.getComponent(other)->setLink(other_pin, *(circuit.getComponent(comp)), comp_pin);
        } else {
           throw std::runtime_error("error in link loop fill circuit"); ////////////////////////
        }
    }
}

void parse_file(Circuit &circuit, const std::string &file_name)
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

    fill_circuit(circuit, chipsets, links);

    free_2d_array(chipsets);
    free_2d_array(links);
}
