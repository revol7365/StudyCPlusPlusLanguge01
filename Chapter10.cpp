#include <iostream>

using namespace std;

/*
p.409
���� 10 -1
���� 1
*/

//class Point {
//private:
//	int xpos, ypos;
//public:
//	Point(int x = 0, int y = 0) : xpos(x), ypos(y) {
//	}
//	void ShowPosition() const {
//		cout << "[" << xpos << ", " << ypos << "]" << endl;
//	}
//	
//	
//	Point& operator+=(const Point& ref) {
//		this->xpos += ref.xpos;
//		this->ypos += ref.ypos;
//		return *this;
//	}
//	Point& operator-=(const Point& ref) {
//		this->xpos -= ref.xpos;
//		this->ypos -= ref.ypos;
//		return *this;
//	}
//
//	friend Point operator+(const Point &pos1, const Point &pos2);
//	friend Point operator-(const Point &pos1, const Point &pos2);
//	friend bool operator==(const Point &pos1, const Point &pos2);
//	friend bool operator!=(const Point &pos1, const Point &pos2);
//};
//
//Point operator+(const Point &pos1, const Point &pos2) {
//	Point pos(pos1.xpos + pos2.xpos, pos1.ypos+ pos2.ypos);
//	return pos;
//}
//Point operator-(const Point &pos1, const Point &pos2) {
//	Point pos(pos1.xpos - pos2.xpos, pos1.ypos - pos2.ypos);
//	return pos;
//}
//bool operator==(const Point &pos1, const Point &pos2) {
//	return pos1.xpos == pos2.xpos && pos1.ypos == pos2.ypos;
//}
//bool operator!=(const Point& pos1, const Point& pos2) {
//	return !(pos1 == pos2);
//}
//
//int main1() {
//
//	Point pos1(3, 4);
//	Point pos2(10, 20);
//	Point pos3(3, 4);
//
//	if (pos1 == pos2)
//		cout << "pos1==pos2 ����" << endl;
//	else
//		cout << "pos1==pos2 �ٸ�" << endl;
//
//	if (pos1 == pos3)
//		cout << "pos1==pos3 ����" << endl;
//	else
//		cout << "pos1==pos3 �ٸ�" << endl;
//
//	if (pos1 != pos2)
//		cout << "pos1!=pos2 �ٸ�" << endl;
//	else
//		cout << "pos1!=pos2 ����" << endl;
//
//	if (pos1 != pos3)
//		cout << "pos1!=pos3 �ٸ�" << endl;
//	else
//		cout << "pos1!=pos3 ����" << endl;
//
//	return 0;
//}

/*
p.418
���� 10-2
���� 1,2
*/

//class Point {
//private:
//	int xpos, ypos;
//public:
//	Point(int x = 0, int y = 0) : xpos(x), ypos(y) {
//	}
//	void ShowPosition() const {
//		cout << "[" << xpos << ", " << ypos << "]" << endl;
//	}
//
//	Point& operator-() {
//		this->xpos = this->xpos*-1;
//		this->ypos = this->ypos*-1;
//		return *this;
//	}
//
//	friend Point& operator~(const Point &ref);
//};
//
//Point& operator~(const Point &ref) {
//	Point pos(ref.ypos, ref.xpos);
//	return pos;
//}
//
//int main2() {
//	
//	Point pos1(3, 4);
//	pos1.ShowPosition();
//
//	Point pos2 = -pos1;
//	pos2.ShowPosition();
//
//	Point pos3(10, 20);
//	pos3.ShowPosition();
//
//	Point pos4 = ~pos3;
//	pos4.ShowPosition();
//
//	return 0;
//}

/*
p.436
���� 10-3
*/
#include <istream>

class Point {
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y) {
	}
	void ShowPosition() const {
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}

	friend ostream& operator<<(ostream& os, const Point& pos);
	friend istream& operator>>(istream& is, Point& pos);

};

// �����Լ� ������ �����ε�
ostream& operator<<(ostream& os, const Point& pos) {
	pos.ShowPosition();
	return os;
}

istream& operator>>(istream& is, Point& pos) {
	
	is >> pos.xpos;
	is >> pos.ypos;
	return is;
}


int main() {

	Point pos1;
	cout << "x y ��ǥ ������ �Է�: ";
	cin >> pos1;
	cout << pos1;

	Point pos2;
	cout << "x y ��ǥ ������ �Է�: ";
	cin >> pos2;
	cout << pos2;

	return 0;
}