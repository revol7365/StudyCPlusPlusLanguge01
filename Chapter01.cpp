#include <iostream>

/*
p.22
���� 01 - 1
���� 1
*/

int main1() {

	int result = 0;
	for(int i = 0; i < 5; i++) {
		int num = 0;
		std::cout << "������ �Է����ּ���" << std::endl;
		std::cin >> num;
		result += num;
		std::cout << i + 1 << "��° ���� �Է�:" << num << std::endl;
	}

	std::cout <<"�հ�" << result << std::endl;

	return 0;

}

/*
���� 2
*/

int main2() {

	char name[100];
	char phoneNumber[100];

	std::cout << "�̸��� �Է����ּ���" << std::endl;
	std::cin >> name;

	std::cout << "��ȭ��ȣ�� �Է����ּ���." << std::endl;
	std::cin >> phoneNumber;

	std::cout << "�̸�: " << name << std::endl;
	std::cout << "��ȭ��ȣ: " << phoneNumber<< std::endl;

	return 0;
}


/*
���� 3
*/

int main3() {

	int dan;

	std::cout << "����� ������ ���� �Է����ּ���." << std::endl;
	std::cin >> dan;

	for (int i = 1; i <= 9; i++) {
		std::cout << dan << "*" << i << "=" << dan * i << std::endl;
	}
	return 0;
}

/*
���� 4
*/

int main4() {

	while (true) {

		int salesAmount = 0;

		std::cout << "�̹��� �Ǹűݾ��� �Է����ּ���" << std::endl;
		std::cin >> salesAmount;

		if (salesAmount == -1)
			break;

		std::cout << "�̹� �� �޿�: " << 50 + salesAmount * 0.12 << "����" << std::endl;

	}


	return 0;
}


/*
p.26
���� 01 - 2
���� 1
*/

void swap(int *num1, int* num2) {

	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

void swap(char* ch1, char* ch2) {
	char temp = *ch1;
	*ch1 = *ch2;
	*ch2 = temp;
}

void swap(double* dbl1, double* dbl2) {
	double temp = *dbl1;
	*dbl1 = *dbl2;
	*dbl2 = temp;
}


int main5() {
	int num1 = 20, num2 = 30;
	swap(&num1, &num2);
	std::cout << num1 << ' ' << num2 << std::endl;

	char ch1 = 'A', ch2 = 'Z';
	swap(&ch1, &ch2);
	std::cout << ch1 << ' ' << ch2 << std::endl;

	double dbl1 = 1.111, dbl2 = 5.555;
	swap(&dbl1, &dbl2);
	std::cout << dbl1 << ' ' << dbl2 << std::endl;

	return 0;
}


/*
p.32
���� 01 - 3
���� 1
*/
//int BoxVolume(int length, int widht = 1, int height = 1);
int BoxVolume(int length, int widht, int height);
int BoxVolume(int length, int widht);
int BoxVolume(int length);
//int BoxVolume();

int main6() {

	std::cout << "[3, 3, 3] : " << BoxVolume(3, 3, 3) << std::endl;
	std::cout << "[5, 5, D] : " << BoxVolume(5, 5) << std::endl;
	std::cout << "[7, D, D] : " << BoxVolume(7) << std::endl;
	//std::cout << "[D, D, D] : " << BoxVolume() << std::endl;
	return 0;
}

int BoxVolume(int length, int width, int height) {
	return length * width * height;
}

int BoxVolume(int length, int width) {
	return length * width * 1;
}

int BoxVolume(int length) {
	return length * 1 * 1;
}

//int BoxVolume() {
//	return length * width * height;
//}

/*
���� 2

ù��° �Լ��� ����Ʈ ���� �־ �ι�° �Լ��� ���� ���·� ���� �� �־ �ȵȴ�
SimpleFunc()�� ù��°�Լ����� �ι�° �Լ����� ������ �ȵȴ�

int SimpleFunc(int a = 10){
	return a+1;
}

int SimpleFunc(){
	return 10;
}

*/


/*
p.43
���� 01 - 4
���� 1
���� -> Chapter01-04
*/

