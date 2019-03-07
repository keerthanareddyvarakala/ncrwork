#include<iostream>
#include<string>
#include<stack>
#include<queue>
using namespace std;
double divi(double, double);
double add(double, double);
double sub(double, double);
double mul(double, double);
bool balancingParanthesis(string expression)
{
	stack<char> string;
	char ch;
	for (int i = 0; i < expression.length(); i++)
	{
		if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[')
		{
			string.push(expression[i]);
			continue;
		}
		if (string.empty())
			return true;

		switch (expression[i])
		{
		case ')':

			ch = string.top();
			string.pop();
			if (ch == '{' || ch == '[')
				return false;
			break;

		case '}':

			ch = string.top();
			string.pop();
			if (ch == '(' || ch == '[')
				return false;
			break;

		case ']':

			ch = string.top();
			string.pop();
			if (ch == '(' || ch == '{')
				return false;
			break;
		}
	}
	return (string.empty());
}

int postfixEvaluation(string str) {
	stack<double> eval;
	double left, right;
	int i = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (isdigit(str[i]))
		{
			double a = (double)str[i];
			eval.push(a - 48);
		}
		else
		{
			if (str[i] == '*') {
				right = eval.top();
				eval.pop();
				left = eval.top();
				eval.pop();
				double res = mul(left, right);
				eval.push(res);
			}
			if (str[i] == '/') {
				right = eval.top();
				eval.pop();
				left = eval.top();
				eval.pop();
				double res = divi(left, right);
				eval.push(res);
			}
			if (str[i] == '+') {
				right = eval.top();
				eval.pop();
				left = eval.top();
				eval.pop();
				double s = add(left, right);
				eval.push(s);
			}
			if (str[i] == '-') {
				left = eval.top();
				eval.pop();
				right = eval.top();
				eval.pop();
				double s = sub(left, right);
				eval.push(s);
			}
		}

	}
	cout << endl << "result is " << eval.top();
	return 0;
}

int priority(char pri)
{
	if (pri == '/' || pri == '*')
		return 2;
	else if (pri == '-' || pri == '+')
		return 1;
	else
		return -1;
}
int main()
{
	stack<char> calc;
	string input, postfix, post_eval;
	cout << "enter an equation :";
	cin >> input;
	if (!balancingParanthesis(input))
	{
		cout << "Invalid Expression" << endl;
		getchar();
		return 0;
	}
	else
	{
		int len = input.length();
		char c;

		for (int i = 0; i < len; i++)
		{
			if (isdigit(input[i]))
			{
				postfix += input[i];
			}
			else if (input[i] == '(')
			{
				calc.push(input[i]);
			}
			else if (input[i] == ')')
			{
				while (!calc.empty() && calc.top() != '(')
				{
					c = calc.top();
					calc.pop();
					postfix += c;
				}
				if (calc.top() == '(') {
					c = calc.top();
					calc.top();
				}
			}
			else
			{
				while (!calc.empty() && priority(input[i]) <= priority(calc.top())) {
					c = calc.top();
					calc.pop();
					postfix += c;
				}
				calc.push(input[i]);
			}
		}
		while (!calc.empty()) {
			c = calc.top();
			calc.pop();
			postfix += c;
		}
		for (int i = 0; i < len; i++) {
			if (postfix[i] == '(') {
				continue;
			}
			post_eval += postfix[i];
		}
		postfixEvaluation(post_eval);
	}
	getchar();
	getchar();
	return 0;
}
