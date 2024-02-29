/*
** EPITECH PROJECT, 2024
** InputComponent.cpp
** File description:
** InputComponent
*/

#include "../../includes/components/InputComponent.hpp"
#include "../../ErrorHandling/ErrorHandling.hpp"

nts::InputComponent::InputComponent()
{
}

nts::InputComponent::~InputComponent()
{
}

void nts::InputComponent::setValue(nts::Tristate value)
{
    this->_nextValue = value;
}

void nts::InputComponent::simulate(std::size_t tick)
{
    this->_value = this->_nextValue;
}

nts::Tristate nts::InputComponent::compute(std::size_t pin)
{
    if (pin != 1)
        throw nts::PinException();
    return nts::Tristate::True;
}
