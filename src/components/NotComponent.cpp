/*
** EPITECH PROJECT, 2024
** NotComponent.cpp
** File description:
** functions for NotComponent class
*/

#include "../../includes/components/NotComponent.hpp"
#include "../../ErrorHandling/ErrorHandling.hpp"

nts::NotComponent::NotComponent()
{
}

nts::NotComponent::~NotComponent()
{
}

nts::Tristate nts::NotComponent::compute(std::size_t pin)
{
    if (pin == 2) {
        if (this->_links[0].second->compute(this->_links[0].first) == nts::Tristate::True)
            return nts::Tristate::False;
        else if (this->_links[0].second->compute(this->_links[0].first) == nts::Tristate::False)
            return nts::Tristate::True;
        else
            return nts::Tristate::Undefined;
    }
    throw nts::PinException();
}
