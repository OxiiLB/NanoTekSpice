/*
** EPITECH PROJECT, 2024
** OrComponent.cpp
** File description:
** OrComponent
*/

#include "../../includes/components/OrComponent.hpp"
#include "../../ErrorHandling/ErrorHandling.hpp"

nts::OrComponent::OrComponent()
{
}

nts::OrComponent::~OrComponent()
{
}

nts::Tristate nts::OrComponent::compute(std::size_t pin)
{
    if (pin == 3) {
        nts::Tristate a = this->_links[0].second->compute(this->_links[0].first);
        nts::Tristate b = this->_links[1].second->compute(this->_links[1].first);
        if (a == nts::Tristate::True || b == nts::Tristate::True)
            return nts::Tristate::True;
        else if (a == nts::Tristate::False && b == nts::Tristate::False)
            return nts::Tristate::False;
        else
            return nts::Tristate::Undefined;
    }
    throw nts::PinException();
}
