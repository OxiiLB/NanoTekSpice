/*
** EPITECH PROJECT, 2024
** FalseComponent.cpp
** File description:
** all functions for FalseCOmponent
*/

#include "../../includes/components/FalseComponent.hpp"
#include "../../includes/AComponent.hpp"

nts::FalseComponent::FalseComponent()
{
}

nts::FalseComponent::~FalseComponent()
{
}

nts::Tristate nts::FalseComponent::compute(std::size_t pin)
{
    return nts::Tristate::False;
}
