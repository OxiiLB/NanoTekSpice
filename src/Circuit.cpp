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

void Circuit::addComponent(std::string name, nts::IComponent *component)
{
    this->_components[name] = component;
}

nts::IComponent *Circuit::getComponent(std::string name)
{
    for (auto &component : this->_components) {
        if (component.first == name)
            return component.second;
    }
    return nullptr;
}

void Circuit::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    std::cout << "Circuit::setLink" << std::endl;
    for (auto &component : this->_components) {
        if (component.second->compute(pin) == nts::Tristate::Undefined) {
            component.second->setLink(pin, other, otherPin);
            return;
        }
    }
}

void Circuit::simulate(std::size_t tick)
{
    this->_tick = tick;
    this->simulate();
}

nts::Tristate Circuit::compute(std::size_t pin)
{
    for (auto &component : this->_components) {
        if (component.second->compute(pin) != nts::Tristate::Undefined)
            return component.second->compute(pin);
    }
    return nts::Tristate::Undefined;
}

void Circuit::display()
{
    std::cout << "tick: " << this->_tick << std::endl;
    std::cout << "input(s):" << std::endl;
    for (auto &component : this->_components) {
        if (auto input = dynamic_cast<nts::InputComponent *>(component.second)) {
            std::cout << component.first << ": " << input->compute(1) << std::endl;
        } else if (auto clock = dynamic_cast<nts::ClockComponent *>(component.second)) {
            std::cout << component.first << ": " << clock->compute(1) << std::endl;
        }
    }
    std::cout << "output(s):" << std::endl;
    for (auto &component : this->_components) {
        if (auto output = dynamic_cast<nts::OutputComponent *>(component.second)) {
            std::cout << component.first << ": " << output->compute(1) << std::endl;
        }
    }
}

