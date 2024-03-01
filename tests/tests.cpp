/*
** EPITECH PROJECT, 2024
** tests.cpp
** File description:
** tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../includes/functions.hpp"

static void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(AndComponent, CheckTrueTrue, .init = redirect_all_stdout)
{
    nts::AndComponent andComp;
    nts::TrueComponent trueComp1;
    nts::TrueComponent trueComp2;

    andComp.setLink(1, trueComp1, 1);
    andComp.setLink(2, trueComp2, 1);
    cr_assert_eq(andComp.compute(3), nts::Tristate::True);
}

Test(AndComponent, CheckTrueFalse, .init = redirect_all_stdout)
{
    nts::AndComponent andComp;
    nts::TrueComponent trueComp1;
    nts::FalseComponent falseComp1;

    andComp.setLink(1, trueComp1, 1);
    andComp.setLink(2, falseComp1, 1);
    cr_assert_eq(andComp.compute(3), nts::Tristate::False);
}

Test(AndComponent, CheckFalseTrue, .init = redirect_all_stdout)
{
    nts::AndComponent andComp;
    nts::FalseComponent falseComp1;
    nts::TrueComponent trueComp1;

    andComp.setLink(1, falseComp1, 1);
    andComp.setLink(2, trueComp1, 1);
    cr_assert_eq(andComp.compute(3), nts::Tristate::False);
}

Test(AndComponent, CheckFalseFalse, .init = redirect_all_stdout)
{
    nts::AndComponent andComp;
    nts::FalseComponent falseComp1;
    nts::FalseComponent falseComp2;

    andComp.setLink(1, falseComp1, 1);
    andComp.setLink(2, falseComp2, 1);
    cr_assert_eq(andComp.compute(3), nts::Tristate::False);
}

Test(AndComponent, CheckUndefinedTrue, .init = redirect_all_stdout)
{
    nts::AndComponent andComp;
    nts::InputComponent inputComp1;
    nts::TrueComponent trueComp1;

    andComp.setLink(1, inputComp1, 1);
    andComp.setLink(2, trueComp1, 1);
    cr_assert_eq(andComp.compute(3), nts::Tristate::Undefined);
}

Test(AndComponent, CheckUndefinedFalse, .init = redirect_all_stdout)
{
    nts::AndComponent andComp;
    nts::InputComponent inputComp1;
    nts::FalseComponent falseComp1;

    andComp.setLink(1, inputComp1, 1);
    andComp.setLink(2, falseComp1, 1);
    cr_assert_eq(andComp.compute(3), nts::Tristate::False);
}

Test(AndComponent, CheckUndefinedUndefined, .init = redirect_all_stdout)
{
    nts::AndComponent andComp;
    nts::InputComponent inputComp1;
    nts::InputComponent inputComp2;

    andComp.setLink(1, inputComp1, 1);
    andComp.setLink(2, inputComp2, 1);
    cr_assert_eq(andComp.compute(3), nts::Tristate::Undefined);
}

Test(OrComponent, CheckTrueTrue, .init = redirect_all_stdout)
{
    nts::OrComponent orComp;
    nts::TrueComponent trueComp1;
    nts::TrueComponent trueComp2;

    orComp.setLink(1, trueComp1, 1);
    orComp.setLink(2, trueComp2, 1);
    cr_assert_eq(orComp.compute(3), nts::Tristate::True);
}

Test(OrComponent, CheckTrueFalse, .init = redirect_all_stdout)
{
    nts::OrComponent orComp;
    nts::TrueComponent trueComp1;
    nts::FalseComponent falseComp1;

    orComp.setLink(1, trueComp1, 1);
    orComp.setLink(2, falseComp1, 1);
    cr_assert_eq(orComp.compute(3), nts::Tristate::True);
}

Test(OrComponent, CheckFalseTrue, .init = redirect_all_stdout)
{
    nts::OrComponent orComp;
    nts::FalseComponent falseComp1;
    nts::TrueComponent trueComp1;

    orComp.setLink(1, falseComp1, 1);
    orComp.setLink(2, trueComp1, 1);
    cr_assert_eq(orComp.compute(3), nts::Tristate::True);
}

Test(OrComponent, CheckFalseFalse, .init = redirect_all_stdout)
{
    nts::OrComponent orComp;
    nts::FalseComponent falseComp1;
    nts::FalseComponent falseComp2;

    orComp.setLink(1, falseComp1, 1);
    orComp.setLink(2, falseComp2, 1);
    cr_assert_eq(orComp.compute(3), nts::Tristate::False);
}

Test(OrComponent, CheckUndefinedTrue, .init = redirect_all_stdout)
{
    nts::OrComponent orComp;
    nts::InputComponent inputComp1;
    nts::TrueComponent trueComp1;

    orComp.setLink(1, inputComp1, 1);
    orComp.setLink(2, trueComp1, 1);
    cr_assert_eq(orComp.compute(3), nts::Tristate::True);
}

Test(OrComponent, CheckUndefinedFalse, .init = redirect_all_stdout)
{
    nts::OrComponent orComp;
    nts::InputComponent inputComp1;
    nts::FalseComponent falseComp1;

    orComp.setLink(1, inputComp1, 1);
    orComp.setLink(2, falseComp1, 1);
    cr_assert_eq(orComp.compute(3), nts::Tristate::Undefined);
}

Test(OrComponent, CheckUndefinedUndefined, .init = redirect_all_stdout)
{
    nts::OrComponent orComp;
    nts::InputComponent inputComp1;
    nts::InputComponent inputComp2;

    orComp.setLink(1, inputComp1, 1);
    orComp.setLink(2, inputComp2, 1);
    cr_assert_eq(orComp.compute(3), nts::Tristate::Undefined);
}

Test(XorComponent, CheckTrueTrue, .init = redirect_all_stdout)
{
    nts::XorComponent xorComp;
    nts::TrueComponent trueComp1;
    nts::TrueComponent trueComp2;

    xorComp.setLink(1, trueComp1, 1);
    xorComp.setLink(2, trueComp2, 1);
    cr_assert_eq(xorComp.compute(3), nts::Tristate::False);
}

Test(XorComponent, CheckTrueFalse, .init = redirect_all_stdout)
{
    nts::XorComponent xorComp;
    nts::TrueComponent trueComp1;
    nts::FalseComponent falseComp1;

    xorComp.setLink(1, trueComp1, 1);
    xorComp.setLink(2, falseComp1, 1);
    cr_assert_eq(xorComp.compute(3), nts::Tristate::True);
}

Test(XorComponent, CheckFalseTrue, .init = redirect_all_stdout)
{
    nts::XorComponent xorComp;
    nts::FalseComponent falseComp1;
    nts::TrueComponent trueComp1;

    xorComp.setLink(1, falseComp1, 1);
    xorComp.setLink(2, trueComp1, 1);
    cr_assert_eq(xorComp.compute(3), nts::Tristate::True);
}

Test(XorComponent, CheckFalseFalse, .init = redirect_all_stdout)
{
    nts::XorComponent xorComp;
    nts::FalseComponent falseComp1;
    nts::FalseComponent falseComp2;

    xorComp.setLink(1, falseComp1, 1);
    xorComp.setLink(2, falseComp2, 1);
    cr_assert_eq(xorComp.compute(3), nts::Tristate::False);
}

Test(XorComponent, CheckUndefinedTrue, .init = redirect_all_stdout)
{
    nts::XorComponent xorComp;
    nts::InputComponent inputComp1;
    nts::TrueComponent trueComp1;

    xorComp.setLink(1, inputComp1, 1);
    xorComp.setLink(2, trueComp1, 1);
    cr_assert_eq(xorComp.compute(3), nts::Tristate::Undefined);
}

Test(XorComponent, CheckUndefinedFalse, .init = redirect_all_stdout)
{
    nts::XorComponent xorComp;
    nts::InputComponent inputComp1;
    nts::FalseComponent falseComp1;

    xorComp.setLink(1, inputComp1, 1);
    xorComp.setLink(2, falseComp1, 1);
    cr_assert_eq(xorComp.compute(3), nts::Tristate::Undefined);
}

Test(XorComponent, CheckUndefinedUndefined, .init = redirect_all_stdout)
{
    nts::XorComponent xorComp;
    nts::InputComponent inputComp1;
    nts::InputComponent inputComp2;

    xorComp.setLink(1, inputComp1, 1);
    xorComp.setLink(2, inputComp2, 1);
    cr_assert_eq(xorComp.compute(3), nts::Tristate::Undefined);
}

Test(NotComponent, CheckTrue, .init = redirect_all_stdout)
{
    nts::NotComponent notComp;
    nts::TrueComponent trueComp1;

    notComp.setLink(1, trueComp1, 1);
    cr_assert_eq(notComp.compute(2), nts::Tristate::False);
}

Test(NotComponent, CheckFalse, .init = redirect_all_stdout)
{
    nts::NotComponent notComp;
    nts::FalseComponent falseComp1;

    notComp.setLink(1, falseComp1, 1);
    cr_assert_eq(notComp.compute(2), nts::Tristate::True);
}

Test(NotComponent, CheckUndefined, .init = redirect_all_stdout)
{
    nts::NotComponent notComp;
    nts::InputComponent inputComp1;

    notComp.setLink(1, inputComp1, 1);
    cr_assert_eq(notComp.compute(2), nts::Tristate::Undefined);
}

Test(ClockComponent, CheckFalse, .init = redirect_all_stdout)
{
    nts::ClockComponent clockComp;

    clockComp.setValue(nts::Tristate::False);
    clockComp.simulate(1);
    cr_assert_eq(clockComp.compute(1), nts::Tristate::False);
}

Test(ClockComponent, CheckTrue, .init = redirect_all_stdout)
{
    nts::ClockComponent clockComp;

    clockComp.setValue(nts::Tristate::True);
    clockComp.simulate(1);
    cr_assert_eq(clockComp.compute(1), nts::Tristate::True);
}

Test(ClockComponent, CheckUndefined, .init = redirect_all_stdout)
{
    nts::ClockComponent clockComp;

    clockComp.simulate(1);
    cr_assert_eq(clockComp.compute(1), nts::Tristate::Undefined);
}

Test(InputComponent, CheckFalse, .init = redirect_all_stdout)
{
    nts::InputComponent inputComp;

    inputComp.setValue(nts::Tristate::False);
    inputComp.simulate(1);
    cr_assert_eq(inputComp.compute(1), nts::Tristate::False);
}

Test(InputComponent, CheckTrue, .init = redirect_all_stdout)
{
    nts::InputComponent inputComp;

    inputComp.setValue(nts::Tristate::True);
    inputComp.simulate(1);
    cr_assert_eq(inputComp.compute(1), nts::Tristate::True);
}

Test(InputComponent, CheckUndefined, .init = redirect_all_stdout)
{
    nts::InputComponent inputComp;

    inputComp.simulate(1);
    cr_assert_eq(inputComp.compute(1), nts::Tristate::Undefined);
}

Test(OutputComponent, CheckFalse, .init = redirect_all_stdout)
{
    nts::OutputComponent outputComp;
    nts::FalseComponent falseComp1;

    outputComp.setLink(1, falseComp1, 1);
    cr_assert_eq(outputComp.compute(1), nts::Tristate::False);
}

Test(OutputComponent, CheckTrue, .init = redirect_all_stdout)
{
    nts::OutputComponent outputComp;
    nts::TrueComponent trueComp1;

    outputComp.setLink(1, trueComp1, 1);
    cr_assert_eq(outputComp.compute(1), nts::Tristate::True);
}

Test(OutputComponent, CheckUndefined, .init = redirect_all_stdout)
{
    nts::OutputComponent outputComp;
    nts::InputComponent inputComp1;

    outputComp.setLink(1, inputComp1, 1);
    cr_assert_eq(outputComp.compute(1), nts::Tristate::Undefined);
}

Test(Gate4001, CheckTrueTrue, .init = redirect_all_stdout)
{
    nts::Nor gate4001;
    nts::TrueComponent trueComp1;
    nts::TrueComponent trueComp2;

    gate4001.setLink(1, trueComp1, 1);
    gate4001.setLink(2, trueComp2, 1);
    cr_assert_eq(gate4001.compute(3), nts::Tristate::False);
}

Test(Gate4001, CheckTrueFalse, .init = redirect_all_stdout)
{
    nts::Nor gate4001;
    nts::TrueComponent trueComp1;
    nts::FalseComponent falseComp1;

    gate4001.setLink(1, trueComp1, 1);
    gate4001.setLink(2, falseComp1, 1);
    cr_assert_eq(gate4001.compute(3), nts::Tristate::False);
}

Test(Gate4001, CheckFalseTrue, .init = redirect_all_stdout)
{
    nts::Nor gate4001;
    nts::FalseComponent falseComp1;
    nts::TrueComponent trueComp1;

    gate4001.setLink(1, falseComp1, 1);
    gate4001.setLink(2, trueComp1, 1);
    cr_assert_eq(gate4001.compute(3), nts::Tristate::False);
}

Test(Gate4001, CheckFalseFalse, .init = redirect_all_stdout)
{
    nts::Nor gate4001;
    nts::FalseComponent falseComp1;
    nts::FalseComponent falseComp2;

    gate4001.setLink(1, falseComp1, 1);
    gate4001.setLink(2, falseComp2, 1);
    cr_assert_eq(gate4001.compute(3), nts::Tristate::True);
}

Test(Gate4001, CheckUndefinedTrue, .init = redirect_all_stdout)
{
    nts::Nor gate4001;
    nts::InputComponent inputComp1;
    nts::TrueComponent trueComp1;

    gate4001.setLink(1, inputComp1, 1);
    gate4001.setLink(2, trueComp1, 1);
    cr_assert_eq(gate4001.compute(3), nts::Tristate::Undefined);
}

Test(Gate4001, CheckUndefinedFalse, .init = redirect_all_stdout)
{
    nts::Nor gate4001;
    nts::InputComponent inputComp1;
    nts::FalseComponent falseComp1;

    gate4001.setLink(1, inputComp1, 1);
    gate4001.setLink(2, falseComp1, 1);
    cr_assert_eq(gate4001.compute(3), nts::Tristate::Undefined);
}

Test(Gate4001, CheckUndefinedUndefined, .init = redirect_all_stdout)
{
    nts::Nor gate4001;
    nts::InputComponent inputComp1;
    nts::InputComponent inputComp2;

    gate4001.setLink(1, inputComp1, 1);
    gate4001.setLink(2, inputComp2, 1);
    cr_assert_eq(gate4001.compute(3), nts::Tristate::Undefined);
}

Test(Gate4001, CheckTrueTrue4, .init = redirect_all_stdout)
{
    nts::Nor gate4001;
    nts::TrueComponent trueComp1;
    nts::TrueComponent trueComp2;

    gate4001.setLink(5, trueComp1, 1);
    gate4001.setLink(6, trueComp2, 1);
    cr_assert_eq(gate4001.compute(4), nts::Tristate::False);
}

Test(Gate4001, CheckTrueFalse4, .init = redirect_all_stdout)
{
    nts::Nor gate4001;
    nts::TrueComponent trueComp1;
    nts::FalseComponent falseComp1;

    gate4001.setLink(5, trueComp1, 1);
    gate4001.setLink(6, falseComp1, 1);
    cr_assert_eq(gate4001.compute(4), nts::Tristate::False);
}

Test(Gate4001, CheckFalseTrue4, .init = redirect_all_stdout)
{
    nts::Nor gate4001;
    nts::FalseComponent falseComp1;
    nts::TrueComponent trueComp1;

    gate4001.setLink(5, falseComp1, 1);
    gate4001.setLink(6, trueComp1, 1);
    cr_assert_eq(gate4001.compute(4), nts::Tristate::False);
}

Test(Gate4001, CheckFalseFalse4, .init = redirect_all_stdout)
{
    nts::Nor gate4001;
    nts::FalseComponent falseComp1;
    nts::FalseComponent falseComp2;

    gate4001.setLink(5, falseComp1, 1);
    gate4001.setLink(6, falseComp2, 1);
    cr_assert_eq(gate4001.compute(4), nts::Tristate::True);
}

Test(Gate4001, CheckUndefinedTrue4, .init = redirect_all_stdout)
{
    nts::Nor gate4001;
    nts::InputComponent inputComp1;
    nts::TrueComponent trueComp1;

    gate4001.setLink(5, inputComp1, 1);
    gate4001.setLink(6, trueComp1, 1);
    cr_assert_eq(gate4001.compute(4), nts::Tristate::Undefined);
}

Test(Gate4001, CheckUndefinedFalse4, .init = redirect_all_stdout)
{
    nts::Nor gate4001;
    nts::InputComponent inputComp1;
    nts::FalseComponent falseComp1;

    gate4001.setLink(5, inputComp1, 1);
    gate4001.setLink(6, falseComp1, 1);
    cr_assert_eq(gate4001.compute(4), nts::Tristate::Undefined);
}

Test(Gate4001, CheckUndefinedUndefined4, .init = redirect_all_stdout)
{
    nts::Nor gate4001;
    nts::InputComponent inputComp1;
    nts::InputComponent inputComp2;

    gate4001.setLink(5, inputComp1, 1);
    gate4001.setLink(6, inputComp2, 1);
    cr_assert_eq(gate4001.compute(4), nts::Tristate::Undefined);
}

Test(Gate4001, CheckTrueTrue10, .init = redirect_all_stdout)
{
    nts::Nor gate4001;
    nts::TrueComponent trueComp1;
    nts::TrueComponent trueComp2;

    gate4001.setLink(8, trueComp1, 1);
    gate4001.setLink(9, trueComp2, 1);
    cr_assert_eq(gate4001.compute(10), nts::Tristate::False);
}

Test(Gate4001, CheckTrueFalse10, .init = redirect_all_stdout)
{
    nts::Nor gate4001;
    nts::TrueComponent trueComp1;
    nts::FalseComponent falseComp1;

    gate4001.setLink(8, trueComp1, 1);
    gate4001.setLink(9, falseComp1, 1);
    cr_assert_eq(gate4001.compute(10), nts::Tristate::False);
}

Test(Gate4001, CheckFalseTrue10, .init = redirect_all_stdout)
{
    nts::Nor gate4001;
    nts::FalseComponent falseComp1;
    nts::TrueComponent trueComp1;

    gate4001.setLink(8, falseComp1, 1);
    gate4001.setLink(9, trueComp1, 1);
    cr_assert_eq(gate4001.compute(10), nts::Tristate::False);
}

Test(Gate4001, CheckFalseFalse10, .init = redirect_all_stdout)
{
    nts::Nor gate4001;
    nts::FalseComponent falseComp1;
    nts::FalseComponent falseComp2;

    gate4001.setLink(8, falseComp1, 1);
    gate4001.setLink(9, falseComp2, 1);
    cr_assert_eq(gate4001.compute(10), nts::Tristate::True);
}

Test(Gate4001, CheckUndefinedTrue10, .init = redirect_all_stdout)
{
    nts::Nor gate4001;
    nts::InputComponent inputComp1;
    nts::TrueComponent trueComp1;

    gate4001.setLink(8, inputComp1, 1);
    gate4001.setLink(9, trueComp1, 1);
    cr_assert_eq(gate4001.compute(10), nts::Tristate::Undefined);
}

Test(Gate4001, CheckUndefinedFalse10, .init = redirect_all_stdout)
{
    nts::Nor gate4001;
    nts::InputComponent inputComp1;
    nts::FalseComponent falseComp1;

    gate4001.setLink(8, inputComp1, 1);
    gate4001.setLink(9, falseComp1, 1);
    cr_assert_eq(gate4001.compute(10), nts::Tristate::Undefined);
}

Test(Gate4001, CheckUndefinedUndefined10, .init = redirect_all_stdout)
{
    nts::Nor gate4001;
    nts::InputComponent inputComp1;
    nts::InputComponent inputComp2;

    gate4001.setLink(8, inputComp1, 1);
    gate4001.setLink(9, inputComp2, 1);
    cr_assert_eq(gate4001.compute(10), nts::Tristate::Undefined);
}

Test(Gate4001, CheckTrueTrue11, .init = redirect_all_stdout)
{
    nts::Nor gate4001;
    nts::TrueComponent trueComp1;
    nts::TrueComponent trueComp2;

    gate4001.setLink(12, trueComp1, 1);
    gate4001.setLink(13, trueComp2, 1);
    cr_assert_eq(gate4001.compute(11), nts::Tristate::False);
}

Test(Gate4001, CheckTrueFalse11, .init = redirect_all_stdout)
{
    nts::Nor gate4001;
    nts::TrueComponent trueComp1;
    nts::FalseComponent falseComp1;

    gate4001.setLink(12, trueComp1, 1);
    gate4001.setLink(13, falseComp1, 1);
    cr_assert_eq(gate4001.compute(11), nts::Tristate::False);
}

Test(Gate4001, CheckFalseTrue11, .init = redirect_all_stdout)
{
    nts::Nor gate4001;
    nts::FalseComponent falseComp1;
    nts::TrueComponent trueComp1;

    gate4001.setLink(12, falseComp1, 1);
    gate4001.setLink(13, trueComp1, 1);
    cr_assert_eq(gate4001.compute(11), nts::Tristate::False);
}

Test(Gate4001, CheckFalseFalse11, .init = redirect_all_stdout)
{
    nts::Nor gate4001;
    nts::FalseComponent falseComp1;
    nts::FalseComponent falseComp2;

    gate4001.setLink(12, falseComp1, 1);
    gate4001.setLink(13, falseComp2, 1);
    cr_assert_eq(gate4001.compute(11), nts::Tristate::True);
}

Test(Gate4001, CheckUndefinedTrue11, .init = redirect_all_stdout)
{
    nts::Nor gate4001;
    nts::InputComponent inputComp1;
    nts::TrueComponent trueComp1;

    gate4001.setLink(12, inputComp1, 1);
    gate4001.setLink(13, trueComp1, 1);
    cr_assert_eq(gate4001.compute(11), nts::Tristate::Undefined);
}

Test(Gate4001, CheckUndefinedFalse11, .init = redirect_all_stdout)
{
    nts::Nor gate4001;
    nts::InputComponent inputComp1;
    nts::FalseComponent falseComp1;

    gate4001.setLink(12, inputComp1, 1);
    gate4001.setLink(13, falseComp1, 1);
    cr_assert_eq(gate4001.compute(11), nts::Tristate::Undefined);
}

Test(Gate4001, CheckUndefinedUndefined11, .init = redirect_all_stdout)
{
    nts::Nor gate4001;
    nts::InputComponent inputComp1;
    nts::InputComponent inputComp2;

    gate4001.setLink(12, inputComp1, 1);
    gate4001.setLink(13, inputComp2, 1);
    cr_assert_eq(gate4001.compute(11), nts::Tristate::Undefined);
}

Test(Gate4011, CheckTrueTrue, .init = redirect_all_stdout)
{
    nts::Nand gate4011;
    nts::TrueComponent trueComp1;
    nts::TrueComponent trueComp2;

    gate4011.setLink(1, trueComp1, 1);
    gate4011.setLink(2, trueComp2, 1);
    cr_assert_eq(gate4011.compute(3), nts::Tristate::False);
}

Test(Gate4011, CheckTrueFalse, .init = redirect_all_stdout)
{
    nts::Nand gate4011;
    nts::TrueComponent trueComp1;
    nts::FalseComponent falseComp1;

    gate4011.setLink(1, trueComp1, 1);
    gate4011.setLink(2, falseComp1, 1);
    cr_assert_eq(gate4011.compute(3), nts::Tristate::True);
}

Test(Gate4011, CheckFalseTrue, .init = redirect_all_stdout)
{
    nts::Nand gate4011;
    nts::FalseComponent falseComp1;
    nts::TrueComponent trueComp1;

    gate4011.setLink(1, falseComp1, 1);
    gate4011.setLink(2, trueComp1, 1);
    cr_assert_eq(gate4011.compute(3), nts::Tristate::True);
}

Test(Gate4011, CheckFalseFalse, .init = redirect_all_stdout)
{
    nts::Nand gate4011;
    nts::FalseComponent falseComp1;
    nts::FalseComponent falseComp2;

    gate4011.setLink(1, falseComp1, 1);
    gate4011.setLink(2, falseComp2, 1);
    cr_assert_eq(gate4011.compute(3), nts::Tristate::True);
}

Test(Gate4011, CheckUndefinedTrue, .init = redirect_all_stdout)
{
    nts::Nand gate4011;
    nts::InputComponent inputComp1;
    nts::TrueComponent trueComp1;

    gate4011.setLink(1, inputComp1, 1);
    gate4011.setLink(2, trueComp1, 1);
    cr_assert_eq(gate4011.compute(3), nts::Tristate::Undefined);
}

Test(Gate4011, CheckUndefinedFalse, .init = redirect_all_stdout)
{
    nts::Nand gate4011;
    nts::InputComponent inputComp1;
    nts::FalseComponent falseComp1;

    gate4011.setLink(1, inputComp1, 1);
    gate4011.setLink(2, falseComp1, 1);
    cr_assert_eq(gate4011.compute(3), nts::Tristate::Undefined);
}

Test(Gate4011, CheckUndefinedUndefined, .init = redirect_all_stdout)
{
    nts::Nand gate4011;
    nts::InputComponent inputComp1;
    nts::InputComponent inputComp2;

    gate4011.setLink(1, inputComp1, 1);
    gate4011.setLink(2, inputComp2, 1);
    cr_assert_eq(gate4011.compute(3), nts::Tristate::Undefined);
}

Test(Gate4011, CheckTrueTrue4, .init = redirect_all_stdout)
{
    nts::Nand gate4011;
    nts::TrueComponent trueComp1;
    nts::TrueComponent trueComp2;

    gate4011.setLink(5, trueComp1, 1);
    gate4011.setLink(6, trueComp2, 1);
    cr_assert_eq(gate4011.compute(4), nts::Tristate::False);
}

Test(Gate4011, CheckTrueFalse4, .init = redirect_all_stdout)
{
    nts::Nand gate4011;
    nts::TrueComponent trueComp1;
    nts::FalseComponent falseComp1;

    gate4011.setLink(5, trueComp1, 1);
    gate4011.setLink(6, falseComp1, 1);
    cr_assert_eq(gate4011.compute(4), nts::Tristate::True);
}

Test(Gate4011, CheckFalseTrue4, .init = redirect_all_stdout)
{
    nts::Nand gate4011;
    nts::FalseComponent falseComp1;
    nts::TrueComponent trueComp1;

    gate4011.setLink(5, falseComp1, 1);
    gate4011.setLink(6, trueComp1, 1);
    cr_assert_eq(gate4011.compute(4), nts::Tristate::True);
}

Test(Gate4011, CheckFalseFalse4, .init = redirect_all_stdout)
{
    nts::Nand gate4011;
    nts::FalseComponent falseComp1;
    nts::FalseComponent falseComp2;

    gate4011.setLink(5, falseComp1, 1);
    gate4011.setLink(6, falseComp2, 1);
    cr_assert_eq(gate4011.compute(4), nts::Tristate::True);
}

Test(Gate4011, CheckUndefinedTrue4, .init = redirect_all_stdout)
{
    nts::Nand gate4011;
    nts::InputComponent inputComp1;
    nts::TrueComponent trueComp1;

    gate4011.setLink(5, inputComp1, 1);
    gate4011.setLink(6, trueComp1, 1);
    cr_assert_eq(gate4011.compute(4), nts::Tristate::Undefined);
}

Test(Gate4011, CheckUndefinedFalse4, .init = redirect_all_stdout)
{
    nts::Nand gate4011;
    nts::InputComponent inputComp1;
    nts::FalseComponent falseComp1;

    gate4011.setLink(5, inputComp1, 1);
    gate4011.setLink(6, falseComp1, 1);
    cr_assert_eq(gate4011.compute(4), nts::Tristate::Undefined);
}

Test(Gate4011, CheckUndefinedUndefined4, .init = redirect_all_stdout)
{
    nts::Nand gate4011;
    nts::InputComponent inputComp1;
    nts::InputComponent inputComp2;

    gate4011.setLink(5, inputComp1, 1);
    gate4011.setLink(6, inputComp2, 1);
    cr_assert_eq(gate4011.compute(4), nts::Tristate::Undefined);
}

Test(Gate4011, CheckTrueTrue10, .init = redirect_all_stdout)
{
    nts::Nand gate4011;
    nts::TrueComponent trueComp1;
    nts::TrueComponent trueComp2;

    gate4011.setLink(8, trueComp1, 1);
    gate4011.setLink(9, trueComp2, 1);
    cr_assert_eq(gate4011.compute(10), nts::Tristate::False);
}

Test(Gate4011, CheckTrueFalse10, .init = redirect_all_stdout)
{
    nts::Nand gate4011;
    nts::TrueComponent trueComp1;
    nts::FalseComponent falseComp1;

    gate4011.setLink(8, trueComp1, 1);
    gate4011.setLink(9, falseComp1, 1);
    cr_assert_eq(gate4011.compute(10), nts::Tristate::True);
}

Test(Gate4011, CheckFalseTrue10, .init = redirect_all_stdout)
{
    nts::Nand gate4011;
    nts::FalseComponent falseComp1;
    nts::TrueComponent trueComp1;

    gate4011.setLink(8, falseComp1, 1);
    gate4011.setLink(9, trueComp1, 1);
    cr_assert_eq(gate4011.compute(10), nts::Tristate::True);
}

Test(Gate4011, CheckFalseFalse10, .init = redirect_all_stdout)
{
    nts::Nand gate4011;
    nts::FalseComponent falseComp1;
    nts::FalseComponent falseComp2;

    gate4011.setLink(8, falseComp1, 1);
    gate4011.setLink(9, falseComp2, 1);
    cr_assert_eq(gate4011.compute(10), nts::Tristate::True);
}

Test(Gate4011, CheckUndefinedTrue10, .init = redirect_all_stdout)
{
    nts::Nand gate4011;
    nts::InputComponent inputComp1;
    nts::TrueComponent trueComp1;

    gate4011.setLink(8, inputComp1, 1);
    gate4011.setLink(9, trueComp1, 1);
    cr_assert_eq(gate4011.compute(10), nts::Tristate::Undefined);
}

Test(Gate4011, CheckUndefinedFalse10, .init = redirect_all_stdout)
{
    nts::Nand gate4011;
    nts::InputComponent inputComp1;
    nts::FalseComponent falseComp1;

    gate4011.setLink(8, inputComp1, 1);
    gate4011.setLink(9, falseComp1, 1);
    cr_assert_eq(gate4011.compute(10), nts::Tristate::Undefined);
}

Test(Gate4011, CheckUndefinedUndefined10, .init = redirect_all_stdout)
{
    nts::Nand gate4011;
    nts::InputComponent inputComp1;
    nts::InputComponent inputComp2;

    gate4011.setLink(8, inputComp1, 1);
    gate4011.setLink(9, inputComp2, 1);
    cr_assert_eq(gate4011.compute(10), nts::Tristate::Undefined);
}

Test(Gate4011, CheckTrueTrue11, .init = redirect_all_stdout)
{
    nts::Nand gate4011;
    nts::TrueComponent trueComp1;
    nts::TrueComponent trueComp2;

    gate4011.setLink(12, trueComp1, 1);
    gate4011.setLink(13, trueComp2, 1);
    cr_assert_eq(gate4011.compute(11), nts::Tristate::False);
}

Test(Gate4011, CheckTrueFalse11, .init = redirect_all_stdout)
{
    nts::Nand gate4011;
    nts::TrueComponent trueComp1;
    nts::FalseComponent falseComp1;

    gate4011.setLink(12, trueComp1, 1);
    gate4011.setLink(13, falseComp1, 1);
    cr_assert_eq(gate4011.compute(11), nts::Tristate::True);
}

Test(Gate4011, CheckFalseTrue11, .init = redirect_all_stdout)
{
    nts::Nand gate4011;
    nts::FalseComponent falseComp1;
    nts::TrueComponent trueComp1;

    gate4011.setLink(12, falseComp1, 1);
    gate4011.setLink(13, trueComp1, 1);
    cr_assert_eq(gate4011.compute(11), nts::Tristate::True);
}

Test(Gate4011, CheckFalseFalse11, .init = redirect_all_stdout)
{
    nts::Nand gate4011;
    nts::FalseComponent falseComp1;
    nts::FalseComponent falseComp2;

    gate4011.setLink(12, falseComp1, 1);
    gate4011.setLink(13, falseComp2, 1);
    cr_assert_eq(gate4011.compute(11), nts::Tristate::True);
}

Test(Gate4011, CheckUndefinedTrue11, .init = redirect_all_stdout)
{
    nts::Nand gate4011;
    nts::InputComponent inputComp1;
    nts::TrueComponent trueComp1;

    gate4011.setLink(12, inputComp1, 1);
    gate4011.setLink(13, trueComp1, 1);
    cr_assert_eq(gate4011.compute(11), nts::Tristate::Undefined);
}

Test(Gate4011, CheckUndefinedFalse11, .init = redirect_all_stdout)
{
    nts::Nand gate4011;
    nts::InputComponent inputComp1;
    nts::FalseComponent falseComp1;

    gate4011.setLink(12, inputComp1, 1);
    gate4011.setLink(13, falseComp1, 1);
    cr_assert_eq(gate4011.compute(11), nts::Tristate::Undefined);
}

Test(Gate4011, CheckUndefinedUndefined11, .init = redirect_all_stdout)
{
    nts::Nand gate4011;
    nts::InputComponent inputComp1;
    nts::InputComponent inputComp2;

    gate4011.setLink(12, inputComp1, 1);
    gate4011.setLink(13, inputComp2, 1);
    cr_assert_eq(gate4011.compute(11), nts::Tristate::Undefined);
}

Test(Gate4030, CheckTrueTrue, .init = redirect_all_stdout)
{
    nts::Xor4 gate4030;
    nts::TrueComponent trueComp1;
    nts::TrueComponent trueComp2;

    gate4030.setLink(1, trueComp1, 1);
    gate4030.setLink(2, trueComp2, 1);
    cr_assert_eq(gate4030.compute(3), nts::Tristate::False);
}

Test(Gate4030, CheckTrueFalse, .init = redirect_all_stdout)
{
    nts::Xor4 gate4030;
    nts::TrueComponent trueComp1;
    nts::FalseComponent falseComp1;

    gate4030.setLink(1, trueComp1, 1);
    gate4030.setLink(2, falseComp1, 1);
    cr_assert_eq(gate4030.compute(3), nts::Tristate::True);
}

Test(Gate4030, CheckFalseTrue, .init = redirect_all_stdout)
{
    nts::Xor4 gate4030;
    nts::FalseComponent falseComp1;
    nts::TrueComponent trueComp1;

    gate4030.setLink(1, falseComp1, 1);
    gate4030.setLink(2, trueComp1, 1);
    cr_assert_eq(gate4030.compute(3), nts::Tristate::True);
}

Test(Gate4030, CheckFalseFalse, .init = redirect_all_stdout)
{
    nts::Xor4 gate4030;
    nts::FalseComponent falseComp1;
    nts::FalseComponent falseComp2;

    gate4030.setLink(1, falseComp1, 1);
    gate4030.setLink(2, falseComp2, 1);
    cr_assert_eq(gate4030.compute(3), nts::Tristate::False);
}

Test(Gate4030, CheckUndefinedTrue, .init = redirect_all_stdout)
{
    nts::Xor4 gate4030;
    nts::InputComponent inputComp1;
    nts::TrueComponent trueComp1;

    gate4030.setLink(1, inputComp1, 1);
    gate4030.setLink(2, trueComp1, 1);
    cr_assert_eq(gate4030.compute(3), nts::Tristate::Undefined);
}

Test(Gate4030, CheckUndefinedFalse, .init = redirect_all_stdout)
{
    nts::Xor4 gate4030;
    nts::InputComponent inputComp1;
    nts::FalseComponent falseComp1;

    gate4030.setLink(1, inputComp1, 1);
    gate4030.setLink(2, falseComp1, 1);
    cr_assert_eq(gate4030.compute(3), nts::Tristate::Undefined);
}

Test(Gate4030, CheckUndefinedUndefined, .init = redirect_all_stdout)
{
    nts::Xor4 gate4030;
    nts::InputComponent inputComp1;
    nts::InputComponent inputComp2;

    gate4030.setLink(1, inputComp1, 1);
    gate4030.setLink(2, inputComp2, 1);
    cr_assert_eq(gate4030.compute(3), nts::Tristate::Undefined);
}

Test(Gate4030, CheckTrueTrue4, .init = redirect_all_stdout)
{
    nts::Xor4 gate4030;
    nts::TrueComponent trueComp1;
    nts::TrueComponent trueComp2;

    gate4030.setLink(5, trueComp1, 1);
    gate4030.setLink(6, trueComp2, 1);
    cr_assert_eq(gate4030.compute(4), nts::Tristate::False);
}

Test(Gate4030, CheckTrueFalse4, .init = redirect_all_stdout)
{
    nts::Xor4 gate4030;
    nts::TrueComponent trueComp1;
    nts::FalseComponent falseComp1;

    gate4030.setLink(5, trueComp1, 1);
    gate4030.setLink(6, falseComp1, 1);
    cr_assert_eq(gate4030.compute(4), nts::Tristate::True);
}

Test(Gate4030, CheckFalseTrue4, .init = redirect_all_stdout)
{
    nts::Xor4 gate4030;
    nts::FalseComponent falseComp1;
    nts::TrueComponent trueComp1;

    gate4030.setLink(5, falseComp1, 1);
    gate4030.setLink(6, trueComp1, 1);
    cr_assert_eq(gate4030.compute(4), nts::Tristate::True);
}

Test(Gate4030, CheckFalseFalse4, .init = redirect_all_stdout)
{
    nts::Xor4 gate4030;
    nts::FalseComponent falseComp1;
    nts::FalseComponent falseComp2;

    gate4030.setLink(5, falseComp1, 1);
    gate4030.setLink(6, falseComp2, 1);
    cr_assert_eq(gate4030.compute(4), nts::Tristate::False);
}

Test(Gate4030, CheckUndefinedTrue4, .init = redirect_all_stdout)
{
    nts::Xor4 gate4030;
    nts::InputComponent inputComp1;
    nts::TrueComponent trueComp1;

    gate4030.setLink(5, inputComp1, 1);
    gate4030.setLink(6, trueComp1, 1);
    cr_assert_eq(gate4030.compute(4), nts::Tristate::Undefined);
}

Test(Gate4030, CheckUndefinedFalse4, .init = redirect_all_stdout)
{
    nts::Xor4 gate4030;
    nts::InputComponent inputComp1;
    nts::FalseComponent falseComp1;

    gate4030.setLink(5, inputComp1, 1);
    gate4030.setLink(6, falseComp1, 1);
    cr_assert_eq(gate4030.compute(4), nts::Tristate::Undefined);
}

Test(Gate4030, CheckUndefinedUndefined4, .init = redirect_all_stdout)
{
    nts::Xor4 gate4030;
    nts::InputComponent inputComp1;
    nts::InputComponent inputComp2;

    gate4030.setLink(5, inputComp1, 1);
    gate4030.setLink(6, inputComp2, 1);
    cr_assert_eq(gate4030.compute(4), nts::Tristate::Undefined);
}

Test(Gate4030, CheckTrueTrue10, .init = redirect_all_stdout)
{
    nts::Xor4 gate4030;
    nts::TrueComponent trueComp1;
    nts::TrueComponent trueComp2;

    gate4030.setLink(8, trueComp1, 1);
    gate4030.setLink(9, trueComp2, 1);
    cr_assert_eq(gate4030.compute(10), nts::Tristate::False);
}

Test(Gate4030, CheckTrueFalse10, .init = redirect_all_stdout)
{
    nts::Xor4 gate4030;
    nts::TrueComponent trueComp1;
    nts::FalseComponent falseComp1;

    gate4030.setLink(8, trueComp1, 1);
    gate4030.setLink(9, falseComp1, 1);
    cr_assert_eq(gate4030.compute(10), nts::Tristate::True);
}

Test(Gate4030, CheckFalseTrue10, .init = redirect_all_stdout)
{
    nts::Xor4 gate4030;
    nts::FalseComponent falseComp1;
    nts::TrueComponent trueComp1;

    gate4030.setLink(8, falseComp1, 1);
    gate4030.setLink(9, trueComp1, 1);
    cr_assert_eq(gate4030.compute(10), nts::Tristate::True);
}

Test(Gate4030, CheckFalseFalse10, .init = redirect_all_stdout)
{
    nts::Xor4 gate4030;
    nts::FalseComponent falseComp1;
    nts::FalseComponent falseComp2;

    gate4030.setLink(8, falseComp1, 1);
    gate4030.setLink(9, falseComp2, 1);
    cr_assert_eq(gate4030.compute(10), nts::Tristate::False);
}

Test(Gate4030, CheckUndefinedTrue10, .init = redirect_all_stdout)
{
    nts::Xor4 gate4030;
    nts::InputComponent inputComp1;
    nts::TrueComponent trueComp1;

    gate4030.setLink(8, inputComp1, 1);
    gate4030.setLink(9, trueComp1, 1);
    cr_assert_eq(gate4030.compute(10), nts::Tristate::Undefined);
}

Test(Gate4030, CheckUndefinedFalse10, .init = redirect_all_stdout)
{
    nts::Xor4 gate4030;
    nts::InputComponent inputComp1;
    nts::FalseComponent falseComp1;

    gate4030.setLink(8, inputComp1, 1);
    gate4030.setLink(9, falseComp1, 1);
    cr_assert_eq(gate4030.compute(10), nts::Tristate::Undefined);
}

Test(Gate4030, CheckUndefinedUndefined10, .init = redirect_all_stdout)
{
    nts::Xor4 gate4030;
    nts::InputComponent inputComp1;
    nts::InputComponent inputComp2;

    gate4030.setLink(8, inputComp1, 1);
    gate4030.setLink(9, inputComp2, 1);
    cr_assert_eq(gate4030.compute(10), nts::Tristate::Undefined);
}

Test(Gate4030, CheckTrueTrue11, .init = redirect_all_stdout)
{
    nts::Xor4 gate4030;
    nts::TrueComponent trueComp1;
    nts::TrueComponent trueComp2;

    gate4030.setLink(12, trueComp1, 1);
    gate4030.setLink(13, trueComp2, 1);
    cr_assert_eq(gate4030.compute(11), nts::Tristate::False);
}

Test(Gate4030, CheckTrueFalse11, .init = redirect_all_stdout)
{
    nts::Xor4 gate4030;
    nts::TrueComponent trueComp1;
    nts::FalseComponent falseComp1;

    gate4030.setLink(12, trueComp1, 1);
    gate4030.setLink(13, falseComp1, 1);
    cr_assert_eq(gate4030.compute(11), nts::Tristate::True);
}

Test(Gate4030, CheckFalseTrue11, .init = redirect_all_stdout)
{
    nts::Xor4 gate4030;
    nts::FalseComponent falseComp1;
    nts::TrueComponent trueComp1;

    gate4030.setLink(12, falseComp1, 1);
    gate4030.setLink(13, trueComp1, 1);
    cr_assert_eq(gate4030.compute(11), nts::Tristate::True);
}

Test(Gate4030, CheckFalseFalse11, .init = redirect_all_stdout)
{
    nts::Xor4 gate4030;
    nts::FalseComponent falseComp1;
    nts::FalseComponent falseComp2;

    gate4030.setLink(12, falseComp1, 1);
    gate4030.setLink(13, falseComp2, 1);
    cr_assert_eq(gate4030.compute(11), nts::Tristate::False);
}

Test(Gate4030, CheckUndefinedTrue11, .init = redirect_all_stdout)
{
    nts::Xor4 gate4030;
    nts::InputComponent inputComp1;
    nts::TrueComponent trueComp1;

    gate4030.setLink(12, inputComp1, 1);
    gate4030.setLink(13, trueComp1, 1);
    cr_assert_eq(gate4030.compute(11), nts::Tristate::Undefined);
}

Test(Gate4030, CheckUndefinedFalse11, .init = redirect_all_stdout)
{
    nts::Xor4 gate4030;
    nts::InputComponent inputComp1;
    nts::FalseComponent falseComp1;

    gate4030.setLink(12, inputComp1, 1);
    gate4030.setLink(13, falseComp1, 1);
    cr_assert_eq(gate4030.compute(11), nts::Tristate::Undefined);
}

Test(Gate4030, CheckUndefinedUndefined11, .init = redirect_all_stdout)
{
    nts::Xor4 gate4030;
    nts::InputComponent inputComp1;
    nts::InputComponent inputComp2;

    gate4030.setLink(12, inputComp1, 1);
    gate4030.setLink(13, inputComp2, 1);
    cr_assert_eq(gate4030.compute(11), nts::Tristate::Undefined);
}

Test(Gate4069, CheckTrue, .init = redirect_all_stdout)
{
    nts::Inverter gate4069;
    nts::TrueComponent trueComp1;

    gate4069.setLink(1, trueComp1, 1);
    cr_assert_eq(gate4069.compute(2), nts::Tristate::False);
}

Test(Gate4069, CheckFalse, .init = redirect_all_stdout)
{
    nts::Inverter gate4069;
    nts::FalseComponent falseComp1;

    gate4069.setLink(1, falseComp1, 1);
    cr_assert_eq(gate4069.compute(2), nts::Tristate::True);
}

Test(Gate4069, CheckUndefined, .init = redirect_all_stdout)
{
    nts::Inverter gate4069;
    nts::InputComponent inputComp1;

    gate4069.setLink(1, inputComp1, 1);
    cr_assert_eq(gate4069.compute(2), nts::Tristate::Undefined);
}

Test(Gate4069, CheckTrue4, .init = redirect_all_stdout)
{
    nts::Inverter gate4069;
    nts::TrueComponent trueComp1;

    gate4069.setLink(3, trueComp1, 1);
    cr_assert_eq(gate4069.compute(4), nts::Tristate::False);
}

Test(Gate4069, CheckFalse4, .init = redirect_all_stdout)
{
    nts::Inverter gate4069;
    nts::FalseComponent falseComp1;

    gate4069.setLink(3, falseComp1, 1);
    cr_assert_eq(gate4069.compute(4), nts::Tristate::True);
}

Test(Gate4069, CheckUndefined4, .init = redirect_all_stdout)
{
    nts::Inverter gate4069;
    nts::InputComponent inputComp1;

    gate4069.setLink(3, inputComp1, 1);
    cr_assert_eq(gate4069.compute(4), nts::Tristate::Undefined);
}

Test(Gate4069, CheckTrue6, .init = redirect_all_stdout)
{
    nts::Inverter gate4069;
    nts::TrueComponent trueComp1;

    gate4069.setLink(5, trueComp1, 1);
    cr_assert_eq(gate4069.compute(6), nts::Tristate::False);
}

Test(Gate4069, CheckFalse6, .init = redirect_all_stdout)
{
    nts::Inverter gate4069;
    nts::FalseComponent falseComp1;

    gate4069.setLink(5, falseComp1, 1);
    cr_assert_eq(gate4069.compute(6), nts::Tristate::True);
}

Test(Gate4069, CheckUndefined6, .init = redirect_all_stdout)
{
    nts::Inverter gate4069;
    nts::InputComponent inputComp1;

    gate4069.setLink(5, inputComp1, 1);
    cr_assert_eq(gate4069.compute(6), nts::Tristate::Undefined);
}

Test(Gate4069, CheckTrue8, .init = redirect_all_stdout)
{
    nts::Inverter gate4069;
    nts::TrueComponent trueComp1;

    gate4069.setLink(9, trueComp1, 1);
    cr_assert_eq(gate4069.compute(8), nts::Tristate::False);
}

Test(Gate4069, CheckFalse8, .init = redirect_all_stdout)
{
    nts::Inverter gate4069;
    nts::FalseComponent falseComp1;

    gate4069.setLink(9, falseComp1, 1);
    cr_assert_eq(gate4069.compute(8), nts::Tristate::True);
}

Test(Gate4069, CheckUndefined8, .init = redirect_all_stdout)
{
    nts::Inverter gate4069;
    nts::InputComponent inputComp1;

    gate4069.setLink(9, inputComp1, 1);
    cr_assert_eq(gate4069.compute(8), nts::Tristate::Undefined);
}

Test(Gate4069, CheckTrue10, .init = redirect_all_stdout)
{
    nts::Inverter gate4069;
    nts::TrueComponent trueComp1;

    gate4069.setLink(11, trueComp1, 1);
    cr_assert_eq(gate4069.compute(10), nts::Tristate::False);
}

Test(Gate4069, CheckFalse10, .init = redirect_all_stdout)
{
    nts::Inverter gate4069;
    nts::FalseComponent falseComp1;

    gate4069.setLink(11, falseComp1, 1);
    cr_assert_eq(gate4069.compute(10), nts::Tristate::True);
}

Test(Gate4069, CheckUndefined10, .init = redirect_all_stdout)
{
    nts::Inverter gate4069;
    nts::InputComponent inputComp1;

    gate4069.setLink(11, inputComp1, 1);
    cr_assert_eq(gate4069.compute(10), nts::Tristate::Undefined);
}

Test(Gate4069, CheckTrue12, .init = redirect_all_stdout)
{
    nts::Inverter gate4069;
    nts::TrueComponent trueComp1;

    gate4069.setLink(13, trueComp1, 1);
    cr_assert_eq(gate4069.compute(12), nts::Tristate::False);
}

Test(Gate4069, CheckFalse12, .init = redirect_all_stdout)
{
    nts::Inverter gate4069;
    nts::FalseComponent falseComp1;

    gate4069.setLink(13, falseComp1, 1);
    cr_assert_eq(gate4069.compute(12), nts::Tristate::True);
}

Test(Gate4069, CheckUndefined12, .init = redirect_all_stdout)
{
    nts::Inverter gate4069;
    nts::InputComponent inputComp1;

    gate4069.setLink(13, inputComp1, 1);
    cr_assert_eq(gate4069.compute(12), nts::Tristate::Undefined);
}

Test(Gate4071, CheckTrueTrue, .init = redirect_all_stdout)
{
    nts::Or4 gate4071;
    nts::TrueComponent trueComp1;
    nts::TrueComponent trueComp2;

    gate4071.setLink(1, trueComp1, 1);
    gate4071.setLink(2, trueComp2, 1);
    cr_assert_eq(gate4071.compute(3), nts::Tristate::True);
}

Test(Gate4071, CheckTrueFalse, .init = redirect_all_stdout)
{
    nts::Or4 gate4071;
    nts::TrueComponent trueComp1;
    nts::FalseComponent falseComp1;

    gate4071.setLink(1, trueComp1, 1);
    gate4071.setLink(2, falseComp1, 1);
    cr_assert_eq(gate4071.compute(3), nts::Tristate::True);
}

Test(Gate4071, CheckFalseTrue, .init = redirect_all_stdout)
{
    nts::Or4 gate4071;
    nts::FalseComponent falseComp1;
    nts::TrueComponent trueComp1;

    gate4071.setLink(1, falseComp1, 1);
    gate4071.setLink(2, trueComp1, 1);
    cr_assert_eq(gate4071.compute(3), nts::Tristate::True);
}

Test(Gate4071, CheckFalseFalse, .init = redirect_all_stdout)
{
    nts::Or4 gate4071;
    nts::FalseComponent falseComp1;
    nts::FalseComponent falseComp2;

    gate4071.setLink(1, falseComp1, 1);
    gate4071.setLink(2, falseComp2, 1);
    cr_assert_eq(gate4071.compute(3), nts::Tristate::False);
}

Test(Gate4071, CheckUndefinedTrue, .init = redirect_all_stdout)
{
    nts::Or4 gate4071;
    nts::InputComponent inputComp1;
    nts::TrueComponent trueComp1;

    gate4071.setLink(1, inputComp1, 1);
    gate4071.setLink(2, trueComp1, 1);
    cr_assert_eq(gate4071.compute(3), nts::Tristate::True);
}

Test(Gate4071, CheckUndefinedFalse, .init = redirect_all_stdout)
{
    nts::Or4 gate4071;
    nts::InputComponent inputComp1;
    nts::FalseComponent falseComp1;

    gate4071.setLink(1, inputComp1, 1);
    gate4071.setLink(2, falseComp1, 1);
    cr_assert_eq(gate4071.compute(3), nts::Tristate::Undefined);
}

Test(Gate4071, CheckUndefinedUndefined, .init = redirect_all_stdout)
{
    nts::Or4 gate4071;
    nts::InputComponent inputComp1;
    nts::InputComponent inputComp2;

    gate4071.setLink(1, inputComp1, 1);
    gate4071.setLink(2, inputComp2, 1);
    cr_assert_eq(gate4071.compute(3), nts::Tristate::Undefined);
}

Test(Gate4071, CheckTrueTrue4, .init = redirect_all_stdout)
{
    nts::Or4 gate4071;
    nts::TrueComponent trueComp1;
    nts::TrueComponent trueComp2;

    gate4071.setLink(5, trueComp1, 1);
    gate4071.setLink(6, trueComp2, 1);
    cr_assert_eq(gate4071.compute(4), nts::Tristate::True);
}

Test(Gate4071, CheckTrueFalse4, .init = redirect_all_stdout)
{
    nts::Or4 gate4071;
    nts::TrueComponent trueComp1;
    nts::FalseComponent falseComp1;

    gate4071.setLink(5, trueComp1, 1);
    gate4071.setLink(6, falseComp1, 1);
    cr_assert_eq(gate4071.compute(4), nts::Tristate::True);
}

Test(Gate4071, CheckFalseTrue4, .init = redirect_all_stdout)
{
    nts::Or4 gate4071;
    nts::FalseComponent falseComp1;
    nts::TrueComponent trueComp1;

    gate4071.setLink(5, falseComp1, 1);
    gate4071.setLink(6, trueComp1, 1);
    cr_assert_eq(gate4071.compute(4), nts::Tristate::True);
}

Test(Gate4071, CheckFalseFalse4, .init = redirect_all_stdout)
{
    nts::Or4 gate4071;
    nts::FalseComponent falseComp1;
    nts::FalseComponent falseComp2;

    gate4071.setLink(5, falseComp1, 1);
    gate4071.setLink(6, falseComp2, 1);
    cr_assert_eq(gate4071.compute(4), nts::Tristate::False);
}

Test(Gate4071, CheckUndefinedTrue4, .init = redirect_all_stdout)
{
    nts::Or4 gate4071;
    nts::InputComponent inputComp1;
    nts::TrueComponent trueComp1;

    gate4071.setLink(5, inputComp1, 1);
    gate4071.setLink(6, trueComp1, 1);
    cr_assert_eq(gate4071.compute(4), nts::Tristate::True);
}

Test(Gate4071, CheckUndefinedFalse4, .init = redirect_all_stdout)
{
    nts::Or4 gate4071;
    nts::InputComponent inputComp1;
    nts::FalseComponent falseComp1;

    gate4071.setLink(5, inputComp1, 1);
    gate4071.setLink(6, falseComp1, 1);
    cr_assert_eq(gate4071.compute(4), nts::Tristate::Undefined);
}

Test(Gate4071, CheckUndefinedUndefined4, .init = redirect_all_stdout)
{
    nts::Or4 gate4071;
    nts::InputComponent inputComp1;
    nts::InputComponent inputComp2;

    gate4071.setLink(5, inputComp1, 1);
    gate4071.setLink(6, inputComp2, 1);
    cr_assert_eq(gate4071.compute(4), nts::Tristate::Undefined);
}

Test(Gate4071, CheckTrueTrue10, .init = redirect_all_stdout)
{
    nts::Or4 gate4071;
    nts::TrueComponent trueComp1;
    nts::TrueComponent trueComp2;

    gate4071.setLink(8, trueComp1, 1);
    gate4071.setLink(9, trueComp2, 1);
    cr_assert_eq(gate4071.compute(10), nts::Tristate::True);
}

Test(Gate4071, CheckTrueFalse10, .init = redirect_all_stdout)
{
    nts::Or4 gate4071;
    nts::TrueComponent trueComp1;
    nts::FalseComponent falseComp1;

    gate4071.setLink(8, trueComp1, 1);
    gate4071.setLink(9, falseComp1, 1);
    cr_assert_eq(gate4071.compute(10), nts::Tristate::True);
}

Test(Gate4071, CheckFalseTrue10, .init = redirect_all_stdout)
{
    nts::Or4 gate4071;
    nts::FalseComponent falseComp1;
    nts::TrueComponent trueComp1;

    gate4071.setLink(8, falseComp1, 1);
    gate4071.setLink(9, trueComp1, 1);
    cr_assert_eq(gate4071.compute(10), nts::Tristate::True);
}

Test(Gate4071, CheckFalseFalse10, .init = redirect_all_stdout)
{
    nts::Or4 gate4071;
    nts::FalseComponent falseComp1;
    nts::FalseComponent falseComp2;

    gate4071.setLink(8, falseComp1, 1);
    gate4071.setLink(9, falseComp2, 1);
    cr_assert_eq(gate4071.compute(10), nts::Tristate::False);
}

Test(Gate4071, CheckUndefinedTrue10, .init = redirect_all_stdout)
{
    nts::Or4 gate4071;
    nts::InputComponent inputComp1;
    nts::TrueComponent trueComp1;

    gate4071.setLink(8, inputComp1, 1);
    gate4071.setLink(9, trueComp1, 1);
    cr_assert_eq(gate4071.compute(10), nts::Tristate::True);
}

Test(Gate4071, CheckUndefinedFalse10, .init = redirect_all_stdout)
{
    nts::Or4 gate4071;
    nts::InputComponent inputComp1;
    nts::FalseComponent falseComp1;

    gate4071.setLink(8, inputComp1, 1);
    gate4071.setLink(9, falseComp1, 1);
    cr_assert_eq(gate4071.compute(10), nts::Tristate::Undefined);
}

Test(Gate4071, CheckUndefinedUndefined10, .init = redirect_all_stdout)
{
    nts::Or4 gate4071;
    nts::InputComponent inputComp1;
    nts::InputComponent inputComp2;

    gate4071.setLink(8, inputComp1, 1);
    gate4071.setLink(9, inputComp2, 1);
    cr_assert_eq(gate4071.compute(10), nts::Tristate::Undefined);
}

Test(Gate4071, CheckTrueTrue11, .init = redirect_all_stdout)
{
    nts::Or4 gate4071;
    nts::TrueComponent trueComp1;
    nts::TrueComponent trueComp2;

    gate4071.setLink(12, trueComp1, 1);
    gate4071.setLink(13, trueComp2, 1);
    cr_assert_eq(gate4071.compute(11), nts::Tristate::True);
}

Test(Gate4071, CheckTrueFalse11, .init = redirect_all_stdout)
{
    nts::Or4 gate4071;
    nts::TrueComponent trueComp1;
    nts::FalseComponent falseComp1;

    gate4071.setLink(12, trueComp1, 1);
    gate4071.setLink(13, falseComp1, 1);
    cr_assert_eq(gate4071.compute(11), nts::Tristate::True);
}

Test(Gate4071, CheckFalseTrue11, .init = redirect_all_stdout)
{
    nts::Or4 gate4071;
    nts::FalseComponent falseComp1;
    nts::TrueComponent trueComp1;

    gate4071.setLink(12, falseComp1, 1);
    gate4071.setLink(13, trueComp1, 1);
    cr_assert_eq(gate4071.compute(11), nts::Tristate::True);
}

Test(Gate4071, CheckFalseFalse11, .init = redirect_all_stdout)
{
    nts::Or4 gate4071;
    nts::FalseComponent falseComp1;
    nts::FalseComponent falseComp2;

    gate4071.setLink(12, falseComp1, 1);
    gate4071.setLink(13, falseComp2, 1);
    cr_assert_eq(gate4071.compute(11), nts::Tristate::False);
}

Test(Gate4071, CheckUndefinedTrue11, .init = redirect_all_stdout)
{
    nts::Or4 gate4071;
    nts::InputComponent inputComp1;
    nts::TrueComponent trueComp1;

    gate4071.setLink(12, inputComp1, 1);
    gate4071.setLink(13, trueComp1, 1);
    cr_assert_eq(gate4071.compute(11), nts::Tristate::True);
}

Test(Gate4071, CheckUndefinedFalse11, .init = redirect_all_stdout)
{
    nts::Or4 gate4071;
    nts::InputComponent inputComp1;
    nts::FalseComponent falseComp1;

    gate4071.setLink(12, inputComp1, 1);
    gate4071.setLink(13, falseComp1, 1);
    cr_assert_eq(gate4071.compute(11), nts::Tristate::Undefined);
}

Test(Gate4071, CheckUndefinedUndefined11, .init = redirect_all_stdout)
{
    nts::Or4 gate4071;
    nts::InputComponent inputComp1;
    nts::InputComponent inputComp2;

    gate4071.setLink(12, inputComp1, 1);
    gate4071.setLink(13, inputComp2, 1);
    cr_assert_eq(gate4071.compute(11), nts::Tristate::Undefined);
}

Test(Gate4081, CheckTrueTrue, .init = redirect_all_stdout)
{
    nts::And4 gate4081;
    nts::TrueComponent trueComp1;
    nts::TrueComponent trueComp2;

    gate4081.setLink(1, trueComp1, 1);
    gate4081.setLink(2, trueComp2, 1);
    cr_assert_eq(gate4081.compute(3), nts::Tristate::True);
}

Test(Gate4081, CheckTrueFalse, .init = redirect_all_stdout)
{
    nts::And4 gate4081;
    nts::TrueComponent trueComp1;
    nts::FalseComponent falseComp1;

    gate4081.setLink(1, trueComp1, 1);
    gate4081.setLink(2, falseComp1, 1);
    cr_assert_eq(gate4081.compute(3), nts::Tristate::False);
}

Test(Gate4081, CheckFalseTrue, .init = redirect_all_stdout)
{
    nts::And4 gate4081;
    nts::FalseComponent falseComp1;
    nts::TrueComponent trueComp1;

    gate4081.setLink(1, falseComp1, 1);
    gate4081.setLink(2, trueComp1, 1);
    cr_assert_eq(gate4081.compute(3), nts::Tristate::False);
}

Test(Gate4081, CheckFalseFalse, .init = redirect_all_stdout)
{
    nts::And4 gate4081;
    nts::FalseComponent falseComp1;
    nts::FalseComponent falseComp2;

    gate4081.setLink(1, falseComp1, 1);
    gate4081.setLink(2, falseComp2, 1);
    cr_assert_eq(gate4081.compute(3), nts::Tristate::False);
}

Test(Gate4081, CheckUndefinedTrue, .init = redirect_all_stdout)
{
    nts::And4 gate4081;
    nts::InputComponent inputComp1;
    nts::TrueComponent trueComp1;

    gate4081.setLink(1, inputComp1, 1);
    gate4081.setLink(2, trueComp1, 1);
    cr_assert_eq(gate4081.compute(3), nts::Tristate::Undefined);
}

Test(Gate4081, CheckUndefinedFalse, .init = redirect_all_stdout)
{
    nts::And4 gate4081;
    nts::InputComponent inputComp1;
    nts::FalseComponent falseComp1;

    gate4081.setLink(1, inputComp1, 1);
    gate4081.setLink(2, falseComp1, 1);
    cr_assert_eq(gate4081.compute(3), nts::Tristate::False);
}

Test(Gate4081, CheckUndefinedUndefined, .init = redirect_all_stdout)
{
    nts::And4 gate4081;
    nts::InputComponent inputComp1;
    nts::InputComponent inputComp2;

    gate4081.setLink(1, inputComp1, 1);
    gate4081.setLink(2, inputComp2, 1);
    cr_assert_eq(gate4081.compute(3), nts::Tristate::Undefined);
}

Test(Gate4081, CheckTrueTrue4, .init = redirect_all_stdout)
{
    nts::And4 gate4081;
    nts::TrueComponent trueComp1;
    nts::TrueComponent trueComp2;

    gate4081.setLink(5, trueComp1, 1);
    gate4081.setLink(6, trueComp2, 1);
    cr_assert_eq(gate4081.compute(4), nts::Tristate::True);
}

Test(Gate4081, CheckTrueFalse4, .init = redirect_all_stdout)
{
    nts::And4 gate4081;
    nts::TrueComponent trueComp1;
    nts::FalseComponent falseComp1;

    gate4081.setLink(5, trueComp1, 1);
    gate4081.setLink(6, falseComp1, 1);
    cr_assert_eq(gate4081.compute(4), nts::Tristate::False);
}

Test(Gate4081, CheckFalseTrue4, .init = redirect_all_stdout)
{
    nts::And4 gate4081;
    nts::FalseComponent falseComp1;
    nts::TrueComponent trueComp1;

    gate4081.setLink(5, falseComp1, 1);
    gate4081.setLink(6, trueComp1, 1);
    cr_assert_eq(gate4081.compute(4), nts::Tristate::False);
}

Test(Gate4081, CheckFalseFalse4, .init = redirect_all_stdout)
{
    nts::And4 gate4081;
    nts::FalseComponent falseComp1;
    nts::FalseComponent falseComp2;

    gate4081.setLink(5, falseComp1, 1);
    gate4081.setLink(6, falseComp2, 1);
    cr_assert_eq(gate4081.compute(4), nts::Tristate::False);
}

Test(Gate4081, CheckUndefinedTrue4, .init = redirect_all_stdout)
{
    nts::And4 gate4081;
    nts::InputComponent inputComp1;
    nts::TrueComponent trueComp1;

    gate4081.setLink(5, inputComp1, 1);
    gate4081.setLink(6, trueComp1, 1);
    cr_assert_eq(gate4081.compute(4), nts::Tristate::Undefined);
}

Test(Gate4081, CheckUndefinedFalse4, .init = redirect_all_stdout)
{
    nts::And4 gate4081;
    nts::InputComponent inputComp1;
    nts::FalseComponent falseComp1;

    gate4081.setLink(5, inputComp1, 1);
    gate4081.setLink(6, falseComp1, 1);
    cr_assert_eq(gate4081.compute(4), nts::Tristate::False);
}

Test(Gate4081, CheckUndefinedUndefined4, .init = redirect_all_stdout)
{
    nts::And4 gate4081;
    nts::InputComponent inputComp1;
    nts::InputComponent inputComp2;

    gate4081.setLink(5, inputComp1, 1);
    gate4081.setLink(6, inputComp2, 1);
    cr_assert_eq(gate4081.compute(4), nts::Tristate::Undefined);
}

Test(Gate4081, CheckTrueTrue10, .init = redirect_all_stdout)
{
    nts::And4 gate4081;
    nts::TrueComponent trueComp1;
    nts::TrueComponent trueComp2;

    gate4081.setLink(8, trueComp1, 1);
    gate4081.setLink(9, trueComp2, 1);
    cr_assert_eq(gate4081.compute(10), nts::Tristate::True);
}

Test(Gate4081, CheckTrueFalse10, .init = redirect_all_stdout)
{
    nts::And4 gate4081;
    nts::TrueComponent trueComp1;
    nts::FalseComponent falseComp1;

    gate4081.setLink(8, trueComp1, 1);
    gate4081.setLink(9, falseComp1, 1);
    cr_assert_eq(gate4081.compute(10), nts::Tristate::False);
}

Test(Gate4081, CheckFalseTrue10, .init = redirect_all_stdout)
{
    nts::And4 gate4081;
    nts::FalseComponent falseComp1;
    nts::TrueComponent trueComp1;

    gate4081.setLink(8, falseComp1, 1);
    gate4081.setLink(9, trueComp1, 1);
    cr_assert_eq(gate4081.compute(10), nts::Tristate::False);
}

Test(Gate4081, CheckFalseFalse10, .init = redirect_all_stdout)
{
    nts::And4 gate4081;
    nts::FalseComponent falseComp1;
    nts::FalseComponent falseComp2;

    gate4081.setLink(8, falseComp1, 1);
    gate4081.setLink(9, falseComp2, 1);
    cr_assert_eq(gate4081.compute(10), nts::Tristate::False);
}

Test(Gate4081, CheckUndefinedTrue10, .init = redirect_all_stdout)
{
    nts::And4 gate4081;
    nts::InputComponent inputComp1;
    nts::TrueComponent trueComp1;

    gate4081.setLink(8, inputComp1, 1);
    gate4081.setLink(9, trueComp1, 1);
    cr_assert_eq(gate4081.compute(10), nts::Tristate::Undefined);
}

Test(Gate4081, CheckUndefinedFalse10, .init = redirect_all_stdout)
{
    nts::And4 gate4081;
    nts::InputComponent inputComp1;
    nts::FalseComponent falseComp1;

    gate4081.setLink(8, inputComp1, 1);
    gate4081.setLink(9, falseComp1, 1);
    cr_assert_eq(gate4081.compute(10), nts::Tristate::False);
}

Test(Gate4081, CheckUndefinedUndefined10, .init = redirect_all_stdout)
{
    nts::And4 gate4081;
    nts::InputComponent inputComp1;
    nts::InputComponent inputComp2;

    gate4081.setLink(8, inputComp1, 1);
    gate4081.setLink(9, inputComp2, 1);
    cr_assert_eq(gate4081.compute(10), nts::Tristate::Undefined);
}

Test(Gate4081, CheckTrueTrue11, .init = redirect_all_stdout)
{
    nts::And4 gate4081;
    nts::TrueComponent trueComp1;
    nts::TrueComponent trueComp2;

    gate4081.setLink(12, trueComp1, 1);
    gate4081.setLink(13, trueComp2, 1);
    cr_assert_eq(gate4081.compute(11), nts::Tristate::True);
}

Test(Gate4081, CheckTrueFalse11, .init = redirect_all_stdout)
{
    nts::And4 gate4081;
    nts::TrueComponent trueComp1;
    nts::FalseComponent falseComp1;

    gate4081.setLink(12, trueComp1, 1);
    gate4081.setLink(13, falseComp1, 1);
    cr_assert_eq(gate4081.compute(11), nts::Tristate::False);
}

Test(Gate4081, CheckFalseTrue11, .init = redirect_all_stdout)
{
    nts::And4 gate4081;
    nts::FalseComponent falseComp1;
    nts::TrueComponent trueComp1;

    gate4081.setLink(12, falseComp1, 1);
    gate4081.setLink(13, trueComp1, 1);
    cr_assert_eq(gate4081.compute(11), nts::Tristate::False);
}

Test(Gate4081, CheckFalseFalse11, .init = redirect_all_stdout)
{
    nts::And4 gate4081;
    nts::FalseComponent falseComp1;
    nts::FalseComponent falseComp2;

    gate4081.setLink(12, falseComp1, 1);
    gate4081.setLink(13, falseComp2, 1);
    cr_assert_eq(gate4081.compute(11), nts::Tristate::False);
}

Test(Gate4081, CheckUndefinedTrue11, .init = redirect_all_stdout)
{
    nts::And4 gate4081;
    nts::InputComponent inputComp1;
    nts::TrueComponent trueComp1;

    gate4081.setLink(12, inputComp1, 1);
    gate4081.setLink(13, trueComp1, 1);
    cr_assert_eq(gate4081.compute(11), nts::Tristate::Undefined);
}

Test(Gate4081, CheckUndefinedFalse11, .init = redirect_all_stdout)
{
    nts::And4 gate4081;
    nts::InputComponent inputComp1;
    nts::FalseComponent falseComp1;

    gate4081.setLink(12, inputComp1, 1);
    gate4081.setLink(13, falseComp1, 1);
    cr_assert_eq(gate4081.compute(11), nts::Tristate::False);
}

Test(Gate4081, CheckUndefinedUndefined11, .init = redirect_all_stdout)
{
    nts::And4 gate4081;
    nts::InputComponent inputComp1;
    nts::InputComponent inputComp2;

    gate4081.setLink(12, inputComp1, 1);
    gate4081.setLink(13, inputComp2, 1);
    cr_assert_eq(gate4081.compute(11), nts::Tristate::Undefined);
}
