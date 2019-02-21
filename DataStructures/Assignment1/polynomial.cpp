#include <iostream>
using namespace std;
struct node
{
	int coefft;
	int power;
	struct node *next;
};
class poly
{
	struct node *start;
public:
	void insert_first(int,int);
	void insert_last(int,int);
	poly();
	void create_poly(int coeff, int power);
	void add(poly &p1,poly &p2);
	void display();
	~poly();
};
poly::poly()
{
	start = NULL;
}
void poly::insert_last(int coeff,int po)
{
	struct node *temp, *curr;
	temp = new node;
	temp->coefft = coeff;
	temp->power = po;
	temp->next = NULL;
	if (start == NULL)
		start = temp;
	else
	{
		curr = start;
		while (curr->next != NULL)
			curr = curr->next;
		curr->next = temp;
	}

}
void poly::create_poly(int coeff,int power)
{
	struct node *temp;
	temp = new node;
	temp->coefft = coeff;
	temp->power = power;
	temp->next = start;
	start = temp;
}
void poly::add(poly &l1, poly &l2)
{
	poly l3;
	struct node *c1, *c2,*temp;
	c1 = l1.start;
	c2 = l2.start;
	while (c1 != NULL && c2 != NULL)
	{
		if (c1->power == c2->power)
		{
			l3.create_poly(c1->coefft + c2->coefft, c1->power);
		}
		if (c1->power > c2->power)
		{
			l3.insert_last(c1->coefft, c1->power);
		}
		else
			l3.insert_last(c2->coefft, c2->power);
	}
}
void poly::display()
{
	if (start != NULL)
	{
		struct node *curr;
		curr = start;
		while (curr != NULL)
		{
			cout << curr->coefft;
			cout << curr->power;
			curr = curr->next;
		}
	}
}
poly::~poly()
{
	struct node *temp;
	while (start != NULL)
	{
		temp = start;
		start = temp->next;
		delete temp;
	}
}
int main()
{
	poly l1, l2,l3;
	int coef, power,ch;
	cout << "enter an operation to perform\n 1.enter the 1st polynomial\n 2.enter the second polynomial\n 3.add the two polynomials\n 4.display all the polynomials\n";
	cin >> ch;
	while (ch < 10)
	{
		switch (ch)
		{
		case 1:
			cout << "enter the coefficient\n";
			cin >> coef;
			cout << "enter the power\n";
			cin >> power;
			l1.create_poly(coef, power);
			break;
		case 2:
			cout << "enter the coefficient\n";
			cin >> coef;
			cout << "enter the power\n";
			cin >> power;
			l2.create_poly(coef, power);
			break;
		case 3:
			l3.add(l1, l2);
			break;
		case 4:
			l1.display();
			l2.display();
			l3.display();
			break;
		}
		cout << "enter an operation to perform\n";
		cin >> ch;
	}
	return 0;
}