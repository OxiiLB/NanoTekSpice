/*
** EPITECH PROJECT, 2024
** 4001.cpp
** File description:
** Nor
*/

#include "../../includes/gates/Gate4001.hpp"
#include "../../ErrorHandling/ErrorHandling.hpp"

nts::Nor::Nor()
{
}

nts::Nor::~Nor()
{
}

nts::Tristate nts::Nor::compute(std::size_t pin)
{
    if (pin == 3) {
        nts::Tristate a = this->_links[0].second->compute(this->_links[0].first);
        nts::Tristate b = this->_links[1].second->compute(this->_links[1].first);
        if (a == nts::Tristate::False && b == nts::Tristate::False)
            return nts::Tristate::True;
        else if (a == nts::Tristate::Undefined || b == nts::Tristate::Undefined)
            return nts::Tristate::Undefined;
        else
            return nts::Tristate::False;
    }
    if (pin == 4) {
        nts::Tristate a = this->_links[3].second->compute(this->_links[3].first);
        nts::Tristate b = this->_links[4].second->compute(this->_links[4].first);
        if (a == nts::Tristate::False && b == nts::Tristate::False)
            return nts::Tristate::True;
        else if (a == nts::Tristate::Undefined || b == nts::Tristate::Undefined)
            return nts::Tristate::Undefined;
        else
            return nts::Tristate::False;
    }
    if (pin == 10) {
        nts::Tristate a = this->_links[5].second->compute(this->_links[5].first);
        nts::Tristate b = this->_links[6].second->compute(this->_links[6].first);
        if (a == nts::Tristate::False && b == nts::Tristate::False)
            return nts::Tristate::True;
        else if (a == nts::Tristate::Undefined || b == nts::Tristate::Undefined)
            return nts::Tristate::Undefined;
        else
            return nts::Tristate::False;
    }
    if (pin == 11) {
        nts::Tristate a = this->_links[7].second->compute(this->_links[7].first);
        nts::Tristate b = this->_links[8].second->compute(this->_links[8].first);
        if (a == nts::Tristate::False && b == nts::Tristate::False)
            return nts::Tristate::True;
        else if (a == nts::Tristate::Undefined || b == nts::Tristate::Undefined)
            return nts::Tristate::Undefined;
        else
            return nts::Tristate::False;
    }
    throw nts::PinException();
}