/*
** EPITECH PROJECT, 2024
** Circuit.cpp
** File description:
** Functions for class Circuit
*/

#include <iostream>
#include "../includes/Circuit.hpp"
#include "../includes/components/AndComponent.hpp"
#include "../includes/components/NotComponent.hpp"
#include "../includes/components/TrueComponent.hpp"
#include "../includes/components/FalseComponent.hpp"
#include "../includes/components/InputComponent.hpp"
#include "../includes/components/OutputComponent.hpp"
#include "../includes/components/ClockComponent.hpp"
#include "../includes/components/OrComponent.hpp"
#include "../includes/components/XorComponent.hpp"

Circuit::Circuit()
{
    this->_tick = 0;

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

void Circuit::addComponent(std::string name, std::unique_ptr<nts::IComponent> &component)
{
    this->_components[name] = std::move(component);
}

nts::IComponent *Circuit::getComponent(std::string name)
{
    for (const auto &pair : this->_components) {
        if (pair.first == name)
            return pair.second.get();
    }
    return nullptr;
}

void Circuit::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
}

void Circuit::simulate(std::size_t tick)
{
    this->_tick = tick;
    this->simulate();
}

nts::Tristate Circuit::compute(std::size_t pin)
{
    for (const auto &component : this->_components) {
        if (component.second->compute(pin) != nts::Tristate::Undefined)
            return component.second->compute(pin);
    }
    return nts::Tristate::Undefined;
}

void Circuit::display()
{
    std::cout << "tick: " << this->_tick << std::endl;
    std::cout << "input(s):" << std::endl;
    for (const auto &component : this->_components) {
        const std::string &name = component.first;
        const std::unique_ptr<nts::IComponent> &comp = component.second;
        if (dynamic_cast<nts::InputComponent *>(comp.get())) {
            if (comp->compute(1) == -1)
                std::cout << name << ": U" << std::endl;
            else
                std::cout << name << ": " << comp->compute(1) << std::endl;
        }
        if (dynamic_cast<nts::ClockComponent *>(comp.get())) {
            if (comp->compute(1) == -1)
                std::cout << name << ": U" << std::endl;
            else
                std::cout << name << ": " << comp->compute(1) << std::endl;
        }
    }
    std::cout << "output(s):" << std::endl;
    for (const auto &component : this->_components) {
        const std::string &name = component.first;
        const std::unique_ptr<nts::IComponent> &comp = component.second;
        if (dynamic_cast<nts::OutputComponent *>(comp.get())) {
            if (comp->compute(1) == -1)
                std::cout << name << ": U" << std::endl;
            else
                std::cout << name << ": " << comp->compute(1) << std::endl;
        }
    }
}

