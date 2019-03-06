#include<iostream>
#include<stack>
#include<string>
#include<ctype.h>
#include<cmath>

using namespace std;

extern int add(int a, int b);
extern int sub(int a, int b);
extern int mul(int a, int b);
extern int div(int a, int b);

int main()
{
	stack<int> st;
	st.push(0);
	string s;
	cout << "Enter" << endl;
	cin >> s;
	int c1, c2;
	int i = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (isdigit(s[i]))
		{
			int a;
			a = (int)s[i];
			//cout<<a-48;
			st.push(a - 48);
		}
	
		else 
		{
			if (s[i] == '*') 
			{
				c1 = st.top();
				st.pop();
				c2 = st.top();
				st.pop();
				int s = mul(c2,c1);
				st.push(s);
			}
			if (s[i] == '/') 
			{
				c1 = st.top();
				st.pop();
				c2 = st.top();
				st.pop();
				int s = divi(c2,c1);
				st.push(s);
			}
			if (s[i] == '+') 
			{
				c1 = st.top();
				st.pop();
				c2 = st.top();
				st.pop();
				int s = add(c2,c1);
				st.push(s);
			}
			if (s[i] == '-') 
			{
				c1 = st.top();
				st.pop();
				c2 = st.top();
				st.pop();
				int s = sub(c2,c1);
				st.push(s);
			}
		}

	}
	cout << st.top();
	return 0;
}
