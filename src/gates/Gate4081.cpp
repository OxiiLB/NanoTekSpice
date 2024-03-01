/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Gate4080
*/

#include "../../ErrorHandling/ErrorHandling.hpp"
#include "../../includes/gates/Gate4081.hpp"

nts::And4::And4()
{
}

nts::And4::~And4()
{
}

nts::Tristate nts::And4::compute(std::size_t pin)
{
    if (pin == 3) {
        if (this->_links[0].second->compute(this->_links[0].first) == nts::Tristate::False ||
            this->_links[1].second->compute(this->_links[1].first) == nts::Tristate::False)
            return nts::Tristate::False;
        else if (this->_links[0].second->compute(this->_links[0].first) == nts::Tristate::True  &&
                this->_links[1].second->compute(this->_links[1].first) == nts::Tristate::True)
            return nts::Tristate::True;
        else
            return nts::Tristate::Undefined;
    }
    if (pin == 4) {
        if (this->_links[4].second->compute(this->_links[4].first) == nts::Tristate::False ||
            this->_links[5].second->compute(this->_links[5].first) == nts::Tristate::False)
            return nts::Tristate::False;
        else if (this->_links[4].second->compute(this->_links[4].first) == nts::Tristate::True  &&
                this->_links[5].second->compute(this->_links[5].first) == nts::Tristate::True)
            return nts::Tristate::True;
        else
            return nts::Tristate::Undefined;
    }
    if (pin == 10) {
        if (this->_links[7].second->compute(this->_links[7].first) == nts::Tristate::False ||
            this->_links[8].second->compute(this->_links[8].first) == nts::Tristate::False)
            return nts::Tristate::False;
        else if (this->_links[7].second->compute(this->_links[7].first) == nts::Tristate::True  &&
                this->_links[8].second->compute(this->_links[8].first) == nts::Tristate::True)
            return nts::Tristate::True;
        else
            return nts::Tristate::Undefined;
    }
    if (pin == 11) {
        if (this->_links[11].second->compute(this->_links[11].first) == nts::Tristate::False ||
            this->_links[12].second->compute(this->_links[12].first) == nts::Tristate::False)
            return nts::Tristate::False;
        else if (this->_links[11].second->compute(this->_links[11].first) == nts::Tristate::True  &&
                this->_links[12].second->compute(this->_links[12].first) == nts::Tristate::True)
            return nts::Tristate::True;
        else
            return nts::Tristate::Undefined;
    }
    throw nts::PinException();
}
