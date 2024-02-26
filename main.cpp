/*
** EPITECH PROJECT, 2024
** main
** File description:
** main
*/

#include "includes/components/FalseComponent.hpp"
#include "includes/components/TrueComponent.hpp"
#include "includes/components/AndComponent.hpp"
#include "includes/components/NotComponent.hpp"
#include <memory>

int main(void)
{
    std::unique_ptr<nts::IComponent>input1 = std::make_unique<nts::FalseComponent>();
    std::unique_ptr<nts::IComponent>input2 = std::make_unique<nts::TrueComponent>();
    std::unique_ptr<nts::IComponent>and_gate = std::make_unique<nts::AndComponent>();
    std::unique_ptr<nts::IComponent>inverter = std::make_unique<nts::NotComponent>();
    and_gate->setLink(1, *input1, 1);
    and_gate->setLink(2, *input2, 1)
    inverter->setLink(1 , *and_gate , 3);
    std::cout << "!(" << input1->compute(1) << " && " << input2->compute(1) << ") ->" << inverter->compute(2) << std::endl;
}
