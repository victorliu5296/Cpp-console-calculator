#include "Calculator.h"
#include <map>
#include <functional>
#include <stdexcept>

double Calculator::Calculate(double operand1, char operation, double operand2)
{
    static const std::map<char, std::function<double(double, double)>> operationMap {
        {'+', std::plus<double>()},
        {'-', std::minus<double>()},
        {'*', std::multiplies<double>()},
        {'/', std::divides<double>()}
    };

    auto operationIterator = operationMap.find(operation);
    if (operationIterator != operationMap.end())
    {
        if (operation == '/' && operand2 == 0)
        {
            throw std::invalid_argument("Error: Division by zero");
        }
        return operationIterator->second(operand1, operand2);
    }
    else
    {
        throw std::invalid_argument("Error: Operation not supported");
    }
}
