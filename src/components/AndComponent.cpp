/*
** EPITECH PROJECT, 2024
** AndComponent.cpp
** File description:
** functions for AndComponent class
*/

#include "../../includes/components/AndComponent.hpp"

nts::AndComponent::AndComponent()
{
}

nts::AndComponent::~AndComponent()
{
}

nts::Tristate nts::AndComponent::compute(std::size_t pin)
{
    nts::Tristate input1 = nts::Tristate::Undefined;
    nts::Tristate input2 = nts::Tristate::Undefined;
    std::pair<std::size_t, nts::IComponent *> link1 = this->getLink(1);
    std::pair<std::size_t, nts::IComponent *> link2 = this->getLink(2);

    if (link1.second)
        input1 = link1.second->compute(link1.first);
    if (link2.second)
        input2 = link2.second->compute(link2.first);
    if (input1 == nts::Tristate::True && input2 == nts::Tristate::True)
        return nts::Tristate::True;
    else if (input1 == nts::Tristate::False || input2 == nts::Tristate::False)
        return nts::Tristate::False;
    return nts::Tristate::Undefined;
}