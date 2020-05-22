#ifndef Group_H
#define Group_H

#include "Student.h"
#pragma once
#include <string>
#include <vector>

class Group
{
	std::string Name_Group;
	int StudentsNum;
	double AverageBall;
	double AverageBallPhys;
	double AverageBallMath;
	int Countof5;
	int Countof2;
	vector<int> OzenkiPhys;
	vector<int> OzenkiMath;
	std::vector<Student> Students;
public:
	Group();
	Group(std::string Name, std::vector<Student> stud);
	~Group();
	std::string get_NameGroup();
	int get_StudentsNum();
	double get_AverageBall();
	double get_AverageBallPhys();
	double get_AverageBallMath();
	int get_Countof5();
	int get_Countof2();
	void print_5();
	void print_2();
	void set_NameGroup(std::string NameGr);
	void update();
	void add(Student& stud);
	void del();
	void print_Students();
	friend std::ostream& operator<<(std::ostream& out, Group& gr);
	Group operator+(Student& Stud);
};

#endif