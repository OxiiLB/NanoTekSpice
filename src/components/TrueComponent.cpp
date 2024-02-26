/*
** EPITECH PROJECT, 2024
** TrueComponent
** File description:
** TrueComponent
*/

#include "../../includes/components/TrueComponent.hpp"

nts::TrueComponent::TrueComponent()
{
}

nts::TrueComponent::~TrueComponent()
{
}

nts::Tristate nts::TrueComponent::compute(std::size_t pin)
{
    return nts::Tristate::True;
}
