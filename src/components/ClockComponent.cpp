/*
** EPITECH PROJECT, 2024
** ClockComponent.cpp
** File description:
** ClockComponent
*/

#include "../../includes/components/ClockComponent.hpp"
#include "../../ErrorHandling/ErrorHandling.hpp"

nts::ClockComponent::ClockComponent()
{
    this->_value = nts::Tristate::Undefined;
    this->_nextValue = nts::Tristate::Undefined;
}

nts::ClockComponent::~ClockComponent()
{
}

void nts::ClockComponent::setValue(nts::Tristate value)
{
    this->_nextValue = value;
}

void nts::ClockComponent::simulate(std::size_t tick)
{
    this->_value = this->_nextValue;
    if (this->_value == nts::Tristate::True)
        this->_nextValue = nts::Tristate::False;
    else if (this->_value == nts::Tristate::False)
        this->_nextValue = nts::Tristate::True;
}

nts::Tristate nts::ClockComponent::compute(std::size_t pin)
{
    if (pin != 1)
        throw nts::PinException();
    return this->_value;
}
