/*
** EPITECH PROJECT, 2024
** XorComponent
** File description:
** XorComponent
*/

#include "../../includes/components/XorComponent.hpp"
#include "../../ErrorHandling/ErrorHandling.hpp"

nts::XorComponent::XorComponent()
{
}

nts::XorComponent::~XorComponent()
{
}

nts::Tristate nts::XorComponent::compute(std::size_t pin)
{
    if (pin == 3) {
        if (this->_links[0].second->compute(this->_links[0].first) == nts::Tristate::True &&
        this->_links[1].second->compute(this->_links[1].first) == nts::Tristate::False)
            return nts::Tristate::True;
        else if (this->_links[0].second->compute(this->_links[0].first) == nts::Tristate::False &&
        this->_links[1].second->compute(this->_links[1].first) == nts::Tristate::True)
            return nts::Tristate::True;
        else if (this->_links[0].second->compute(this->_links[0].first) == nts::Tristate::True &&
        this->_links[1].second->compute(this->_links[1].first) == nts::Tristate::True)
            return nts::Tristate::False;
        else if (this->_links[0].second->compute(this->_links[0].first) == nts::Tristate::False &&
        this->_links[1].second->compute(this->_links[1].first) == nts::Tristate::False)
            return nts::Tristate::False;
        else
            return nts::Tristate::Undefined;
    }
    throw nts::PinException();
}