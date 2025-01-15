#include <iostream>
using namespace std;

/*
p.294
문제 07-01
문제 1
*/
class Car {
private:
	int gasolineGauge;
public:
	Car(int gauge):gasolineGauge(gauge) {

	}
	int GetGasGauge() {
		return gasolineGauge;
	}
};

class HybridCar : public Car {
private:
	int electricGauge;
public:
	HybridCar(int gasGauge, int electricGauge) :Car(gasGauge), electricGauge(electricGauge) {

	}
	int GetElecGauge() {
		return electricGauge;
	}
};

class HybridWaterCar : public HybridCar {
private:
	int waterGauge;
public:
	HybridWaterCar(int gasGauge, int electricGauge, int waterGauge) :HybridCar(gasGauge, electricGauge), waterGauge(waterGauge) {

	}
	void ShowCurrentGauge() {
		cout << "잔여 가솔린: " << GetGasGauge() << endl;
		cout << "잔여 전기량: " << GetElecGauge() << endl;
		cout << "잔여 워터량: " << waterGauge << endl;
	}
};

int main1() {

	//Car* car = new Car(100);
	//HybridCar* hybridCar = new HybridCar(50,50);

	HybridWaterCar* hybridWaterCar = new HybridWaterCar(30,30,40);
	hybridWaterCar->ShowCurrentGauge();
	
	return 0;
}

/*
문제 2
*/

class MyFriendInfo {
private:
	char* name;
	int age;
public:
	MyFriendInfo(const char* name, int age): age(age){
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
	}
	void ShowMyFriendInfo() const {
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
	}
	~MyFriendInfo() {
		delete []name;
	}
};

class MyFriendDetailInfo : public MyFriendInfo {
private:
	char* addr;
	char* phone;
public:
	MyFriendDetailInfo(const char* name, int age, const char* addr, const char* phone): MyFriendInfo(name, age) {

		this->addr = new char[strlen(addr) + 1];
		this->phone = new char[strlen(phone) + 1];
		strcpy_s(this->addr, strlen(addr) + 1, addr);
		strcpy_s(this->phone, strlen(phone) + 1, phone);
	}
	void ShowMyFriendDetailInfo() const {
		ShowMyFriendInfo();
		cout << "주소: " << addr << endl;
		cout << "전화: " << phone << endl << endl;
	}
	~MyFriendDetailInfo() {
		delete []addr;
		delete []phone;
	}
};

int main2() {

	MyFriendDetailInfo myFriend("won", 32, "경기도", "010-1111-2222");
	myFriend.ShowMyFriendDetailInfo();

	return 0;
}

/*
p.312
문제 07-02
문제 1
*/
class Rectangle {
private:
	int width;
	int height;
public:
	Rectangle(int width, int height) : width(width), height(height) {

	}
	void ShowAreaInfo() {
		cout << "면적: " << width * height << endl;
	}
};

class Square : public Rectangle {
public:
	Square(int w) : Rectangle(w, w) {
	}
};


int main3() {
	Rectangle rec(4, 3);
	rec.ShowAreaInfo();

	Square sqr(7);
	sqr.ShowAreaInfo();
	return 0;
}

/*
문제 2
*/

class Book {
private:
	char* title;
	char* isbn;
	int price;
public:
	Book(const char* title, const char* isbn, const int price): price(price) {
		this->title = new char[strlen(title) + 1];
		this->isbn = new char[strlen(isbn) + 1];
		strcpy_s(this->title, strlen(title) + 1, title);
		strcpy_s(this->isbn, strlen(isbn) + 1, isbn);
	}
	void ShowBookInfo() const {
		cout << "제목: " << title << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "가격: " << price << endl;
	}
	~Book() {
		delete []title;
		delete []isbn;
	}
};


class EBook : public Book {
private:
	char* DRMKey;
public:
	EBook(const char* title, const char* isbn, const int price, const char* drmKey):  Book(title, isbn, price) {
		this->DRMKey = new char[strlen(drmKey) + 1];
		strcpy_s(this->DRMKey, strlen(drmKey) + 1, drmKey);
	}
	void ShowEBookInfo() const {
		ShowBookInfo();
		cout << "인증키: " << DRMKey << endl;
	}
	~EBook() {
		delete[]DRMKey;
	}
};


int main() {
	Book book("좋은 C++", "555-`1234-890-0", 20000);
	book.ShowBookInfo();
	cout << endl;

	EBook ebook("좋은 C++ eBook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
	ebook.ShowEBookInfo();

	return 0;
}