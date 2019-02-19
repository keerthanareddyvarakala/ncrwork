#include<iostream>
using namespace std;

struct __stack__
{
	int top;
	int *s;
	int size;
};
class _stack_
{
	struct __stack__ sta;
public:
	_stack_();
	void push(int);
	int pop();
	int peek();
	bool isEmpty();
	bool isFull();
	void Display();
	~_stack_();
	void getsize(int);

};
_stack_::_stack_()
{
	sta.top = -1;
	sta.s = NULL;
	sta.size = 0;

}
void _stack_::getsize(int n)
{
	sta.size = n;
	sta.s = new int[n];
}
bool _stack_::isFull()
{
	return (sta.top == (sta.size - 1));
}
bool _stack_::isEmpty()
{
	return (sta.top == -1);
}
void _stack_::push(int ele)
{
	if (!isFull())
	{
		sta.s[++sta.top] = ele;

	}
	else
		cout << "Stack is full" << endl;
}
int _stack_::pop()
{
	int x = -999;
	if (!isEmpty())
		x = sta.s[sta.top--];
	else
		cout << "stack is empty" << endl;
	return x;
}
int _stack_::peek()

{
	int x = -999;
	if (!isEmpty())
		x = sta.s[sta.top];
	else
		cout << "stack is empty" << endl;
	return x;
}
void _stack_::Display()
{
	cout << "stack elements:";
	for (int i = 0; i <= sta.top; i++)
		cout << sta.s[i] << "\t";
	cout << endl;
}
_stack_::~_stack_()
{
	delete sta.s;
}
int number(char a)
{
	switch (a)
	{
	case '+':
	case '-':
		return 2;
	case '*':
	case '/':
		return 3;
	case '(':
		return 1;
	case ')':
		return 4;
	}
}


void main()
{
	char in[10], op[10];
	cin >> in;
	int j = 0, val, count = 0;
	int len = strlen(in);
	_stack_ a;
	a.getsize(len);
	for (int i = 0; i < len; i++)
	{
		char ch = in[i];
		if ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'B'))
		{
			op[j] = ch;
			j++;
		}
		else
		{
			if (a.isEmpty())
			{
				a.push(ch);
			}
			else
			{
				if (number(ch) > number(a.peek()))
				{
					if (number(ch) == 4)
					{
						while (a.peek() != '(')
						{
							op[j] = a.peek();
							j++;
							a.pop();
						}
						a.pop();

					}
					else
						a.push(ch);
				}

				else
				{
					if (number(ch) == 1)
					{
						a.push(ch);
					}
					else
					{
						while (!a.isEmpty())
						{
							op[j] = a.peek();
							j++;
							a.pop();
						}
						a.push(ch);
					}
				}
			}
		}
	}
	while (!a.isEmpty())
	{
		op[j] = a.peek();
		j++;
		a.pop();
	}
	for (int k = 0; k <j; k++)
		cout << op[k];
}