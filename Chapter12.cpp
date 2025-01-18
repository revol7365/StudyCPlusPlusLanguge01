#include <iostream>

using namespace std;

class String {
private:
	int len;
	char* string;
public:
	// 일반 생성자
	String() {
		len = 0;
		string = NULL;
	}
	// 문자열을 받는 생성자
	String(const char* s) {
		len = strlen(s) + 1;
		this->string = new char[len];
		strcpy_s(this->string, len, s);
	}
	// 복사 생성자
	String(const String& ref) {
		len = ref.len;
		string = new char[len];
		strcpy_s(this->string, len, ref.string);
	}
	// 대입연산자 오버로딩
	String& operator=(const String& s) {
		if(string != NULL)
			delete[]string;

		len = s.len;
		this->string = new char[len];
		strcpy(this->string, s.string);
		return *this;
	}

	// == 연산자 오버로딩
	bool operator==(const String& s) {
		return strcmp(s.string, this->string) ? false : true;
	}
	// += 연산자 오버로딩 -- 재시도
	void operator+=(const String& s) {
		// 메모리 공간 추가 확보

		// 초기화

		//대입 

	}


	// + 연산자 오버로딩 -- 재시도
	String& operator+(const String& s) {
		// 메모리 공간 확보
		
		// 초기화
	}

	// 소멸자 오버로딩
	~String() {
		delete[]string;
	}
};

//  -- 재시도
ostream& operator<<(ostream& os, const String s) {
	os << s.string;
	return os;
}
//  -- 재시도
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
		cout << "동일 문자열!" << endl;
	else
		cout << "동일하지 않은 문자열!" << endl;

	String str4;
	cout << "문자열 입력: ";
	cin >> str4;
	cout << "입력한 문자열: " << str4 << endl;
	return 0;
}