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
}

nts::ClockComponent::~ClockComponent()
{
}

void nts::ClockComponent::simulate(std::size_t tick)
{
    if (tick == 0)
        this->_value = nts::Tristate::Undefined;
    else if (tick % 2 == 0)
        this->_value = nts::Tristate::True;
    else
        this->_value = nts::Tristate::False;
}

nts::Tristate nts::ClockComponent::compute(std::size_t pin)
{
    if (pin != 1)
        throw nts::PinException();
    return this->_value;
}
