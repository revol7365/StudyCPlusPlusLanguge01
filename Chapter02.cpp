#include <iostream>

/*
p.80
���� 02-1
���� 1
*/
void addOne(int &ref) {
	ref++;
}

void changeSign(int &ref) {
	ref *= -1;
}

int main1() {

	int num1 = 10;

	addOne(num1);
	std::cout << "1���ϱ� " << num1 << std::endl;
	
	changeSign(num1);
	std::cout << "��ȣ���� " << num1 << std::endl;

	return 0;
}


/*
���� 2
�Ʒ� �Լ��� SwapByRef2(23, 45);
�������� �θ��� ���ϴ� ������ �����ڴ� ������ ���� �� �ֱ� �����̴�.
*/

void SwapByRef2(int &ref1, int &ref2) {
	int temp = ref1;
	ref1 = ref2;
	ref2 = temp;
}

/*
���� 3
*/

void SwapPointer(int* (&ref1), int* (&ref2)) {

	int* temp = ref1;
	ref1 = ref2;
	ref2 = temp;

}


int main2() {

	int num1 = 5;
	int* ptr1 = &num1;

	int num2 = 10;
	int* ptr2 = &num2;

	std::cout << "num1: " << *ptr1 << std::endl;
	std::cout << "num2: " << *ptr2 << std::endl;

	SwapPointer(ptr1, ptr2);


	std::cout << "num1: " << *ptr1 << std::endl;
	std::cout << "num2: " << *ptr2 << std::endl;


	return 0;
}


/*
p.90
���� 02-2
*/

int main3() {
	
	const int num = 12;
	const int* ptr = &num;
	const int* (&ref) = ptr;

	std::cout << "num: "<< num << std::endl;
	std::cout << "ptr: "<< *ptr << std::endl;
	std::cout << "ref: "<< *ref << std::endl;

	return 0;
}

/*
p.95
���� 02-3
*/

typedef struct __Point{
	int xPos;
	int yPos;
}Point;

Point& PntAdder(const Point& p1, const Point& p2) {
	Point* result = new Point; // �⺻ ������ ���� �޸� �Ҵ�
	result->xPos = p1.xPos + p2.xPos;
	result->yPos = p1.yPos + p2.yPos;
	return *result;
}


int main4() {
	
	Point* p1 = new Point;
	p1->xPos = 10;
	p1->yPos = 10;

	Point* p2 = new Point;
	p2->xPos = 5;
	p2->yPos = 6;

	Point &pref = PntAdder(*p1, *p2);

	std::cout << "xpos" << pref.xPos << std::endl;
	std::cout << "ypos" << pref.yPos << std::endl;

	delete p1;
	delete p2;
	delete &pref;

	return 0;
}


/*
p.99
���� 02-4
*/

#include <cstring>

int main5() {
	
	char str[20] = "Hello world";

	std::cout << strlen(str) << std::endl;
	strcat_s(str, " won");
	std::cout << str << std::endl;
	strcpy_s(str, "world");
	std::cout << str << std::endl;
	std::cout << strcmp(str, "wo") << std::endl;

	return 0;
}

/*
���� 2
*/

#include <ctime>
#include <cstdlib>

int main() {

	int numArr[5];
	std::srand(static_cast<unsigned int>(std::time(0)));
	for (int i = 0; i < 5; i++) {

		numArr[i] = rand();
	}
	for (int i = 0; i < 5; i++) {
		std::cout << i << "��°" << numArr[i] << std::endl;
	}


	return 0;
}