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

nts::Tristate nts::InputComponent::compute(std::size_t pin)
{
    if (pin != 1)
        throw nts::PinException();
    return nts::Tristate::True;
}
