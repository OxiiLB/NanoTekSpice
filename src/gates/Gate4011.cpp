/*
** EPITECH PROJECT, 2024
** Gate4011
** File description:
** Gate4011
*/

#include "../../includes/gates/Gate4011.hpp"
#include "../../ErrorHandling/ErrorHandling.hpp"

nts::Nand::Nand()
{
}

nts::Nand::~Nand()
{
}

nts::Tristate nts::Nand::compute(std::size_t pin)
{
    if (pin == 3) {
        nts::Tristate a = this->_links[0].second->compute(this->_links[0].first);
        nts::Tristate b = this->_links[1].second->compute(this->_links[1].first);
        if (a == nts::Tristate::True && b == nts::Tristate::True)
            return nts::Tristate::False;
        else if (a == nts::Tristate::Undefined || b == nts::Tristate::Undefined)
            return nts::Tristate::Undefined;
        else
            return nts::Tristate::True;
    }
    if (pin == 4) {
        nts::Tristate a = this->_links[2].second->compute(this->_links[2].first);
        nts::Tristate b = this->_links[3].second->compute(this->_links[3].first);
        if (a == nts::Tristate::True && b == nts::Tristate::True)
            return nts::Tristate::False;
        else if (a == nts::Tristate::Undefined || b == nts::Tristate::Undefined)
            return nts::Tristate::Undefined;
        else
            return nts::Tristate::True;
    }
    if (pin == 10) {
        nts::Tristate a = this->_links[4].second->compute(this->_links[4].first);
        nts::Tristate b = this->_links[5].second->compute(this->_links[5].first);
        if (a == nts::Tristate::True && b == nts::Tristate::True)
            return nts::Tristate::False;
        else if (a == nts::Tristate::Undefined || b == nts::Tristate::Undefined)
            return nts::Tristate::Undefined;
        else
            return nts::Tristate::True;
    }
    if (pin == 11) {
        nts::Tristate a = this->_links[6].second->compute(this->_links[6].first);
        nts::Tristate b = this->_links[7].second->compute(this->_links[7].first);
        if (a == nts::Tristate::True && b == nts::Tristate::True)
            return nts::Tristate::False;
        else if (a == nts::Tristate::Undefined || b == nts::Tristate::Undefined)
            return nts::Tristate::Undefined;
        else
            return nts::Tristate::True;
    }
    throw nts::PinException();
}