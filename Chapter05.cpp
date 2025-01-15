#include <iostream>
using namespace std;

/*
p.226
문제 05-01
문제 1
*/

namespace COMP_POS {
	enum { CLEAK, SENIOR, ASSIST, MANAGER };

	void showPositionInfo(int role) {
		switch (role) {
		case 0:
			cout << "사원" << endl;
			break;
		case 1:
			cout << "주임" << endl;
			break;
		case 2:
			cout << "대리" << endl;
			break;
		case 3:
			cout << "과장" << endl;
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
	NameCard(const char* name, const char* componyName, const char* phoneNumber, int role) :role(role) {
		// 동적 할당
		this->name = new char[strlen(name) + 1];
		this->componyName = new char[strlen(componyName) + 1];
		this->phoneNumber = new char[strlen(phoneNumber) + 1];

		strcpy_s(this->name, strlen(name) + 1, name);
		strcpy_s(this->componyName, strlen(componyName) + 1, componyName);
		strcpy_s(this->phoneNumber, strlen(phoneNumber) + 1, phoneNumber);
	}
	NameCard(const NameCard& copy1) :role(copy1.role) {
		this->name = new char[strlen(copy1.name) + 1];
		this->componyName = new char[strlen(copy1.componyName) + 1];
		this->phoneNumber = new char[strlen(copy1.phoneNumber) + 1];

		strcpy_s(this->name, strlen(copy1.name) + 1, copy1.name);
		strcpy_s(this->componyName, strlen(copy1.componyName) + 1, copy1.componyName);
		strcpy_s(this->phoneNumber, strlen(copy1.phoneNumber) + 1, copy1.phoneNumber);
	}

	void ShowNameCardInfo() {
		cout << "이름: " << name << endl;
		cout << "회사: " << componyName << endl;
		cout << "전화번호: " << phoneNumber << endl;
		cout << "직급: "; COMP_POS::showPositionInfo(role); cout << endl;
	}
	~NameCard() {
		cout << "NameCard delete" << endl;
		delete[]name;
		delete[]componyName;
		delete[]phoneNumber;
	}
};

int main() {
	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLEAK);
	NameCard copy1 = manClerk;
	NameCard manSenior("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	NameCard copy2 = manSenior;
	copy1.ShowNameCardInfo();
	copy2.ShowNameCardInfo();

	return 0;
}