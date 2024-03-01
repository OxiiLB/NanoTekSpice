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

static void get_array(std::vector<std::string> &vector, const std::string &file_str, std::string section)
{
    std::size_t position = file_str.find(section);
    if (position == std::string::npos)
        throw nts::InvalidSectionFormatException();
    int pos = (int)(position);
    for (pos = pos; file_str[pos] != '\n'; pos++);
    pos++;
    for (pos = pos; file_str[pos] != '.' && file_str[pos] != '\0'; pos++) {
        std::string str;
        for (pos = pos; file_str[pos] != '\n' && file_str[pos] != '#' && file_str[pos] != '\0'; pos++) {
            str += file_str[pos];
        }
        vector.push_back(str);
        if (file_str[pos] == '\0')
            throw nts::InvalidSectionFormatException();
        if (file_str[pos + 1] == '\0')
            break;
        str.clear();
    }
}

static int get_comp_type(std::string str)
{
    int i = 0;
    for (i = 0; i < 9; i++) {
        if (str.find(comp_type_array[i]) != std::string::npos)
            return i;
    }
    return -1;
}

static std::string get_name(std::string name, std::string str)
{
    int i = 0;
    int j = 0;
    for (i = 0; str[i] != ' '; i++);
    i++;
    for (i = i; str[i] != '\0'; i++) {
        name += str[i];
        j++;
    }
    return name;
}

void check_if_name_repeated(std::vector<std::string> &chipsets, std::string comp_name)
{
    int i = 0;
    int count = 0;
    for (i = 0; i < chipsets.size(); i++) {
        if (chipsets[i] == comp_name)
            count++;
    }
    if (count > 1)
        throw nts::RepeatNameException();
}

static std::string get_comp_name(std::string str)
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

static std::size_t get_comp_pin_num(std::string str)
{
    int i = 0;
    int res = 0;
    for (i = 0; str[i] != ' '; i++);
    for (i = i; str[i] != ':'; i++);
    i++;
    if (str[i] < '0' || str[i] > '9')
        throw nts::ImproperLinkLineException();
    res = (str[i] - '0');
    return ((std::size_t)(res));
}

static std::string get_other_name(std::string str)
{
    int i = 0;
    std::string name;
    for (i = 0; str[i] != ':'; i++) {
        name += str[i];
    }
    return name;
}

static std::size_t get_other_pin_num(std::string str)
{
    int i = 0;
    int res = 0;
    for (i = 0; str[i] != ':'; i++);
    i++;
    res = (str[i] - '0');
    return ((std::size_t)(res));
}

static int check_in_out(std::vector<std::string> chipsets, std::string name)
{
    for (int i = 0; i < chipsets.size(); i++) {
        if (chipsets[i].find(name) != std::string::npos) {
            if (chipsets[i].find("clock") != std::string::npos)
                return 2;
            if (chipsets[i].find("input") != std::string::npos ||
                chipsets[i].find("true") != std::string::npos ||
                chipsets[i].find("false") != std::string::npos)
                return 1;
            if (chipsets[i].find("output") != std::string::npos)
                return 0;
        }
    }
    return -1;
}

void check_comp_name_exists(Circuit &circuit, std::string comp_n)
{
    if (circuit.getComponent(comp_n) == NULL)
        throw nts::InexistentComponentNameException();
}

void fill_circuit(Circuit &circuit, std::vector<std::string> &chipsets, std::vector<std::string> &links)
{
    int i = 0;
    int j = 0;
    std::size_t comp_pin = 0;
    std::size_t other_pin = 0;
    std::string comp_name;
    std::string other_name;
    nts::ComponentFactory factory;
    for (i = 0; i < (chipsets.size() - 1); i++) {
        j = get_comp_type(chipsets[i]);
        if (j == -1)
            throw nts::InvalidComponentException();
        comp_name = get_name(comp_name, chipsets[i]);
        check_if_name_repeated(chipsets, comp_name);
        std::unique_ptr<nts::IComponent> comp = factory.createComponent(comp_type_array[j]);
        circuit.addComponent(comp_name, comp);
        comp_name.clear();
    }
    comp_name.clear();
    for (i = 0; i < links.size(); i++) {
        comp_name = get_comp_name(links[i]);
        check_comp_name_exists(circuit, comp_name);
        comp_pin = get_comp_pin_num(links[i]);
        other_name = get_other_name(links[i]);
        other_pin = get_other_pin_num(links[i]);
        if (comp_name == other_name)
            throw nts::SelfLinkException();
        if (check_in_out(chipsets, other_name) == 1 || check_in_out(chipsets, other_name) == 2) {
           circuit.getComponent(comp_name)->setLink(comp_pin, *(circuit.getComponent(other_name)), other_pin);
        } else if (check_in_out(chipsets, other_name) == 0) {
           circuit.getComponent(other_name)->setLink(other_pin, *(circuit.getComponent(comp_name)), comp_pin);
        } else {
           throw std::runtime_error("Error in link loop in fill circuit");
        }
    }
}

void parse_file(Circuit &circuit, const std::string &file_name)
{
    std::string file_str = nts::get_file_content(file_name);
    if (file_str.empty())
        throw nts::FileNotFoundException();

    std::vector<std::string> chipsets;
    get_array(chipsets, file_str, ".chipsets:");

    std::vector<std::string> links;
    get_array(links, file_str, ".links:");

    fill_circuit(circuit, chipsets, links);
}
