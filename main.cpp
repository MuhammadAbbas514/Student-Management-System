#include<iostream>
#include<fstream>
#include<string>
#include<Windows.h>
#include"Filehandler.h"
#include"c.h"
#include"Stu.h"
#include<stdio.h>
using namespace std;

class Course;
class Student;
class Filehandler;
bool checkrollnum(string r)
{
	if (r.length() != 8)
	{
		return true;
	}
	if (r[2] != 'L')
	{
		return true;
	}
	if (r[3] != '-')
	{
		return true;
	}
	return false;
}
Student::Student()
{
	name = "";
	roll_num = "";
	age = 0;
	contact = 0;
	//courses = co;
	attendance = 0;
	totalAttendance = 0;
	marks = 0;
	totalmarks = 0;
}
Student::Student(string n, string r, int a, long long c, char* att, int* m, int t, int t1 ,string code)
{
	name = n;
	roll_num = r;
	age = a;
	contact = c;
	attendance = att;
	totalAttendance = t;
	marks = m;
	totalmarks = t1;
	string f = code + roll_num + ".txt";
	FileHandler fin;
	fin.open(f, ios::out);
	fin.close();
	f = code + roll_num + "M.txt";
	fin.open(f, ios::out);
	fin.close();
}
void Student::AssignMarks(string code)
{
	if (totalmarks > 0)
	{
		for (int i = 0; i < totalmarks; i++)
		{
			cout << marks[i] << " - ";
		}
		int today;
		cin >> today;
		int* temp;

		int len = totalmarks + 1;
		temp = new int[len];
		int k = 0;
		for (k; k < totalmarks; k++)
		{
			temp[k] = marks[k];
		}
		temp[k] = today;
		delete[] marks;
		marks = temp;
		totalmarks = len;
		string f = roll_num + "M" + ".txt";
		const char* filename = Help::GetStrFromBuffer(code + f);
		remove(filename);
		FileHandler fin;
		fin.open(filename, ios::app);
		fin << totalmarks;
		fin << '\n';
		for (int i = 0; i < totalmarks; i++)
		{
			fin << marks[i];
			fin << '\t';
		}
		fin.close();
	}
	else
	{
		totalmarks = totalmarks + 1;
		marks = new int[totalmarks];
		cin >> marks[totalmarks - 1];
		string f = roll_num + "M" + ".txt";
		const char* filename = Help::GetStrFromBuffer(code + f);
		FileHandler fin;
		fin.open(filename, ios::app);
		fin << totalmarks;
		fin << '\n';
		fin << marks[totalmarks - 1];
		fin << '\t';
		fin.close();
	}
}
void Student::MarkAttendance(string code)
{
	if (totalAttendance > 0)
	{
		for (int i = 0; i < totalAttendance; i++)
		{
			cout << attendance[i] << " , ";
		}
		char today;
		cin >> today;
		char* temp;

		int len = totalAttendance + 1;
		temp = new char[len];
		int k = 0;
		for (k; k < totalAttendance; k++)
		{
			temp[k] = attendance[k];
		}
		temp[k] = today;
		delete[] attendance;
		attendance = temp;
		totalAttendance = len;
		string f = roll_num + ".txt";
		const char* filename = Help::GetStrFromBuffer(code + f);
		remove(filename);
		FileHandler fin;
		fin.open(filename, ios::app);
		fin << totalAttendance;
		fin << '\n';
		for (int i = 0; i < totalAttendance; i++)
		{
			fin << attendance[i];
			fin << '\t';
		}
		fin.close();
	}
	else
	{
		totalAttendance = totalAttendance + 1;
		attendance = new char[totalAttendance];
		cin >> attendance[totalAttendance - 1];
		string f = roll_num + ".txt";
		const char* filename = Help::GetStrFromBuffer(code + f);
		FileHandler fin;
		fin.open(filename, ios::app);
		fin << totalAttendance;
		fin << '\n';
		fin << attendance[totalAttendance - 1];
		fin << '\t';
		fin.close();
	}
}
Course::Course()
{
	code = " ";
	name = " ";
	instructor = " ";
	credits = 0;
	students = 0;
	totalStudents = 0;
}
Course::Course(string c, string n, string ins, int cre, int cap, int ts, Student* st)
{
	code = c;
	name = n;
	instructor = ins;
	credits = cre;
	capacity = cap;
	students = st;
	totalStudents = ts;
}
Course::~Course()
{
	code = " ";
	name = " ";
	instructor = " ";
	credits = 0;
	totalStudents = 0;
	if (students)
	{
		delete[] students;
	}
	else
	{
		students = 0;
	}
}
void Course::AssignMarks()
{
	for (int i = 0; i < totalStudents; i++)
	{
		cout << students[i].getname() << " : ";
		students[i].AssignMarks(code);
	}
}
void Course::DisplayMarks()
{
	for (int i = 0; i < totalStudents; i++)
	{
		cout << students[i].getname() << " : ";
		students[i].DisplayMarks();
	}
}
void Course::MarkAttendance()
{
	for (int i = 0; i < totalStudents; i++)
	{
		cout << students[i].getname() << " : ";
		students[i].MarkAttendance(code);
	}
}
void Course::DisplayAttendance()
{
	for (int i = 0; i < totalStudents; i++)
	{
		cout << students[i].getname() << " : ";
		students[i].DisplayAttendance();
	}
}
string Course::getcode()
{
	return code;
}
string Course::getname()
{
	return name;
}
string Course::getinstructor()
{
	return instructor;
}
int Course::getcredits()
{
	return credits;
}
int Course::getcapacity()
{
	return capacity;
}
void Course::Input()
{
	system("cls");
	string fname, lname;
	cout << "Enter the code of course = ";
	cin >> code;
	cout << "Enter the name of the course in the format (First name-second name) = ";
	cin >> name;
	cout << "Enter the first name of instructor = ";
	cin >> fname;
	cout << "Enter the second name of instructor = ";
	cin >> lname;
	instructor = fname + " " + lname;
	cout << "Enter the credits hour of course = ";
	cin >> credits;
	cout << "Enter the capacity of students = ";
	cin >> capacity;
	totalStudents = 0;
	students = 0;
}
void Course::operator=(const Course& obj)
{
	code = obj.code;
	name = obj.name;
	instructor = obj.instructor;
	credits = obj.credits;
	capacity = obj.capacity;
	totalStudents = obj.totalStudents;
	students = new Student[totalStudents];
	for (int i = 0; i < totalStudents; i++)
	{
		students[i] = obj.students[i];
	}
}
void Course::DisplayStudents()
{
	system("cls");
	cout << code << "\t\t"
		<< name << "\t\t"
		<< instructor << "\t\t"
		<< credits << "\t\t"
		<< capacity << "\t\t\t\n\n"
		"Total nummber of Students enrolled : " << totalStudents << "\n\n";
	for (int i = 0; i < totalStudents; i++)
	{
		cout << students[i];
	}
	Sleep(3000);
}
Course* Course::EditStudentDetail(int t)
{
	Course* temp = this;
	string roll;
	int len, a, b;
	bool flag = false;
	system("cls");
	do
	{
		cout << "Enter the Roll number of Student in Format(XXL-XXXX) : ";
		cin >> roll;
	} while (checkrollnum(roll));
	for (int i = 0; i < t; i++)
	{
		len = temp[i].totalStudents;
		for (int j = 0; j < len; j++)
		{
			if (roll == temp[i].students[j].getrollnum())
			{
				temp[i].students[j].updateStudent();
				a = i;
				b = j;
				flag = true;
				FileHandler fin;
				const char* filename;
				filename = Help::GetStrFromBuffer(temp[i].code + ".txt");
				remove(filename);
				fin.open(filename, ios::app);
				fin << temp[i].totalStudents;
				fin << '\n';
				for (int k = 0; k < temp[i].totalStudents; k++)
				{
					fin << temp[i].students[k].getname();
					fin << "\t\t";
					fin << temp[i].students[k].getage();
					fin << "\t\t";
					fin << temp[i].students[k].getrollnum();
					fin << "\t\t";
					fin << temp[i].students[k].getconatct();
					fin << '\n';
				}
				fin.close();
				break;
			}
		}
		if (flag == true) break;
	}
	if (flag == true && a != t - 1)
	{
		for (int i = a + 1; i < t; i++)
		{
			len = temp[i].totalStudents;
			for (int j = 0; j < len; j++)
			{
				if (roll == temp[i].students[j].getrollnum())
				{
					temp[i].students[j] = temp[a].students[b];
					FileHandler fin;
					const char* filename;
					filename = Help::GetStrFromBuffer(temp[i].code + ".txt");
					remove(filename);
					fin.open(filename, ios::app);
					fin << temp[i].totalStudents;
					fin << '\n';
					for (int k = 0; k < temp[i].totalStudents; k++)
					{
						fin << temp[i].students[k].getname();
						fin << "\t\t";
						fin << temp[i].students[k].getage();
						fin << "\t\t";
						fin << temp[i].students[k].getrollnum();
						fin << "\t\t";
						fin << temp[i].students[k].getconatct();
						fin << '\n';
					}
					fin.close();
				}
			}
		}

	}
	else
	{
		cout << "Student not found!!!\n";
		return this;
	}
	return temp;
}
void Course::removeStudent()
{
	FileHandler fin;
	string roll;
	Student* temp;
	int len;
	system("cls");
	do
	{
		cout << "Enter the Roll number of Student in format(XXL-XXXX) : ";
		cin >> roll;
	} while (checkrollnum(roll));
	bool flag = false;
	for (int i = 0; i < totalStudents; i++)
	{
		if (roll == students[i].getrollnum())
		{
			flag = true;
			len = totalStudents - 1;
			temp = new Student[len];
			int k = 0;
			for (int j = 0; j < totalStudents; j++)
			{
				if (roll == students[j].getrollnum())
				{
					const char* filename;
					string removefile = code + students[j].getrollnum();
					filename = Help::GetStrFromBuffer(removefile + ".txt");
					remove(filename);
					removefile = code + students[j].getrollnum() + "M";
					filename = Help::GetStrFromBuffer(removefile + ".txt");
					remove(filename);
					continue;
				}
				else
				{
					temp[k] = students[j];
					k++;
				}
			}
			delete[] students;
			students = temp;
			totalStudents = len;
		}

	}
	if (!flag)
	{
		cout << "Roll num not found!!!\n";
	}
	const char* filename;
	filename = Help::GetStrFromBuffer(code + ".txt");
	remove(filename);
	fin.open(filename, ios::app);
	fin << totalStudents;
	fin << '\n';
	for (int i = 0; i < totalStudents; i++)
	{
		fin << students[i].getname();
		fin << "\t\t";
		fin << students[i].getage();
		fin << "\t\t";
		fin << students[i].getrollnum();
		fin << "\t\t";
		fin << students[i].getconatct();
		fin << '\n';
	}
	fin.close();
	Sleep(100);
}
void Course::enrollStudent()
{
	FileHandler fin;
	int tmp = totalStudents;
	totalStudents++;
	string name, roll_num, fname, lname;
	int age, * y = 0, t = 0 , t1 = 0;
	long long contact;
	char* a = 0;
	system("cls");
	cout << "First name : ";
	cin >> fname;
	cout << "Last name : ";
	cin >> lname;
	name = fname + " " + lname;
	cout << "Age : ";
	cin >> age;
	do
	{
		cout << "Roll num in format(XXL-XXXX) : ";
		cin >> roll_num;
	} while (checkrollnum(roll_num));
	cout << "Contact : ";
	cin >> contact;
	if (tmp > 0)
	{
		Student* temp = new Student[totalStudents];
		for (int i = 0; i < tmp; i++)
		{
			temp[i] = students[i];
		}
		temp[totalStudents - 1] = Student(name, roll_num, age, contact, a, y, t,t1, code);
		int kia = temp[0].getTotalattendance();
		temp[totalStudents - 1].setattendance(kia);
		int kia1 = temp[0].getTotalmarks();
		temp[totalStudents - 1].setmarks(kia);
		char* att = temp[totalStudents - 1].getattendance();
		int* mar = temp[totalStudents - 1].getmarks();
		const char* filename;
		string removefile = code + temp[totalStudents - 1].getrollnum();
		filename = Help::GetStrFromBuffer(removefile + ".txt");
		fin.open(filename, ios::app);
		fin << temp[0].getTotalattendance();
		fin << "\n";
		for (int i = 0; i < kia; i++)
		{
			fin << att[i];
			fin << "\t";
		}
		fin.close();
		removefile = code + temp[totalStudents - 1].getrollnum() + "M";
		filename = Help::GetStrFromBuffer(removefile + ".txt");
		fin.open(filename, ios::app);
		fin << kia1;
		fin << "\n";
		for (int i = 0; i < kia1; i++)
		{
			fin << mar[i];
			fin << "\t";
		}
		fin.close();
		delete[] students;
		students = temp;
	}
	else
	{
		Student* temp = new Student(name, roll_num, age, contact, a, y, t ,t1 ,code);
		students = temp;
	}
	const char* filename;
	filename = Help::GetStrFromBuffer(code + ".txt");
	remove(filename);
	fin.open(filename, ios::app);
	fin << totalStudents;
	fin << '\n';
	for (int i = 0; i < totalStudents; i++)
	{
		fin << students[i].getname();
		fin << "\t\t";
		fin << students[i].getage();
		fin << "\t\t";
		fin << students[i].getrollnum();
		fin << "\t\t";
		fin << students[i].getconatct();
		fin << '\n';
	}
	fin.close();
	Sleep(100);
}
void Course::readfromfile(string c, string n, string ins, int cre, int cap, Student* obj, int t)
{
	code = c;
	name = n;
	instructor = ins;
	credits = cre;
	capacity = cap;
	totalStudents = t;
	if (t > 0)
	{
		students = new Student[t];
		for (int i = 0; i < t; i++)
		{
			students[i] = obj[i];
		}
	}
	else
	{
		totalStudents = 0;
		students = 0;
	}
}
void Course::Availablecourse()
{
	cout << "(" << code << ") - " << name << endl;
}
class System
{
private:
	Course* courses;
	int totalcourses;
	int menus;
	FileHandler fin;
public:
	System()
	{
		courses = 0;
		totalcourses = 0;
		menus = 0;
		fin;
		fin.open("courses.txt", ios::in);
		fin.read(courses, totalcourses);
		fin.close();
	}
	void mainmenu()
	{
	start:
		system("cls");
		cout << "\t1 - Enroll a student\n";
		cout << "\t2 - Course Registration\n";
		cout << "\t3 - Attendance\n";
		cout << "\t4 - Marks\n";
		cout << "\t5 - Exit\n";
		cin >> menus;
		if (menus > 5 || menus < 0)
		{
			system("cls");
			cout << "\n\n\t\tInvalid input!!\n";
			Sleep(3000);
			goto start;
		}
		else if (menus <= 4)
		{
			this->submenu(menus);
		}
		else if (menus == 5)
		{
			system("cls");
			cout << "\n\n\n\t\t\t===================================\n";
			cout <<       "\t\t\t======= Thank you for using =======\n";
			cout <<       "\t\t\t===================================\n";
			cout << "\n\n\n\n\n\"\Teddy\"\n";
		}
		Sleep(100);
	}
	void submenu(int i)
	{
		int in;
	start:
		system("cls");
		if (i == 1)
		{
			cout << "\t1 - Display Already Enrolled Students\n";
			cout << "\t2 - Add a Student\n";
			cout << "\t3 - Remove a Student\n";
			cout << "\t4 - Edit Student Detail\n";
			cout << "\t5 - back\n";
			cin >> in;
			if (in > 5 || in < 0)
			{
				system("cls");
				cout << "\n\n\t\tInvalid input!!\n";
				Sleep(3000);
				goto start;
			}
			else if (in == 1)
			{
				for (int i = 0; i < totalcourses; i++)
				{
					courses[i].DisplayStudents();
				}
				goto start;
			}
			else if (in == 2)
			{
			a:
				int i = 0;
				system("cls");
				cout << "\t\"Available course\"\n\n";
				for (int j = 0; j < totalcourses; j++)
				{
					cout << "\t" << j << " - ";
					courses[j].Availablecourse();
				}
				do
				{
					if (i < 0 || i > totalcourses - 1)
					{
						system("cls");
						cout << "\n\n\t\tInvalid input!!\n";
						Sleep(3000);
						goto a;
					}
					cout << "\nIn which Course you want to Add Student = ";
					cin >> i;
				} while (i < 0 || i > totalcourses - 1);
				courses[i].enrollStudent();
				Sleep(3000);
				goto start;
			}
			else if (in == 3)
			{
			b:
				int i = 0;
				system("cls");
				cout << "\t\"Available course\"\n\n";
				for (int j = 0; j < totalcourses; j++)
				{
					cout << "\t" << j << " - ";
					courses[j].Availablecourse();
				}
				do
				{
					if (i < 0 || i > totalcourses - 1)
					{
						system("cls");
						cout << "\n\n\t\tInvalid input!!\n";
						Sleep(3000);
						goto b;
					}
					cout << "\nIn which Course you want to Remove Student = ";
					cin >> i;
				} while (i < 0 || i > totalcourses - 1);
				courses[i].removeStudent();
				Sleep(3000);
				goto start;

			}
			else if (in == 4)
			{
				courses = courses->EditStudentDetail(totalcourses);
				Sleep(3000);
				goto start;
			}
			else if (in == 5)
			{
				this->mainmenu();
			}
		}
		else if (i == 2)
		{
			cout << "\t1 - Available Courses\n";
			cout << "\t2 - Register Course\n";
			cout << "\t3 - back\n";
			cin >> in;
			if (in > 3 || in < 0)
			{
				system("cls");
				cout << "\n\n\t\tInvalid input!!\n";
				Sleep(3000);
				goto start;
			}
			else if (in == 1)
			{
				system("cls");
				cout << "\t\"Available course\"\n\n";
				for (int j = 0; j < totalcourses; j++)
				{
					courses[j].Availablecourse();
				}
				Sleep(3000);
				goto start;
			}
			else if (in == 2)
			{
				int len = totalcourses + 1, i = 0;
				Course* temp = new Course[len];
				for (i; i < totalcourses; i++)
				{
					temp[i] = courses[i];
				}
				temp[i].Input();
				delete[] courses;
				courses = temp;
				totalcourses = len;
				remove("courses.txt");
				fin.open("courses.txt", ios::app);
				fin << totalcourses;
				fin << '\n';
				for (int j = 0; j < totalcourses; j++)
				{
					fin << courses[j].getcode();
					fin << "\t\t";
					fin << courses[j].getname();
					fin << "\t\t";
					fin << courses[j].getinstructor();
					fin << "\t\t";
					fin << courses[j].getcredits();
					fin << "\t\t";
					fin << courses[j].getcapacity();
					fin << '\n';
				}
				fin.close();
				Sleep(3000);
				goto start;
			}
			else if (in == 3)
			{
				this->mainmenu();
			}
		}
		else if (i == 3)
		{
			cout << "\t1 - Display Attendance(subject wise)\n";
			cout << "\t2 - Mark Attendance.\n";
			cout << "\t3 - back\n";
			cin >> in;
			if (in > 3 || in < 0)
			{
				system("cls");
				cout << "\n\n\t\tInvalid input!!\n";
				Sleep(3000);
				goto start;
			}
			else if (in == 1)
			{
			c:
				int i = 0;
				system("cls");
				cout << "\t\"Available course\"\n\n";
				for (int j = 0; j < totalcourses; j++)
				{
					cout << "\t" << j << " - ";
					courses[j].Availablecourse();
				}
				do
				{
					if (i < 0 || i > totalcourses - 1)
					{
						system("cls");
						cout << "\n\n\t\tInvalid input!!\n";
						Sleep(3000);
						goto c;
					}
					cout << "\nFor which course you want to Display Attendance = ";
					cin >> i;
				} while (i < 0 || i > totalcourses - 1);
				courses[i].DisplayAttendance();
				Sleep(3000);
				goto start;
			}
			else if (in == 2)
			{
			d:
				int i = 0;
				system("cls");
				cout << "\t\"Available course\"\n\n";
				for (int j = 0; j < totalcourses; j++)
				{
					cout << "\t" << j << " - ";
					courses[j].Availablecourse();
				}
				do
				{
					if (i < 0 || i > totalcourses - 1)
					{
						system("cls");
						cout << "invalid input!!\n";
						Sleep(3000);
						goto d;
					}
					cout << "\nFor which course you want to Mark Attendance = ";
					cin >> i;
				} while (i < 0 || i > totalcourses - 1);
				courses[i].MarkAttendance();
				Sleep(3000);
				goto start;
			}
			else if (in == 3)
			{
				this->mainmenu();
			}
		}
		else if (i == 4)
		{
			cout << "\t1 - Display Marks(subject wise)\n";
			cout << "\t2 - Assign Marks.\n";
			cout << "\t3 - back\n";
			cin >> in;
			if (in > 3 || in < 0)
			{
				system("cls");
				cout << "\n\n\t\tInvalid input!!\n";
				Sleep(3000);
				goto start;
			}
			else if (in == 1)
			{
				int i = 0;
			e:
				system("cls");
				cout << "\t\"Available course\"\n\n";
				for (int j = 0; j < totalcourses; j++)
				{
					cout << "\t" << j << " - ";
					courses[j].Availablecourse();
				}
				do
				{
					if (i < 0 || i > totalcourses - 1)
					{
						system("cls");
						cout << "\n\n\t\tInvalid input!!\n";
						Sleep(3000);
						goto e;
					}
					cout << "\nFor which course you want to Display Marks = ";
					cin >> i;
				} while (i < 0 || i > totalcourses - 1);
				courses[i].DisplayMarks();
				Sleep(3000);
				goto start;
			}
			else if (in == 2)
			{
				int i = 0;
			f:
				system("cls");
				cout << "\t\"Available course\"\n\n";
				for (int j = 0; j < totalcourses; j++)
				{
					cout << "\t" << j << " - ";
					courses[j].Availablecourse();
				}
				do
				{
					if (i < 0 || i > totalcourses - 1)
					{
						system("cls");
						cout << "\n\n\t\tInvalid input!!\n";
						Sleep(3000);
						goto f;
					}
					cout << "\nFor which course you want to Assign Marks = ";
					cin >> i;
				} while (i < 0 || i > totalcourses - 1);
				courses[i].AssignMarks();
				Sleep(3000);
				goto start;
			}
			else if (in == 3)
			{
				this->mainmenu();
			}
		}
		Sleep(100);
	}
};
int main()
{
	system("cls");
	cout << "\n\n\n\t\t\t===================================\n";
	cout << "\t\t\t========= Welcome to FLEX =========\n";
	cout << "\t\t\t===================================\n";
	Sleep(4000);
	System s;
	s.mainmenu();
	return 0;
}