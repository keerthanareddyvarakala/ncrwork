#include<iostream>
#include<cmath>
using namespace std;
class point {

	int x;
	int y;
public:
	point(int w, int z)
	{
		x = w;
		y = z;
	}
	friend void add(point p1, point p2);
	friend void distance(point p1, point p2);
};
void add(point p1, point p2)
{
	int x, y;
	x = p1.x + p2.x;
	y = p1.y + p2.y;
	cout << "(" << x << "," << y << ")" << endl;

}
void distance(point p1,point p2)
{
	float d;
	d = sqrt(pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2));
	cout<< d<<endl;
}
int main()
{
	point p1(2, 3), p2(4, 5);
	add(p1, p2);
	distance(p1, p2);
	return 0;
}
