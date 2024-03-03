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
        if (a == nts::Tristate::False || b == nts::Tristate::False)
            return nts::Tristate::True;
        else if (a == nts::Tristate::True && b == nts::Tristate::True)
            return nts::Tristate::False;
        else
            return nts::Tristate::Undefined;
    }
    if (pin == 4) {
        nts::Tristate a = this->_links[4].second->compute(this->_links[4].first);
        nts::Tristate b = this->_links[5].second->compute(this->_links[5].first);
        if (a == nts::Tristate::False || b == nts::Tristate::False)
            return nts::Tristate::True;
        else if (a == nts::Tristate::True && b == nts::Tristate::True)
            return nts::Tristate::False;
        else
            return nts::Tristate::Undefined;
    }
    if (pin == 10) {
        nts::Tristate a = this->_links[7].second->compute(this->_links[7].first);
        nts::Tristate b = this->_links[8].second->compute(this->_links[8].first);
        if (a == nts::Tristate::False || b == nts::Tristate::False)
            return nts::Tristate::True;
        else if (a == nts::Tristate::True && b == nts::Tristate::True)
            return nts::Tristate::False;
        else
            return nts::Tristate::Undefined;
    }
    if (pin == 11) {
        nts::Tristate a = this->_links[11].second->compute(this->_links[11].first);
        nts::Tristate b = this->_links[12].second->compute(this->_links[12].first);
        if (a == nts::Tristate::False || b == nts::Tristate::False)
            return nts::Tristate::True;
        else if (a == nts::Tristate::True && b == nts::Tristate::True)
            return nts::Tristate::False;
        else
            return nts::Tristate::Undefined;
    }
    throw nts::PinException();
}