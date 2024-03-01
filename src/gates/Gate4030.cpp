/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Gate4030
*/

#include "Gate4030.hpp"

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
        nts::Tristate c = this->_links[2].second->compute(this->_links[2].first);
        nts::Tristate d = this->_links[3].second->compute(this->_links[3].first);
        if (a == nts::Tristate::True && b == nts::Tristate::True && c == nts::Tristate::True && d == nts::Tristate::True)
            return nts::Tristate::False;
        else if (a == nts::Tristate::Undefined || b == nts::Tristate::Undefined || c == nts::Tristate::Undefined || d == nts::Tristate::Undefined)
            return nts::Tristate::Undefined;
        else
            return nts::Tristate::True;
    }
    if (pin == 4) {
        nts::Tristate a = this->_links[5].second->compute(this->_links[5].first);
        nts::Tristate b = this->_links[6].second->compute(this->_links[6].first);
        nts::Tristate c = this->_links[7].second->compute(this->_links[7].first);
        nts::Tristate d = this->_links[8].second->compute(this->_links[8].first);
        if (a == nts::Tristate::True && b == nts::Tristate::True && c == nts::Tristate::True && d == nts::Tristate::True)
            return nts::Tristate::False;
        else if (a == nts::Tristate::Undefined || b == nts::Tristate::Undefined || c == nts::Tristate::Undefined || d == nts::Tristate::Undefined)
            return nts::Tristate::Undefined;
        else
            return nts::Tristate::True;
    }
    if (pin == 10) {
        nts::Tristate a = this->_links[9].second->compute(this->_links[9].first);
        nts::Tristate b = this->_links[10].second->compute(this->_links[10].first);
        nts::Tristate c = this->_links[11].second->compute(this->_links[11].first);
        nts::Tristate d = this->_links[12].second->compute(this->_links[12].first);
        if (a == nts::Tristate::True && b == nts::Tristate::True && c == nts::Tristate::True && d == nts::Tristate::True)
            return nts::Tristate::False;
        else if (a == nts::Tristate::Undefined || b == nts::Tristate::Undefined || c == nts::Tristate::Undefined || d == nts::Tristate::Undefined)
            return nts::Tristate::Undefined;
        else
            return nts::Tristate::True;
    }
    if (pin == 11) {
        nts::Tristate a = this->_links[13].second->compute(this->_links[13].first);
        nts::Tristate b = this->_links[14].second->compute(this->_links[14].first);
        nts::Tristate c = this->_links[15].second->compute(this->_links[15].first);
        nts::Tristate d = this->_links[16].second->compute(this->_links[16].first);
        if (a == nts::Tristate::True && b == nts::Tristate::True && c == nts::Tristate::True && d == nts::Tristate::True)
            return nts::Tristate::False;
        else if (a == nts::Tristate::Undefined || b == nts::Tristate::Undefined || c == nts::Tristate::Undefined || d == nts::Tristate::Undefined)
            return nts::Tristate::Undefined;
        else
            return nts::Tristate::True;
    }
}
