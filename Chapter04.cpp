#include <iostream>

/*
p.160
���� 04-1
���� 1
*/

using namespace std;

class FruitSeller {
private:
	int APPLE_PRICE;
	int numOfApples;
	int myMoney;
public:
	void InitMembers(int price, int num, int money) {
		APPLE_PRICE = price;
		numOfApples = num;
		myMoney = money;
	}
	int SaleApples(int money) {
		if (money < 0)
			return 0 ;

		int num = money / APPLE_PRICE;
		numOfApples -= num;
		myMoney += money;
		return num;
	}
	void ShowSalesResult() const {
		cout << "���� ���: " << numOfApples << endl;
		cout << "�Ǹ� ����: " << myMoney << endl << endl;
	}
};

class FruitBuyer {
	int myMoney;
	int numOfApples;
public:
	void InitMembers(int money) {
		myMoney = money;
		numOfApples = 0;
	}
	void BuyApples(FruitSeller& seller, int money) {
		if (money < 0)
			return;

		numOfApples += seller.SaleApples(money);
		myMoney -= money;
	}
	void ShowBuyResult() const {
		cout << "���� �ܾ�: " << myMoney << endl;
		cout << "��� ����: " << numOfApples << endl << endl;
	}
};

int main1() {

	FruitSeller seller;
	seller.InitMembers(1000, 20, 0);
	FruitBuyer buyer;
	buyer.InitMembers(5000);
	buyer.BuyApples(seller, 2000);

	cout << "���� �Ǹ����� ��Ȳ" << endl;
	seller.ShowSalesResult();
	cout << "���� �������� ��Ȳ" << endl;
	buyer.ShowBuyResult();


	return 0;
}

/*
p.166
���� 04-02
���� 1
*/


//class Point {
//private:
//	int xpos, ypos;
//public:
//	void Init(int x, int y) {
//		xpos = x;
//		ypos = y;
//	}
//	void ShowPointInfo() const {
//		cout << "[" << xpos << ", " << ypos << "]" << endl;
//	}
//};
//
//class Circle {
//private:
//	int rad;
//	Point cpoint;
//public:
//	void Init(int x, int y, int r) {
//		rad = r;
//		cpoint.Init(x, y);
//	}
//	void ShowCircleInfo() const {
//		cout << "radius: "<< rad << endl;
//		cpoint.ShowPointInfo();
//	}
//};
//
//class Ring {
//private:
//	Circle innerCircle, outterCircle;
//public:
//	void Init(int x1, int y1, int r1, int x2, int y2, int r2) {
//		innerCircle.Init(x1, y1, r1);
//		outterCircle.Init(x2, y2, r2);
//	}
//	void ShowRingInfo() const {
//		cout << "Inner Circle Info..." << endl;
//		innerCircle.ShowCircleInfo();
//
//		cout << "Outter Circle Info..." << endl;
//		outterCircle.ShowCircleInfo();
//	}
//
//};
//
//
//int main2() {
//	Ring ring;
//	ring.Init(1, 1, 4, 2, 2, 9);
//	ring.ShowRingInfo();
//	return 0;
//}

/*
p.190
���� 04-03
���� 1
*/


class Point {
private:
	int xpos, ypos;
public:
	Point(int x, int y):xpos(x), ypos(y) {
	}
	void ShowPointInfo() const {
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
};

class Circle {
private:
	int rad;
	Point c;
public:
	Circle(int x, int y, int r): c(x, y), rad(r) {
	}
	void ShowCircleInfo() const {
		cout << "radius: " << rad << endl;
		c.ShowPointInfo();
	}
};

class Ring {
private:
	Circle innerCircle, outterCircle;
public:
	Ring(int x1, int y1, int r1, int x2, int y2, int r2): innerCircle(x1, y1, r1), outterCircle(x2, y2, r2) {

	}
	void ShowRingInfo() const {
		cout << "Inner Circle Info..." << endl;
		innerCircle.ShowCircleInfo();

		cout << "Outter Circle Info..." << endl;
		outterCircle.ShowCircleInfo();
	}

};


int main3() {
	Ring ring(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();
	return 0;
}

/*
p.190
���� 04-03
���� 2
*/
namespace COMP_POS {
	enum { CLEAK, SENIOR, ASSIST, MANAGER };

	void showPositionInfo(int role) {
		switch (role) {
		case 0:
			cout <<"���" << endl;
			break;
		case 1:
			cout <<"����" << endl;
			break;
		case 2:
			cout <<  "�븮" << endl;
			break;
		case 3:
			cout <<"����" << endl;
			break;
		}
	}
}


class NameCard {
private:
	char* name;
	char* componyName;
	char* phoneNumber;
	int role;
public:
	NameCard(const char* _name, const char* _componyName, const char* _phoneNumber, int role) :role(role) {
		// ���� �Ҵ�
		name = new char[strlen(_name) + 1];
		componyName = new char[strlen(_componyName) + 1];
		phoneNumber = new char[strlen(_phoneNumber) + 1];

		strcpy_s(name, strlen(name) + 1, _name);
		strcpy_s(componyName, strlen(componyName) + 1, _componyName);
		strcpy_s(phoneNumber, strlen(phoneNumber) + 1, _phoneNumber);
	}
	void ShowNameCardInfo() {
		cout << "�̸�: " << name << endl;
		cout << "ȸ��: " << componyName << endl;
		cout << "��ȭ��ȣ: " << phoneNumber << endl;
		cout << "����: "; COMP_POS::showPositionInfo(role); cout<< endl;
	}
	~NameCard() {
		delete[]name;
		delete[]componyName;
		delete[]phoneNumber;
	}
};

int main() {
	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLEAK);
	NameCard manSenior("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST);
	manClerk.ShowNameCardInfo();
	manSenior.ShowNameCardInfo();
	manAssist.ShowNameCardInfo();

	return 0;
}