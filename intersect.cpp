#include <iostream>
#include <cstdio>

using namespace std;

int max(int a, int b) {
	return (a > b) ? a : b;
}

int min(int a, int b) {
	return (a < b) ? a : b;
}

class CRect
{
private:
	int lx;
	int ly;
	int rx;
	int ry;

public:
	CRect(int Lx, int Ly, int Rx, int Ry)
		: lx(Lx), ly(Ly), rx(Rx), ry(Ry)
	{}
	void show();
	static CRect intersect(CRect &a, CRect &b);
};

void CRect::show()
{
	printf("%d %d %d %d \n", lx, ly, rx, ry);
}

CRect CRect::intersect(CRect &a, CRect &b)
{
	int leftX, leftY, rightX, rightY;

	leftX = max(a.lx, b.lx);
	leftY = max(a.ly, b.ly);
	rightX = min(a.rx, b.rx);
	rightY = min(a.ry, b.ry);

	return CRect(leftX, leftY, rightX, rightY);
}

int main()
{
	CRect rect1(2, 2, 5, 3);
	CRect rect2(1, 1, 4, 4);

	CRect result = CRect::intersect(rect1, rect2);
	result.show();

	return 0;
}