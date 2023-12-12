#pragma once
#ifndef s_h
#define s_h
#include<iostream>
#include"filehandler.h"
#include"c.h";
using namespace std;
class Help
{
public:
	static int strlength(string ch)
	{
		int i = 0;
		for (; ch[i] != '\0'; i++);
		return i;
	}
	static void strcopy(char* des, string src)
	{
		int i;
		for (i = 0; src[i] != '\0'; i++)
		{
			des[i] = src[i];
		}
		des[i] = '\0';
	}
	static char* GetStrFromBuffer(string arr)
	{
		int n = strlength(arr);
		char* temp = new char[n];
		strcopy(temp, arr);
		return temp;
	}
	static bool searchstr(char* str, const char*& substr)
	{

		for (int i = 0; str[i] != '\0'; i++)
		{
			if (substr[0] == str[i])
			{
				bool f1 = true;
				int k = i;
				for (int j = 0; substr[j] != '\0'; j++, k++)
				{
					if (str[k] != substr[j])
					{
						f1 = false;
					}
				}
				if (f1 == true)
				{
					return true;
				}
			}
		}
		return false;
	}
};
class Student
{
private:
	string name;
	string roll_num;
	int age;
	long long contact;
	//course* courses;
	char* attendance;
	int totalAttendance;
	int* marks;
	int totalmarks;
public:
	friend class FileHandler;
	Student();
	Student(string n, string r, int a, long long c, char* att, int* m, int t, int t1, string code);
	void MarkAttendance(string code);
	void AssignMarks(string code);
	Student(const Student& obj)
	{
		name = obj.name;
		roll_num = obj.roll_num;
		age = obj.age;
		contact = obj.contact;
		attendance = obj.attendance;
		marks = obj.marks;
	}
	void operator=(const Student& obj)
	{
		name = obj.name;
		roll_num = obj.roll_num;
		age = obj.age;
		contact = obj.contact;
		attendance = obj.attendance;
		marks = obj.marks;
		totalAttendance = obj.totalAttendance;
		if (totalAttendance > 0)
		{
			attendance = new char[totalAttendance];
			for (int i = 0; i < totalAttendance; i++)
			{
				attendance[i] = obj.attendance[i];
			}
		}
		totalmarks = obj.totalmarks;
		if (totalmarks > 0)
		{
			marks = new int[totalmarks];
			for (int i = 0; i < totalmarks; i++)
			{
				marks[i] = obj.marks[i];
			}
		}
	}
	friend void operator<<(ostream& out, Student& obj)
	{
		out << obj.name << "\t\t";
		out << obj.age << "\t\t";
		out << obj.roll_num << "\t\t";
		out << obj.contact << "\n\n";
	}
	string getname()
	{
		return name;
	}
	string getrollnum()
	{
		return roll_num;
	}
	int getage()
	{
		return age;
	}
	long long getconatct()
	{
		return contact;
	}
	int getTotalattendance()
	{
		return totalAttendance;
	}
	int getTotalmarks()
	{
		return totalmarks;
	}
	char* getattendance()
	{
		return attendance;
	}
	int* getmarks()
	{
		return marks;
	}
	void setattendance(int t)
	{
		totalAttendance = t;
		attendance = new char[totalAttendance];
		for (int i = 0; i < totalAttendance; i++)
		{
			attendance[i] = '_';
		}
	}
	void setmarks(int t)
	{
		totalmarks = t;
		marks = new int[totalmarks];
		for (int i = 0; i < totalmarks; i++)
		{
			marks[i] = 404;
		}
	}
	void updateStudent()
	{
		string a, b;
		cout << "\n\"enter the updated detail of student\"\n\n";
		cout << "enter first name = ";
		cin >> a;
		cout << "enter last name = ";
		cin >> b;
		name = a + " " + b;
		cout << "enter roll num = ";
		cin >> roll_num;
		cout << "enter age = ";
		cin >> age;
		cout << "enter the contact = ";
		cin >> contact;
	}
	void DisplayAttendance()
	{
		if (totalAttendance == 0)
		{
			cout << "there hasn't been any session held for the class to date!!!\n";
		}
		else
		{
			for (int i = 0; i < totalAttendance; i++)
			{
				cout << attendance[i];
				if (i != totalAttendance - 1)
				{
					cout << " , ";
				}
			}
			cout << endl;
		}
	}
	void DisplayMarks()
	{
		if (totalmarks == 0)
		{
			cout << "there hasn't been any session held for the class to date!!!\n";
		}
		else
		{
			for (int i = 0; i < totalmarks; i++)
			{
				cout << marks[i];
				if (i != totalmarks - 1)
				{
					cout << " , ";
				}
			}
			cout << endl;
		}
	}
	~Student()
	{
		name = "";
		roll_num = "";
		age = 0;
		contact = 0;
		if (attendance)
		{
			delete[] attendance;
		}
		else
		{
			attendance = 0;
		}
		if (marks)
		{
			delete[] marks;
		}
		else
		{
			marks = 0;
		}
	}
};
#endif 