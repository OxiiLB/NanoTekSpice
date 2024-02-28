/*
** EPITECH PROJECT, 2024
** CreateComponent
** File description:
** CreateComponent
*/

#include "../includes/ComponentFactory.hpp"
#include "../includes/components/AndComponent.hpp"
#include "../includes/components/OrComponent.hpp"
#include "../includes/components/ClockComponent.hpp"
#include "../includes/components/TrueComponent.hpp"

nts::ComponentFactory::ComponentFactory()
{
    _FunctionTab["And"] = [this](){ return createAndComponent(); };
    _FunctionTab["Or"] = [this](){ return createOrComponent(); };
    _FunctionTab["Clock"] = [this](){ return createClockComponent(); };
    _FunctionTab["True"] = [this](){ return createTrueComponent(); };
}

nts::ComponentFactory::~ComponentFactory()
{
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::createComponent(const std::string &type)
{
    auto it = _FunctionTab.find(type);
    if (it != _FunctionTab.end()) {
        return it->second();
    }
    return nullptr;
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::createAndComponent() const
{
    return std::make_unique<nts::AndComponent>();
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::createOrComponent() const
{
    return std::make_unique<nts::OrComponent>();
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::createClockComponent() const
{
    return std::make_unique<nts::ClockComponent>();
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::createTrueComponent() const
{
    return std::make_unique<nts::TrueComponent>();
}