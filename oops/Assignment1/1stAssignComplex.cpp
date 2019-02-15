#include<iostream>
using namespace std;
class complex
{
	float real;
	float img;
public:
	complex()
	{
		real = img = 0;
	}
	complex(float r)
	{
		real = img = r;
	}
	complex(float r, float i)
	{
		real = r;
		img = i;
	}

	void add(complex *c1, complex *c2)
	{
		real = c1->real + c2->real;
		img = c1->img + c2->img;
		cout << real << "+" << img << "i";

	}
	void mul(complex *c1, complex *c2)
	{
		real = (c1->real)*(c2->real) - (c1->img)*(c2->img);
		img = (c1->real)*(c2->img) + (c1->img)*(c2->real);
		cout << real << "+" << img << "i" << endl;
	}

};
void main()
{
	complex c1(3), c2(2, 3), c3, c4;
	c3.add(&c1, &c2);
	c4.mul(&c1, &c2);

}