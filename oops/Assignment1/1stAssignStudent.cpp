#include<iostream>
using namespace std;
class Student
{
public:
	char *name;
	char grade;
	int marks1, marks2, marks3;

};
class CollegeCourse
{
public:
	Student s1;
	float avg;
	void set_data(char *s,char g,int m1,int m2,int m3)
	{
		
		int len = strlen(s);
		s1.name = (char *)malloc(sizeof(char)*len);
		strcpy(s1.name,s);
		s1.grade = g;
		s1.marks1 = m1;
		s1.marks2 = m2;
		s1.marks3 = m3;
		cout << s << "\t"<< g << "\t" << m1 << "\t" << m2 << "\t" << m3 << endl;
	}
	void compute_avg()
	{
		
		avg = (s1.marks1 + s1.marks2 + s1.marks3) / 3;
		cout << "avg is " << avg << endl;
	}
	void compute_grade()
	{
		if (avg > 60)
		{
			cout << "First class" << endl;
		}
		if (50 <avg > 60 )
		{
			cout << "Second class" << endl;

		}
		if (40 <avg > 50)
		{
			cout << "third class" << endl;
		}
		if (avg < 40)
		{
			cout << "Fail" << endl;
		}
	}
};
void main()
{
	CollegeCourse c1;
	c1.set_data("malu", 'A', 80, 70, 90);
	c1.compute_avg();
	c1.compute_grade();

}