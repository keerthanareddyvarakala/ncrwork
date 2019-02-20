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
	void enqueue(int);
	int dequeue();
	void display();
	~list();
};
list::list()
{
	start = NULL;
}
void list::enqueue(int ele)
{
	struct node *temp, *curr;
	temp = new node;
	temp->data = ele;
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
int list::dequeue()
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
	list queue;
	queue.enqueue(10); 
	queue.enqueue(20);
	queue.enqueue(30);
	queue.enqueue(40);
	queue.enqueue(50);
	queue.enqueue(60);
	queue.enqueue(70);
	queue.enqueue(80);
	queue.enqueue(90);
	queue.enqueue(100);
	queue.display();
	queue.dequeue();
	queue.display();


}