/*
** EPITECH PROJECT, 2024
** Gate4069
** File description:
** Gate4069
*/

#include "../../includes/gates/Gate4069.hpp"
#include "../../ErrorHandling/ErrorHandling.hpp"

nts::Inverter::Inverter()
{
}

nts::Inverter::~Inverter()
{
}

nts::Tristate nts::Inverter::compute(std::size_t pin)
{
    if (pin == 2) {
        if (this->_links[0].second->compute(this->_links[0].first) == nts::Tristate::True)
            return nts::Tristate::False;
        else if (this->_links[0].second->compute(this->_links[0].first) == nts::Tristate::False)
            return nts::Tristate::True;
        else
            return nts::Tristate::Undefined;
    }
    if (pin == 4) {
        if (this->_links[2].second->compute(this->_links[2].first) == nts::Tristate::True)
            return nts::Tristate::False;
        else if (this->_links[2].second->compute(this->_links[2].first) == nts::Tristate::False)
            return nts::Tristate::True;
        else
            return nts::Tristate::Undefined;
    }
    if (pin == 6) {
        if (this->_links[4].second->compute(this->_links[4].first) == nts::Tristate::True)
            return nts::Tristate::False;
        else if (this->_links[4].second->compute(this->_links[4].first) == nts::Tristate::False)
            return nts::Tristate::True;
        else
            return nts::Tristate::Undefined;
    }
    if (pin == 8) {
        if (this->_links[8].second->compute(this->_links[8].first) == nts::Tristate::True)
            return nts::Tristate::False;
        else if (this->_links[8].second->compute(this->_links[8].first) == nts::Tristate::False)
            return nts::Tristate::True;
        else
            return nts::Tristate::Undefined;
    }
    if (pin == 10) {
        if (this->_links[10].second->compute(this->_links[10].first) == nts::Tristate::True)
            return nts::Tristate::False;
        else if (this->_links[10].second->compute(this->_links[10].first) == nts::Tristate::False)
            return nts::Tristate::True;
        else
            return nts::Tristate::Undefined;
    }
    if (pin == 12) {
        if (this->_links[12].second->compute(this->_links[12].first) == nts::Tristate::True)
            return nts::Tristate::False;
        else if (this->_links[12].second->compute(this->_links[12].first) == nts::Tristate::False)
            return nts::Tristate::True;
        else
            return nts::Tristate::Undefined;
    }
    throw nts::PinException();
}
