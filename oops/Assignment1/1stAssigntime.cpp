#include<iostream>
using namespace std;
class time
{
	int hours;
	int minutes;
	int seconds;
public:
	time()
	{
		hours = minutes = seconds = 0;
	}
	time(int h, int m, int s)
	{
		hours = h;
		minutes = m;
		seconds = s;
	}
	void display()
	{
		cout << hours << ":" << minutes << ":" << seconds << endl;
	}
	void add_time(time &t1, time &t2)
	{
		hours = t1.hours + t2.hours;
		minutes = t1.minutes + t2.minutes;
		if (minutes > 60)
		{
			hours++;
			minutes =  minutes -60;
		}
		seconds = t1.seconds + t2.seconds;
		if (seconds > 60)
		{
			minutes++;
			seconds = seconds-60;
		}
		if (hours > 23)
		{
			hours = 0;
		}

	}
};
void main()
{
	time t1(10, 10, 40), t2(20, 20, 30), t3;
	t1.display();
	t2.display();
	t3.add_time(t1, t2);
	t3.display();

}