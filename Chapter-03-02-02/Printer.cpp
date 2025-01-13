#include "printer.h"
#include <cstring>
#include <iostream>

using namespace std;

void Printer::SetString(const char* s){
	strcpy_s(str, s);
};


void Printer::ShowString() {
	cout << str << endl;
};