#include<iostream>

using namespace std;
class Polar
{
	float angle, radius;
public:
	static int count;
	Polar()
	{
		angle = 0;
		radius = 0;
		count++;
	}
	Polar(float p,float w)
	{
		angle = p;
		radius = w;
		count++;
	}
	Polar(Polar &p)
	{
		angle = p.angle;
		radius = p.radius;
		count++;
	}
	void display()
	{
		cout << count;
	}

};
int Polar::count;
int main()
{
	Polar p1, p2(30,4),p3(p2);
	p3.display();

}
