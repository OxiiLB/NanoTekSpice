/*
** EPITECH PROJECT, 2024
** 4001.cpp
** File description:
** Nor
*/

#include "../../includes/gates/Nor.hpp"
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
    throw nts::PinException();
}