#include <iostream>

using namespace std;

/*
p.535
문제 13-01
문제 1
*/

//class Point {
//private:
//	int xpos, ypos;
//public:
//	Point(int x = 0, int y = 0) : xpos(x), ypos(y) { }
//	void ShowPosition() const {
//		cout << "[" << xpos << ", " << ypos << "]" << endl;
//	}
//};
//
//
//
//template <class T>
//void swapData(T& pos1, T& pos2) {
//	T temp = pos1;
//	pos1 = pos2;
//	pos2 = temp;
//}
//
//
//int main1() {
//	Point pos1(5, 7);
//	Point pos2(23, 45);
//
//	pos1.ShowPosition();
//	pos2.ShowPosition();
//
//	swapData(pos1, pos2);
//
//	pos1.ShowPosition();
//	pos2.ShowPosition();
//
//	return 0;
//}

/*
문제 2
*/
template <class T>
T sumArray(T arr[], int len) {
	T sum = 0;
	for (int i = 0; i < len; i++)
		sum += arr[i];
	return sum;
}

int main2() {

	int arr1[] = { 1, 2, 3, 4, 5 };
	double arr2[] = { 1.12, 2.4, 3.0, 4.5, 5.1 };
	float arr3[] = { 121.2f, 2.154f, 3.0015f, 4.15f, 5.7156f };


	cout << sumArray(arr1, sizeof(arr1)/sizeof(int)) <<endl;
	cout << sumArray(arr2, sizeof(arr1) / sizeof(double)) << endl;
	cout << sumArray(arr3, sizeof(arr1) / sizeof(float)) << endl;

	return 0;
}

/*
배열 탬플릿 클래스
*/

template <class T>
class BoundCheckArray {
private:
	T* arr;
	int arrlen;
	// 복사 생성자
	BoundCheckArray(const BoundCheckArray& arr){ }
	// 대입 연산자
	BoundCheckArray& operator=(const BoundCheckArray& arr) { }
public:
	BoundCheckArray(int len);
	T& operator[] (int idx);
	T operator[](int idx) const;
	int GetArrLen() const;
	~BoundCheckArray();
};

template <typename T>
BoundCheckArray<T>::BoundCheckArray(int len) : arrlen(len) {
	arr = new T[len];
}
template <typename T>
T& BoundCheckArray<T>::operator[] (int idx) {
	if (idx <0 || idx>arrlen) {
		cout << "유효하지 않은 인덱스 입니다." << endl;
		exit(1);
	}
	return arr[idx];
}

template <typename T>
T BoundCheckArray<T>::operator[] (int idx) const {
	if (idx <0 || idx>arrlen) {
		cout << "유효하지 않은 인덱스 입니다." << endl;
		exit(1);
	}
	return arr[idx];
}

template <typename T>
int BoundCheckArray<T>::GetArrLen() const {
	return arrlen;
}
template <typename T>
BoundCheckArray<T>::~BoundCheckArray() {
	delete[]arr;
}

/*
p.552
문제 13-02
문제 1
*/
class Point {
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) :xpos(x), ypos(y) {}
	void SetPos(int x, int y) {
		xpos = x;
		ypos = y;
	}
	void ShowPosition() const {
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
};

template < class T>
class SmartPtr {
private:
	T* posptr;
public:
	SmartPtr(Point* ptr): posptr(ptr){ }
	SmartPtr(Point ptr): posptr(ptr){ }
	T& operator*() const { return *posptr; }
	T* operator->() const { return posptr;  }
	~SmartPtr() { delete posptr;  }
};




int main() {
	SmartPtr<Point> sptr1(new Point(1, 2));
	SmartPtr<Point> sptr2(new Point(1, 2));
	sptr1->ShowPosition();
	sptr2->ShowPosition();

	sptr1->SetPos(10, 20);
	sptr2->SetPos(30, 40);
	sptr1->ShowPosition();
	sptr2->ShowPosition();

	return 0;
}