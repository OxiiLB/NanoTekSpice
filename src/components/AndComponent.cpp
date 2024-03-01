/*
** EPITECH PROJECT, 2024
** AndComponent.cpp
** File description:
** functions for AndComponent class
*/

#include "../../includes/components/AndComponent.hpp"
#include "../../ErrorHandling/ErrorHandling.hpp"

nts::AndComponent::AndComponent()
{
}

nts::AndComponent::~AndComponent()
{
}

nts::Tristate nts::AndComponent::compute(std::size_t pin)
{
    if (pin == 3) {
        if (this->_links[0].second->compute(this->_links[0].first) == nts::Tristate::False ||
        this->_links[1].second->compute(this->_links[1].first) == nts::Tristate::False)
            return nts::Tristate::False;
        else if (this->_links[0].second->compute(this->_links[0].first) == nts::Tristate::True &&
        this->_links[1].second->compute(this->_links[1].first) == nts::Tristate::True)
            return nts::Tristate::True;
        else
            return nts::Tristate::Undefined;
    }
    throw nts::PinException();
}