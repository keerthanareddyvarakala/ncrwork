#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
};
class list
{
	struct node *start;
public:
	list();
	void push(int);
	int pop();
	void display();
	~list();
};
list::list()
{
	start = NULL;
}
void list::push(int ele)
{
	struct node *temp;
	temp = new node;
	temp->data = ele;
	temp->next = start;
	start = temp;
}
int list::pop()
{
	int x = -999;
	if (start != NULL)
	{
		struct node *temp;
		temp = start;
		start = start->next;
		x = temp->data;
		delete temp;
	}
	else
		cout << "list is empty" << endl;
	return x;
}
void list::display()
{
	struct node *curr;
	curr = start;
	while (curr != NULL)
	{
		cout << curr->data << "\t";
		curr = curr->next;
	}
	cout << endl;
}
list::~list()
{
	struct node *temp;
	temp = start;
	start = temp->next;
	delete temp;
}
int main()
{
	list stack;
	stack.push(10);
	stack.push(20);
	stack.push(30);
	stack.push(40);
	stack.push(50);
	stack.push(60);
	stack.push(70);
	stack.push(80);
	stack.push(90);
	stack.display();
	stack.pop();
	stack.display();
}