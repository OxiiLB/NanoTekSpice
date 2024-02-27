/*
** EPITECH PROJECT, 2024
** OutputComponent.cpp
** File description:
** OutputComponent
*/

#include "../../includes/components/OutputComponent.hpp"
#include "../../ErrorHandling/ErrorHandling.hpp"

nts::OutputComponent::OutputComponent()
{
}

nts::OutputComponent::~OutputComponent()
{
}

nts::Tristate nts::OutputComponent::compute(std::size_t pin)
{
    if (pin != 1)
        throw nts::PinException();
    return nts::Tristate::True;
}
