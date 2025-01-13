#include <iostream>

using namespace std;

class Calculator {
private:
	int addCount;
	int minCount;
	int divCount;
	int mulCount;

public:
	void init() {
		addCount = 0;
		minCount = 0;
		divCount = 0;
		mulCount = 0;
	}
	double Add(double num1, double num2);
	double Min(double num1, double num2);
	double Div(double num1, double num2);
	double Mul(double num1, double num2);
	void ShowOpCount() {
		cout << "����: " << addCount << endl;
		cout << "����: " << minCount << endl;
		cout << "������: " << divCount << endl;
		cout << "����: " << mulCount << endl;
	};

};