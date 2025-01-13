#include <iostream>

/*
p.114
문제 03-01
문제 1
*/

struct Point {
	int xPos;
	int yPos;

	void MovePos(int x, int y) {
		xPos += x;
		yPos += y;
	}

	void AddPoint(const Point &pos) {
		xPos += pos.xPos;
		yPos += pos.yPos;
	}

	void ShowPosition() {
		std::cout << "[" << xPos << " ," << yPos << "]" << std::endl;
	}
};

int main1() {

	Point pos1 = { 12, 4 };
	Point pos2 = { 20, 30 };

	pos1.MovePos(-7, 10);
	pos1.ShowPosition();

	pos2.AddPoint(pos1);
	pos2.ShowPosition();

	return 0;
}
