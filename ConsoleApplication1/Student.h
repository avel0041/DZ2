#ifndef Student_H
#define Student_H
#pragma once

#include <iostream>
#include <string>
using namespace std;
class Student
{
	int age;
	string name;
	int FizOzenka;
	int MathOzenka;
public:
	Student();
	Student(string n, int a, int MO, int FO);
	~Student();
	int get_age();
	int get_FizOzenka();
	int get_MathOzenka();
	string get_name();
	void set_age(int a);
	void set_MathOzenka(int MO);
	void set_FizOzenka(int FO);
	void set_name(string n);
	friend std::ostream& operator<<(std::ostream& output, Student& H);
};

#endif;