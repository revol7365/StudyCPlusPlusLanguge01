#include <iostream>
#include "printer.h"

using namespace std;

int main() {

	Printer pnt;
	pnt.SetString("Hello World");
	pnt.ShowString();

	pnt.SetString("I love C++");
	pnt.ShowString();

	return 0;
}