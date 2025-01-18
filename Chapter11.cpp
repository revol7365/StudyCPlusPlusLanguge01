#include <iostream>
#include <Cstring>

using namespace std;

//class Person {
//private:
//	char* name;
//	int age;
//public:
//	Person(char* myname, int myage) {
//		int len = strlen(myname) + 1;
//		name = new char[len];
//		strcpy(name, myname);
//		age = myage;
//	}
//	Person& operator=(Person& person) {
//		delete[]person.name;
//		int len = strlen(person.name) + 1;
//		name = new char[len];
//		strcpy(name, person.name);
//		age = person.age;
//		return *this;
//	}
//
//	~Person() {
//		delete[]name;
//		cout << "called destructor!" << endl;
//	}
//
//};

/*
p.452
���� 11-01
����1
*/

//class Gun {
//private:
//	int bullet;
//public:
//	Gun(int bnum) : bullet(bnum) { }
//	void Shot() {
//		cout << "BBANG!" << endl;
//		bullet--;
//	}
//};
//class Police {
//private:
//	int handcuffs; // ������ ������
//	Gun* pistol; // �����ϰ� �ִ� ����
//public:
//	Police(int bnum, int bcuff) : handcuffs(bcuff) {
//		if (bnum > 0)
//			pistol = new Gun(bnum);
//		else
//			pistol = NULL;
//	}
//	// ���� ������
//	Police(const Police &copy) : handcuffs(copy.handcuffs) {
//		cout << "Police ���� ������ " << endl;
//		if (copy.pistol != NULL)
//			pistol = new Gun(*copy.pistol);
//		else
//			pistol = NULL;
//	}
//	void PutHandcuff() {
//		cout << "SNAP!" << endl;
//		handcuffs--;
//	}
//	void shot() {
//		if (pistol == NULL)
//			cout << "Hut BBANG!" << endl;
//		else
//			pistol->Shot();
//	}
//	// ���� ������
//	Police& operator=(Police& copy) {
//		cout << "Police ���� ������ " << endl;
//		if (copy.pistol != NULL)
//			pistol = new Gun(*copy.pistol);
//		else
//			pistol = NULL;
//
//		handcuffs = copy.handcuffs;
//		return *this;
//	}
//	~Police() {
//		cout << "Police �Ҹ��� " << endl;
//		if (pistol != NULL)
//			delete pistol;
//	}
//};
//
//int main1() {
//
//	Police police1(6, 1);
//	Police police2(0, 1);
//	police2 = police1;
//	Police police3(police2);
//
//	return 0;
//}



/*
���� 2
*/

//class Book
//{
//private:
//	char* title; //å�� ����
//	char* isbn; //����ǥ�ص�����ȣ
//	int price; //å�� ����
//public:
//	Book(const char* _title, const char* _isbn, int _price)
//		: price(_price)
//	{
//		size_t len = strlen(_title) + 1;
//		title = new char[len];
//		strcpy_s(title, len, _title);
//		size_t len1 = strlen(_isbn) + 1;
//		isbn = new char[len1];
//		strcpy_s(isbn, len1, _isbn);
//	}
//	// ���� ������
//	Book(const Book &ref):price(ref.price) {
//		cout << "Book ���� ������" << endl;
//
//		this->title = new char[strlen(ref.title) + 1];
//		this->isbn = new char[strlen(ref.isbn) + 1];
//
//		strcpy_s(this->title, strlen(ref.title) + 1, ref.title);
//		strcpy_s(this->isbn, strlen(ref.isbn) + 1, ref.isbn);
//	}
//
//	//���� ������
//	Book& operator=(const Book& ref) {
//		cout << "Book ���� ������" << endl;
//
//		delete[]title;
//		delete[]isbn;
//
//		this->title = new char[strlen(ref.title) + 1];
//		this->isbn = new char[strlen(ref.isbn) + 1];
//
//		strcpy_s(this->title, strlen(ref.title) + 1, ref.title);
//		strcpy_s(this->isbn, strlen(ref.isbn) + 1, ref.isbn);
//		
//		price = ref.price;
//
//		return *this;
//	}
//
//	void ShowBookInfo() const
//	{
//		cout << "Title : " << title << endl;
//		cout << "ISBN : " << isbn << endl;
//		cout << "Price : " << price << endl;
//	}
//	~Book()
//	{
//		cout << "Book �Ҹ���" << endl;
//		delete[]title;
//		delete[]isbn;
//	}
//};
//
//class Ebook :public Book
//{
//private:
//	char* DRMKey; //���Ȱ��� Ű
//public:
//	Ebook(const char* a, const char* b, int c, const char* _drmkey) :Book(a, b, c)
//	{
//		size_t len = strlen(_drmkey) + 1;
//		DRMKey = new char[len];
//		strcpy_s(DRMKey, len, _drmkey);
//	}
//	//���� ������
//	Ebook(const Ebook& ref) :Book(ref) {
//		cout << "EBook ���� ������" << endl;
//		delete[]DRMKey;
//		this->DRMKey = new char[strlen(ref.DRMKey) + 1];
//		strcpy_s(DRMKey, strlen(ref.DRMKey) + 1, ref.DRMKey);
//
//	}
//	// ���� ������
//	Ebook& operator=(const Ebook& ref) {
//		cout << "EBook ���� ������" << endl;
//		Book::operator=(ref);
//		delete[]DRMKey;
//
//		int drmLen = strlen(ref.DRMKey) + 1;
//		this->DRMKey = new char[drmLen];
//		strcpy_s(DRMKey, drmLen, ref.DRMKey);
//		return *this;
//	}
//
//	void ShowEBookInfo() const
//	{
//		ShowBookInfo();
//		cout << "DRMKey : " << DRMKey << endl;
//	}
//
//	~Ebook() {
//		cout << "EBook �Ҹ���" << endl;
//		delete[]DRMKey;
//	}
//};
//
//
//int main2(void)
//{
//	cout << "=== Book ��ü ���� �� ���� �׽�Ʈ ===" << endl;
//	Book book1("���� C", "555-12345-890-0", 20000);
//	Book book2("���� C++", "555-12345-890-0", 30000);
//	book1 = book2; // ���� ������ ȣ��
//	Book book3(book1); // ���� ������ ȣ��
//	Book book4 = book2; // ���� ������ ȣ��
//
//	cout << endl;
//	cout << "=== Ebook ��ü ���� �� ���� ��� ===" << endl;
//	Ebook ebook1("���� C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
//	//ebook1.ShowEBookInfo();
//
//	cout << endl;
//	cout << "=== Ebook ��ü ���� �� ���� �׽�Ʈ ===" << endl;
//	Ebook ebook2 = ebook1; // ���� ������ ȣ��
//	//ebook2.ShowEBookInfo();
//
//	Ebook ebook3("Temp", "123-456", 5000, "abcd1234");
//	ebook3 = ebook1; // ���� ������ ȣ��
//	//ebook3.ShowEBookInfo();
//	return 0;
//}

/*
p.468
���� 11-02
���� 1
*/
#include <ostream>

class Point {
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
	friend ostream& operator<<(ostream & os, const Point* pos);
	friend ostream& operator<<(ostream & os, const Point& pos);
};

ostream& operator<<(ostream & os, const Point& pos){
	os << "[" << pos.xpos << ", " << pos.ypos << "]" << endl;
	return os;
}
ostream& operator<<(ostream& os, const Point* pos) {
	os << "[" << pos->xpos << ", " << pos->ypos << "]" << endl;
	return os;
}
typedef Point* POINT_PTR;

class BoundCheckPointPtrArray {
private:
	POINT_PTR* arr;
	int arrlen;

	// ���� ������ 
	BoundCheckPointPtrArray(const BoundCheckPointPtrArray& arr) {}
	// ���� ������
	BoundCheckPointPtrArray& operator=(const const BoundCheckPointPtrArray& arr) { }
public:
	BoundCheckPointPtrArray(int len) :arrlen(len) {
		arr = new POINT_PTR[len];
	}
	POINT_PTR& operator[](int idx) {
		if (idx<0 || idx>arrlen) {
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return arr[idx];
	}
	POINT_PTR& operator[](int idx) const {
		if (idx<0 || idx>arrlen) {
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return arr[idx];
	}
	int GetArrLen() const { return arrlen; }
	~BoundCheckPointPtrArray() { delete[]arr; }
};

int main3() {
	BoundCheckPointPtrArray arr(3);
	arr[0] = new Point(3, 4);
	arr[1] = new Point(5, 6);
	arr[2] = new Point(7, 8);

	for (int i = 0; i < arr.GetArrLen(); i++)
		cout << *(arr[i]);

	for (int i = 0; i < arr.GetArrLen(); i++)
		cout << arr[i];

	delete arr[0];
	delete arr[1];
	delete arr[2];

	return 0;
}

/*
���� 2
*/

