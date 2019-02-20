#include<iostream>
using namespace std;
struct _Cqueue_
{
	int rear, front;
	int  size;
	int *q;
};
class Cqueue
{
	struct _Cqueue_ que;
public:
	Cqueue();
	void getsize(int);
	void Enqueue(int);
	int Dequeue();
	bool Overflow();
	bool Underflow();
	void display();
	~Cqueue();
};
void Cqueue::getsize(int n)
{
	que.size = n;
	que.q = new int[n];
}
Cqueue::Cqueue()
{
	que.rear = -1;
	que.front = -1;
	que.size = 0;
}
bool Cqueue::Underflow()
{
	return (que.front == -1);
}
bool Cqueue::Overflow()

{
	return ((que.rear == que.size - 1 && que.front == 0) || (que.rear == que.front - 1));
}

void Cqueue::Enqueue(int ele)
{
	if (!Overflow())
	{
		que.rear = (que.rear + 1) % que.size;
		if (que.front == -1)
			que.front = 0;
		que.q[que.rear] = ele;

	}
	else
		cout << "Cqueue is full";
}
int Cqueue::Dequeue()

{
	int n = -999;
	if (!Underflow())
	{
		/*if(que.front==que.rear)
		{
		que.front=que.rear=-1;
		}
		if(que.front==que.size-1)
		que.front=0;*/

		n = que.q[que.front];
		que.front = (que.front + 1) % que.size;


	}
	else
		cout << "Cqueue is empty";
	return n;
}
void Cqueue::display()
{
	for (int i = que.front; i <= que.rear; i++)
	{
		cout << que.q[i] << endl;
	}
}
Cqueue::~Cqueue()
{
	delete que.q;
}
int main()
{
	Cqueue a;
	int ele, k, n;
	cout << "Enter size:";
	cin >> n;
	a.getsize(n);
	int ch;
	cout << "Enter an operation to perform\n1.EnCqueue\n2.Dequeue\n3.Display\n";
	cin >> ch;

	while (ch <= 3 && ch != 0)
	{
		switch (ch)
		{
		case 1: cout << "Enter an element to insert:";
			cin >> ele;
			a.Enqueue(ele);
			break;
		case 2: k = a.Dequeue();
			cout << "\nDeleted element is:" << k;
			break;
		case 3:a.display();
			break;
		}
		cout << "\nEnter an operation to be performed:";
		cin >> ch;
	}
	return 0;
}