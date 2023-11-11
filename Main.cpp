#include <iostream>
#include "Calculator.h"
#include <format>
using namespace std;

int main()
{
    cout << "Calculator console app" << "\n\n";
    cout << "Please enter the operation to perform. Format: a + b | a - b | a * b | a / b" << "\n";
    cout << "Put spaces between the inputs." << "\n";

    Calculator calculator;
    double operand1 = 0.0;
    double operand2 = 0.0;
    double result = 0.0;
    char operation = '+';

    while (true)
    {
        cin >> operand1 >> operation >> operand2;
        result = calculator.Calculate(operand1, operation, operand2);
        cout << format("Result: {} {} {} = {}\n", operand1, operation, operand2, result);
    }

    return 0;
}
