/*
** EPITECH PROJECT, 2024
** NotComponent.cpp
** File description:
** functions for NotComponent class
*/

#include "../../includes/components/NotComponent.hpp"

nts::NotComponent::NotComponent()
{
}

nts::NotComponent::~NotComponent()
{
}

nts::Tristate nts::NotComponent::compute(std::size_t pin)
{
    nts::Tristate input1 = nts::Tristate::Undefined;
    std::pair<std::size_t, nts::IComponent *> link1 = this->getLink(1);

    if (link1.second)
        input1 = link1.second->compute(link1.first);
    if (input1 == nts::Tristate::True)
        return nts::Tristate::False;
    else if (input1 == nts::Tristate::False)
        return nts::Tristate::True;
    return nts::Tristate::Undefined;

}