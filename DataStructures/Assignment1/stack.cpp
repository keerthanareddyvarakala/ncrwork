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
	cout << "stack elements:" ;
	for (int i = 0; i <= sta.top; i++)
		cout <<sta.s[i] << "\t";
	cout << endl;
}
_stack_::~_stack_()
{
	delete sta.s;
}
int main()
{
	_stack_ st;
	int n;
	cout << "enter the size of the stack" << endl;
	cin >> n;
	st.getsize(n);
	st.push(10);
	st.push(20);
	st.push(30);
	cout<<"peek element:"<<st.peek()<<endl;
	cout<<"poped out element:"<<st.pop()<<endl;
	st.Display();
}
