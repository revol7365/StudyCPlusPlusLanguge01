#include <iostream>
#include "Calculator.h"

using namespace std;

double Calculator::Add(double num1, double num2) {
	Calculator::addCount++;
	return num1 + num2;
};


double  Calculator::Min(double num1, double num2) {
	Calculator::minCount++;
	return num1 - num2;
};

double  Calculator::Div(double num1, double num2) {
	Calculator::divCount++;
	return num1 / num2;
};

double  Calculator::Mul(double num1, double num2) {
	Calculator::mulCount++;
	return num1 * num2;
};
