#include "stdafx.h"
#include <iostream>
#include <fstream> 
#include <locale>
#include <math.h>
#include <list>
#include <Windows.h>

using namespace std;

class Student
{
	public: int id;

	public: string frstName;
	public: string lastName;
	public: string prevName;

	public: string group;

	public: Student (int id, string frstName, string lastName, string prevName, string group)
	{
		this->id = id;
		this->frstName = frstName;
		this->lastName = lastName;
		this->prevName = prevName;
		this->group = group;
	}
	bool operator == (const Student &student) const {
	   return this->id == student.id;
	}
	public: void View()
	{ 
		cout << "\tid: " << id << endl
			<< "\t���: " << frstName << endl
			<< "\t�������: " << lastName << endl
			<< "\t��������: " << prevName << endl
			<< "\t������: " << group << endl
			<< endl;  	
	}
};

class Sanatroty
{
	public: list <Student> Students;

	public: Sanatroty()
	{
		Load();
	}

	public: void Add()
	{
		string a,b,c,d;

		cout << "\t�������: ";
		cin >> b;
		cout << "\t���: ";
		cin >> a;
		cout << "\t��������: ";
		cin >> c;
		cout << "\t������: ";
		cin >> d;

		int maxID = 0;
		list <Student> :: iterator it; 
		for (it = Students.begin(); it != Students.end(); it++) 
		if((*it).id >=  maxID) 
			maxID = (*it).id + 1;
				
		Students.push_back(Student(maxID, a, b, c, d));
		Save();
	}
	public: void Save()
	{ 
		ofstream fout ("bd.txt");

		list <Student> :: iterator it; 
		for (it = Students.begin(); it != Students.end(); it++) 
			fout << (*it).id 
				<< " " << (*it).frstName 
				<< " " << (*it).lastName 
				<< " " << (*it).prevName 
				<< " " << (*it).group 
				<< "\n";  
		
		fout.close();
	}

	public: void Remove()
	{ 
		int id;
		cout << "\t������� id ��������: ";
		cin >> id;
		Student rem(id, "", "", "", "");
		Students.remove(rem);
	}

	public: void Load()
	{ 
		ifstream fin ("bd.txt");
		while (true) 
		{	
			string b, c, d, e;
			int a;
			fin >> a >> b >> c >> d >> e;
			if (fin.eof()) break;
			Students.push_back(Student(a, b, c, d, e));
		}
		fin.close();
	}

	public: void View()
	{ 
		list <Student> :: iterator it; 
		int counter = 0;
		for (it = Students.begin(); it != Students.end(); it++) 
		{
			(*it).View();
			counter++;
		}
		if(counter == 0)
			cout << "\t������ ����." << endl;
	}
};

class Menu 
{
	public: void Output ()
	{
		cout << "�������� ����� ����: " << endl << endl
			<< "1) �������� ��������."<< endl
			<< "2) ������� ��������."<< endl
			<< "3) ������� ������ ���������."<< endl << endl;
	}
	public: char Input ()
	{
		char number;

		cout << "����� ����> ";
		cin >> number;

		return number;
	}
};

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Menu menu;
	Sanatroty sanatroty;

	menu.Output();

	while(true)
	{
		char number = menu.Input();
		switch(number)
		{
			case '1': 
				sanatroty.Add();
				break;
			case '2': 
				sanatroty.Remove();
				break;
			case '3': 
				sanatroty.View();
				break;
			default: 
				cout << "������ �����." << endl;
				break;
		}

	}
}

