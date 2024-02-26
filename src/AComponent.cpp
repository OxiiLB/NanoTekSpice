/*
** EPITECH PROJECT, 2024
** AComponent.cpp
** File description:
** All AComponent functions
*/

#include "../includes/AComponent.hpp"
#include <map>

nts::AComponent::AComponent()
{
    _links.resize(14);
}

void nts::AComponent::simulate(std::size_t tick)
{
}

void nts::AComponent::setLink(std::size_t pin , nts::IComponent &other, std::size_t otherPin)
{
    pin --;
    this->_links[pin] = std::make_pair(otherPin, &other);
}

std::pair<std::size_t, nts::IComponent *> nts::AComponent::getLink(std::size_t pin) const
{
    for (size_t i = 0; i != _links.size(); i++) {
        if (_links[i].first == pin)
            return _links[i];
    }

    return std::make_pair(0, nullptr);
}
