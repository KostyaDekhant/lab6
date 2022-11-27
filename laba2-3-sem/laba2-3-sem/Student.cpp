#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 100
#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Student.h"
#include "Function.h"
#include <fstream>


int Student::count_stud = 0;

Student::Student()
{
	Human initHuman;
	this->setFIO(initHuman.getFIO().getFirst(), initHuman.getFIO().getMid(), initHuman.getFIO().getLast());
	this->setAge(initHuman.getAge());
	this->scholarship = 10000;
	this->group = "ПИ11";
	count_stud++;
}
Student::Student(int scholarship)
{
	Human initHuman;
	this->setFIO(initHuman.getFIO().getFirst(), initHuman.getFIO().getMid(), initHuman.getFIO().getLast());
	this->setPD("1203","344894");
	this->setAge(initHuman.getAge());
	this->scholarship = 10000;
	this->group = "ПИ11";
	count_stud++;
}
Student::Student(class Human human, int scholarship, string group)
{
	this->setFIO(human.getFIO().getFirst(), human.getFIO().getMid(), human.getFIO().getLast());
	this->setPD("1203", "344894");
	this->setAge(human.getAge());
	this->scholarship = scholarship;
	this->group = group;
	count_stud++;
}
Student::~Student()
{

}

int Student::getAge(int i)
{
	return this->Human::getAge() + i;
}


void Student::FileRead(Student* stud)
{	
	ifstream file;
	file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	try
	{
		file.open("Students.txt");
		file >> count_stud;
		for (int i = 0; i < count_stud; i++)
		{
			string first, mid, last, ser, num, group;
			int age, sholar;
			file >> last >> first >> mid;
			file >> age;
			file >> num >> ser;
			file >> sholar;
			file >> group;
			stud[i].setFIO(first, mid, last);
			stud[i].setAge(age);
			stud[i].setPD(num, ser);
			stud[i].scholarship = sholar;
			stud[i].group = group;
		}
		file.close();
	}
	catch (std::ifstream::failure e) {
		cout << "Ошибка при чтении или открытии файла!" << endl;
		_getch();
	}
}

void Student::FileWrite(Student *stud)
{
	ofstream file;
	file.exceptions(std::ofstream::failbit | std::ofstream::badbit);
	try
	{
		file.open("Students.txt");
		file << count_stud << endl;
		for (int i = 0; i < count_stud; i++)
		{
			file << stud[i].getFIO().getLast() << endl;
			file << stud[i].getFIO().getFirst() << endl;
			file << stud[i].getFIO().getMid() << endl;
			file << stud[i].getAge(0) << endl;
			file << stud[i].getPD().getNum() << endl;
			file << stud[i].getPD().getSer() << endl;
			file << stud[i].scholarship << endl;
			file << stud[i].group << endl;
		}
		file.close();
	}
	catch (std::ofstream::failure e) {
		cout << "Ошибка при сохранении файла!"<< endl;
		_getch();
	}
}

Student Student::operator + (Student stud)
{
	return Student(this->scholarship + stud.scholarship);
}

Student& Student::operator ++ ()
{
	this->setAge((this->getAge(0)) + 1);
	return *this;
}

Student Student::operator ++ (int)
{
	Student stud = *this;
	++* this;
	return stud;
}

void Student::operator=(Human human)
{
	this->setFIO(human.getFIO().getFirst(), human.getFIO().getMid(), human.getFIO().getLast());
	this->setPD(human.getPD().getNum(), human.getPD().getSer());
	this->setAge(human.getAge());
}


void InputStud(Student& stud)
{
	system("cls");
	string first, mid, last, num, ser;
	cout << "Введите фамилию студента: ";
	last = write_str(29);
	cout << "Введите имя студента: ";
	first = write_str(29);
	cout << "Введите отчество студента: ";
	mid = write_str(29);
	stud.setFIO(first, mid, last);
	cout << "Введите возраст: ";
	stud.setAge(write_num(125));
	cout << "Введите номер паспорта: ";
	num = write_pd(4);
	cout << "Введите серию паспорта: ";
	ser = write_pd(6);
	stud.setPD(num, ser);
	cout << "Введите размер стипендии: ";
	stud.scholarship = write_num(100000);
	cout << "Введите номер группы: ";
	cin >> stud.group;
	stud.count_stud++;
}
void Student::OutputStud(int i)
{
	cout << to_string(i + 1) + "-й человек: " << endl;
	cout << "---------------------------------" << endl;
	cout << "ФИО: " + this->getFIO().getLast() + " " + this->getFIO().getFirst() + " " + this->getFIO().getMid() << endl;
	cout << "Паспортные данные: " + this->getPD().getNum() + " " + this->getPD().getSer() << endl;
	cout << "Возраст: " + to_string(this->getAge(0)) << endl;
	cout << "Студент группы: " + this->group << endl;
	cout << "Стипендия: " + to_string(this->scholarship) << endl;
	cout << "---------------------------------\n\n" << endl;
}

void Student::ChangeInfo()
{
	int inp;
	inp = write_num(6);
	if (inp == 6)
		return;
	else if (inp == 1)
	{
		string first, mid, last;
		cout << "Введите фамилию студента: ";
		last = write_str(29);
		cout << "Введите имя студента: ";
		first = write_str(29);
		cout << "Введите отчество студента: ";
		mid = write_str(29);
		this->setFIO(first, mid, last);
	}
	else if (inp == 2)
	{
		string num, ser;
		cout << "Введите номер паспорта: ";
		num = write_pd(4);
		cout << "Введите серию паспорта: ";
		ser = write_pd(6);
		this->setPD(num, ser);
	}
	else if (inp == 3)
	{
		cout << "Введите возраст: ";
		this->setAge(write_num(125));
	}
	else if (inp == 4)
	{
		cout << "Введите номер группы: ";
		cin >> this->group;
	}
	else if (inp == 5)
	{
		cout << "Введите размер стипендии: ";
		this->scholarship = write_num(100000);
	}
}

void Student::stud_analysis(int* stud_sum_age, int* stud_sum_scholarship,
				   int *count_students, int* max_scholarship, int* min_scholarship)
{
	system("cls");
	if (!*count_students)
	{
		*max_scholarship = this->scholarship;
		*min_scholarship = this->scholarship;
	}
	else if (this->scholarship > *max_scholarship)
	{
		*max_scholarship = this->scholarship;
	}
	else if (this->scholarship < *min_scholarship)
	{
		*min_scholarship = this->scholarship;
	}
	*stud_sum_scholarship += this->scholarship;
	*count_students += 1;
	*stud_sum_age += this->getAge(0);
}

int Student::GetCount()
{
	return count_stud;
}

void Student::SetCount(int count)
{
	count_stud = count;
}
