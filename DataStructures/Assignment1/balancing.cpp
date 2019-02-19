#include<iostream>
#include<string.h>
#include<ctype.h>
using namespace std;
struct __stack__
{
	char top;
	char *s;
	int size;
};
class _stack_
{
	struct __stack__ sta;
public:
	_stack_();
	void push(char);
	char pop();
	char peek();
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
	sta.s = new char[n];
}
bool _stack_::isFull()
{
	return (sta.top == (sta.size - 1));
}
bool _stack_::isEmpty()
{
	return (sta.top == -1);
}
void _stack_::push(char ele)
{
	if (!isFull())
	{
		sta.s[++sta.top] = ele;

	}
	else
		cout << "Stack is full" << endl;
}
char _stack_::pop()
{
	char x;
	if (!isEmpty())
		x = sta.s[sta.top--];
	else
		cout << "stack is empty" << endl;
	return x;
}
char _stack_::peek()

{
	char x;
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
void main()
{
	char str[20];
	cin >> str;
	_stack_ a;
	int n = strlen(str);

	a.getsize(n);
	int flag = 0;
	for (int i = 0; i < n; i++)
	{
		char ch = str[i];
		switch (ch)
		{
		case '(':a.push(ch);
			break;
		case '[':a.push(ch);
			break;
		case '{': a.push(ch);
			break;
		case ')':
		case ']':
		case '}':
			if (!a.isEmpty())
			{
				if ((ch == ')'&&a.peek() == '(') || (ch == ']'&&a.peek() == '[') || (ch == '}'&&a.peek() == '{'))
				{
					a.pop();
					break;
				}
				else
				{

					flag = 1;
					break;
				}
			}
			else
				flag = 1;

		}

	}
	if (!a.isEmpty())
		flag = 1;
	if (flag == 1)
	{
		cout << "not balanced";
		return;
	}

	if (flag == 0)
		cout << "balanced";
	a.Display();
}
	