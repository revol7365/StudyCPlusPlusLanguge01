#include <iostream>

using namespace std;

class String {
private:
	int len;
	char* string;
public:
	// �Ϲ� ������
	String() {
		len = 0;
		string = NULL;
	}
	// ���ڿ��� �޴� ������
	String(const char* s) {
		len = strlen(s) + 1;
		this->string = new char[len];
		strcpy_s(this->string, len, s);
	}
	// ���� ������
	String(const String& ref) {
		len = ref.len;
		string = new char[len];
		strcpy_s(this->string, len, ref.string);
	}
	// ���Կ����� �����ε�
	String& operator=(const String& s) {
		if(string != NULL)
			delete[]string;

		len = s.len;
		this->string = new char[len];
		strcpy(this->string, s.string);
		return *this;
	}

	// == ������ �����ε�
	bool operator==(const String& s) {
		return strcmp(s.string, this->string) ? false : true;
	}
	// += ������ �����ε� -- ��õ�
	void operator+=(const String& s) {
		// �޸� ���� �߰� Ȯ��

		// �ʱ�ȭ

		//���� 

	}


	// + ������ �����ε� -- ��õ�
	String& operator+(const String& s) {
		// �޸� ���� Ȯ��
		
		// �ʱ�ȭ
	}

	// �Ҹ��� �����ε�
	~String() {
		delete[]string;
	}
};

//  -- ��õ�
ostream& operator<<(ostream& os, const String s) {
	os << s.string;
	return os;
}
//  -- ��õ�
istream& operator>>(istream& is, String& string) {
	string >> io;
}

int main() {

	String str1 = "I like ";
	String str2 = "String class";
	String str3 = str1+str2;

	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;

	str1 += str2;
	if (str1 == str3)
		cout << "���� ���ڿ�!" << endl;
	else
		cout << "�������� ���� ���ڿ�!" << endl;

	String str4;
	cout << "���ڿ� �Է�: ";
	cin >> str4;
	cout << "�Է��� ���ڿ�: " << str4 << endl;
	return 0;
}