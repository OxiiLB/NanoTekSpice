/*
** EPITECH PROJECT, 2024
** Circuit.cpp
** File description:
** Functions for class Circuit
*/

#include "../includes/Circuit.hpp"
#include "../includes/components/AndComponent.hpp"
#include "../includes/components/NotComponent.hpp"
#include "../includes/components/TrueComponent.hpp"
#include "../includes/components/FalseComponent.hpp"

Circuit::Circuit()
{
}

Circuit::~Circuit()
{
}

// getters & setters

int Circuit::getTick()
{
    return _tick;
}

void Circuit::setTick(int tick)
{
    _tick = tick;
}

// Methods

void Circuit::simulate()
{
    this->_tick++;

    for (auto &component : this->_components) {
        component.second->simulate(this->_tick);
    }
}

void Circuit::display()
{

}

void Circuit::addComponent(std::string type, nts::IComponent *component)
{
    this->_components.push_back(std::make_pair(type, component));
}

nts::IComponent *Circuit::getComponent(std::string name)
{
    for (auto &component : this->_components) {
        if (component.first == name)
            return component.second;
    }
    return nullptr;
}

void Circuit::display()
{
    for (auto &component : this->_components) {
        if 
        std::cout << component.first << " : " << component.second->getValue() << std::endl;
    }
}