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
	void insert_first(int);
	void insert_last(int);
	void insert_after(int,int);
	void insert_before(int,int);
	int delete_first();
	int delete_last();
	void del_spec(int);
	void travel_frwd();
	void travel_bkwd();
	void reverse();
	friend void print(struct node *curr);
	~list();
};
list::list()
{
	start = NULL;
}
void list::insert_first(int ele)
{
	struct node *temp;
	temp = new node;
	temp->data = ele;
	temp->next = start;
	start = temp;
}
void list::insert_last(int ele)
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
void list::insert_after(int sele, int ele)
{
	if (start != NULL)
	{
		struct node *curr;
		curr = start;
		while (curr != NULL && curr->data != sele)
			curr = curr->next;
		if (curr != NULL)
		{
			struct node *temp;
			temp = new node;
			temp->data = ele;
			temp->next = curr->next;
			curr->next = temp;
		}
		else
			cout << "ele not found" << endl;
	}
	else
		cout << "List is empty" << endl;
}
void list::insert_before(int sele, int ele)
{
	if (start->data = sele)
	{
		struct node *temp;
		temp = new node;
		temp->data = ele;
		temp->next = start;
		start = temp;

	}
	else
	{
		struct node *curr;
		curr = start;
		while (curr->next != NULL &&curr->next->data != sele)
			curr = curr->next;
		if (curr->next != NULL)
		{
			struct node *temp;
			temp = new node;
			temp->data = ele;
			temp->next = curr->next;
			curr->next = temp;
		}
		else
			cout << "ele not found" << endl;

	}
}
int list::delete_first()
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
int list::delete_last()
{
	int x = -1;
	if (start != NULL)
	{
		if (start->next == NULL)
		{
			x = start->data;
			delete start;
			start = NULL;
		}
		else
		{
			struct node *curr;
			curr = start;
			while (curr->next->next != NULL)
				curr = curr->next;
			x = curr->next->data;
			delete curr->next;
			curr->next = NULL;
		}
	}
	else
		cout << "list is empty" << endl;
	return x;
}
void list::del_spec(int ele)
{
	struct node *temp, *curr;
	if (start != NULL)
	{
		if (start->data == ele)
		{
			temp = start;
			start = temp->next;
			delete temp;
		}
		else
		{
			curr = start;
			while (curr->next != NULL && curr->next->data != ele)
				curr = curr->next;
			if (curr->next != NULL)
			{
				temp = curr->next;
				curr->next = temp->next;
				delete temp;
			}
			else
				cout << "not found" << endl;

		}

	}
}
void list::travel_frwd()
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
void print(struct node *curr)
{
	if (curr != NULL)
	{
		print(curr->next);
		cout << curr->data << "\t";
	}
}
void list::travel_bkwd()
{
	if (start != NULL)
		print(start);
	cout << endl;
}
void list::reverse()
{
	struct node *rev, *temp;
	rev = NULL;
	if (start != NULL || start->next != NULL)
	{
		while (start != NULL)
		{
			temp = start;
			start = temp->next;
			temp->next = rev;
			rev = temp;
		}
		start = rev;
	}
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
	list ll;
	ll.insert_first(20);
	ll.insert_last(40);
	ll.insert_last(50);
	ll.insert_after(50, 60);
	ll.insert_before(20, 70);
	ll.travel_frwd();
	ll.travel_bkwd();
	ll.delete_first();
	ll.delete_last();
	ll.del_spec(20);
	ll.travel_frwd();
	ll.travel_bkwd();
	ll.reverse();
}