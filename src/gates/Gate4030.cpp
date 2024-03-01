/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Gate4030
*/

#include "../../includes/gates/Gate4030.hpp"
#include "../../ErrorHandling/ErrorHandling.hpp"

nts::Xor4::Xor4()
{
}

nts::Xor4::~Xor4()
{
}

nts::Tristate nts::Xor4::compute(std::size_t pin)
{
    if (pin == 3) {
        nts::Tristate a = this->_links[0].second->compute(this->_links[0].first);
        nts::Tristate b = this->_links[1].second->compute(this->_links[1].first);
        if (a == nts::Tristate::True ^ b == nts::Tristate::True)
            return nts::Tristate::True;
        else if (a == nts::Tristate::Undefined || b == nts::Tristate::Undefined)
            return nts::Tristate::Undefined;
        else
            return nts::Tristate::False;
    }
    if (pin == 4) {
        nts::Tristate a = this->_links[4].second->compute(this->_links[4].first);
        nts::Tristate b = this->_links[5].second->compute(this->_links[5].first);
        if (a == nts::Tristate::True ^ b == nts::Tristate::True)
            return nts::Tristate::True;
        else if (a == nts::Tristate::Undefined || b == nts::Tristate::Undefined)
            return nts::Tristate::Undefined;
        else
            return nts::Tristate::False;
    }
    if (pin == 10) {
        nts::Tristate a = this->_links[7].second->compute(this->_links[7].first);
        nts::Tristate b = this->_links[8].second->compute(this->_links[8].first);
        if (a == nts::Tristate::True ^ b == nts::Tristate::True)
            return nts::Tristate::True;
        else if (a == nts::Tristate::Undefined)
            return nts::Tristate::Undefined;
        else
            return nts::Tristate::False;
    }
    if (pin == 11) {
        nts::Tristate a = this->_links[11].second->compute(this->_links[11].first);
        nts::Tristate b = this->_links[12].second->compute(this->_links[12].first);
        if (a == nts::Tristate::True ^ b == nts::Tristate::True)
            return nts::Tristate::True;
        else if (a == nts::Tristate::Undefined)
            return nts::Tristate::Undefined;
        else
            return nts::Tristate::False;
    }
    throw nts::PinException();
}
