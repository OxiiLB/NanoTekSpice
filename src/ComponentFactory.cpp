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
#include "../includes/components/InputComponent.hpp"
#include "../includes/components/OutputComponent.hpp"
#include "../includes/components/NotComponent.hpp"
#include "../includes/components/XorComponent.hpp"
#include "../includes/components/FalseComponent.hpp"
#include "../ErrorHandling/ErrorHandling.hpp"
#include "../includes/gates/Gate4001.hpp"

nts::ComponentFactory::ComponentFactory()
{
    _FunctionTab["clock"] = [this](){ return createClockComponent(); };
    _FunctionTab["and"] = [this](){ return createAndComponent(); };
    _FunctionTab["or"] = [this](){ return createOrComponent(); };
    _FunctionTab["xor"] = [this](){ return createXorComponent(); };
    _FunctionTab["not"] = [this](){ return createNotComponent(); };
    _FunctionTab["input"] = [this](){ return createInputComponent(); };
    _FunctionTab["output"] = [this](){ return createOutputComponent(); };
    _FunctionTab["true"] = [this](){ return createTrueComponent(); };
    _FunctionTab["false"] = [this](){ return createFalseComponent(); };
    _FunctionTab["nor"] = [this](){ return createNorGate(); };
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
    throw nts::ComponentException();
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::createNorGate() const
{
    return std::make_unique<nts::Nor>();
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

std::unique_ptr<nts::IComponent> nts::ComponentFactory::createInputComponent() const
{
    return std::make_unique<nts::InputComponent>();
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::createOutputComponent() const
{
    return std::make_unique<nts::OutputComponent>();
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::createNotComponent() const
{
    return std::make_unique<nts::NotComponent>();
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::createXorComponent() const
{
    return std::make_unique<nts::XorComponent>();
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::createFalseComponent() const
{
    return std::make_unique<nts::FalseComponent>();
}
