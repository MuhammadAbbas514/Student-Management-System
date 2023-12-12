#pragma once
#ifndef FILEHANDLER_H
#define FILEHANDLER_H
#include<string>
#include<fstream>
#include"c.h"
#include"Stu.h"
using namespace std;
class FileHandler
{
private:
	string filename;
	ios::openmode mode;
	fstream fin;
public:
	FileHandler()
	{
		fin;
	}
	void open(string f, ios::openmode m)
	{
		filename = f;
		mode = m;
		fin.open(filename, m);
	}
	void close()
	{
		fin.close();
	}
	void read(Course*& obj, int& t)
	{
		fin >> t;
		obj = new Course[t];
		string code, name, instructor, finstructor, linstructor;
		int credits, capacity;
		for (int i = 0; i < t; i++)
		{
			fin >> code;
			fin >> name;
			fin >> finstructor;
			fin >> linstructor;
			instructor = finstructor + " " + linstructor;
			fin >> credits;
			fin >> capacity;
			fstream tmp;
			Student* o = 0;
			int T;
			string fname = code + ".txt";
			tmp.open(fname, ios::in);
			if (tmp)
			{
				tmp >> T;
				o = new Student[T];
				string a, b;
				for (int j = 0; j < T; j++)
				{
					tmp >> a;
					tmp >> b;
					o[j].name = a + " " + b;
					tmp >> o[j].age;
					tmp >> o[j].roll_num;
					tmp >> o[j].contact;
					string fname1 = code + o[j].roll_num + ".txt";
					fstream tmp1;
					tmp1.open(fname1, ios::in);
					tmp1 >> o[j].totalAttendance;
					o[j].attendance = new char[o[j].totalAttendance];
					for (int k = 0; k < o[j].totalAttendance; k++)
					{
						tmp1 >> o[j].attendance[k];
					}
					tmp1.close();
					string fname2 = code + o[j].roll_num + "M" + ".txt";
					tmp1.open(fname2, ios::in);
					tmp1 >> o[j].totalmarks;
					o[j].marks = new int[o[j].totalmarks];
					for (int k = 0; k < o[j].totalmarks; k++)
					{
						tmp1 >> o[j].marks[k];
					}
					tmp1.close();
				}
			}
			else
			{
				T = 0;
				o = 0;
			}
			tmp.close();
			obj[i].readfromfile(code, name, instructor, credits, capacity, o, T);
		}
	}
	template<typename T>
	void operator<<(T a)
	{
		fin << a;
	}
	template<typename T>
	void operator>>(T& n)
	{
		fin >> n;
	}
	bool operator!()
	{
		return (fin.eof() == 0);
	}
};
#endif // !FILEHANDLER_H
