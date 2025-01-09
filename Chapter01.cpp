#include <iostream>

/*
p.22
문제 01 - 1
문제 1
*/

int main1() {

	int result = 0;
	for(int i = 0; i < 5; i++) {
		int num = 0;
		std::cout << "정수를 입력해주세요" << std::endl;
		std::cin >> num;
		result += num;
		std::cout << i + 1 << "번째 정수 입력:" << num << std::endl;
	}

	std::cout <<"합계" << result << std::endl;

	return 0;

}

/*
문제 2
*/

int main2() {

	char name[100];
	char phoneNumber[100];

	std::cout << "이름을 입력해주세요" << std::endl;
	std::cin >> name;

	std::cout << "전화번호를 입력해주세요." << std::endl;
	std::cin >> phoneNumber;

	std::cout << "이름: " << name << std::endl;
	std::cout << "전화번호: " << phoneNumber<< std::endl;

	return 0;
}


/*
문제 3
*/

int main3() {

	int dan;

	std::cout << "출력할 구구단 단을 입력해주세요." << std::endl;
	std::cin >> dan;

	for (int i = 1; i <= 9; i++) {
		std::cout << dan << "*" << i << "=" << dan * i << std::endl;
	}
	return 0;
}

/*
문제 4
*/

int main4() {

	while (true) {

		int salesAmount = 0;

		std::cout << "이번달 판매금액을 입력해주세요" << std::endl;
		std::cin >> salesAmount;

		if (salesAmount == -1)
			break;

		std::cout << "이번 달 급여: " << 50 + salesAmount * 0.12 << "만원" << std::endl;

	}


	return 0;
}


/*
p.26
문제 01 - 2
문제 1
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
문제 01 - 3
문제 1
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
문제 2

첫번째 함수에 디폴트 값이 있어서 두번째 함수랑 같은 형태로 쓰일 수 있어서 안된다
SimpleFunc()이 첫번째함수인지 두번째 함수인지 구분이 안된다

int SimpleFunc(int a = 10){
	return a+1;
}

int SimpleFunc(){
	return 10;
}

*/


/*
p.43
문제 01 - 4
문제 1
폴더 -> Chapter01-04
*/

