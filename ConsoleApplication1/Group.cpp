#include "Group.h"

Group::Group()
{
	Name_Group = nullptr;
	StudentsNum = Countof2 = Countof5 = 0;
	AverageBall = AverageBallMath = AverageBallPhys = 0;
}

Group::Group(std::string Name, std::vector<Student> stud)
{
	for (int i = 0; i < stud.size(); i++) {
		add(stud[i]);
	}
	Name_Group = Name;
	StudentsNum = 0;
}

Group::~Group()
{

}

void Group::set_NameGroup(std::string NameGr)
{
	Name_Group = NameGr;
}



std::string Group::get_NameGroup()
{
	return Name_Group;
}
int Group::get_StudentsNum()
{
	return Students.size();
}
double Group::get_AverageBall()
{
	return AverageBall;
}
double Group::get_AverageBallPhys()
{
	return AverageBallPhys;
}
double Group::get_AverageBallMath()
{
	return AverageBallMath;
}
int Group::get_Countof5()
{
	return Countof5;
}
int Group::get_Countof2()
{
	return Countof2;
}

void Group::update() {
	AverageBall = AverageBallMath = AverageBallPhys = 0;
	for (int i = 0; i < OzenkiPhys.size(); i++) {
		AverageBallPhys += OzenkiPhys[i];
		AverageBall += OzenkiPhys[i];
	}
	for (int i = 0; i < OzenkiMath.size(); i++) {
		AverageBallMath += OzenkiMath[i];
		AverageBall += OzenkiMath[i];
	}
	AverageBallPhys /= (1.*OzenkiPhys.size());
	AverageBallMath /= (1.*OzenkiMath.size());
	AverageBall /= (1.*(OzenkiMath.size() + OzenkiPhys.size()));
}


void Group::add(Student& stud)
{
	Students.push_back(stud);
	StudentsNum += 1;
	OzenkiMath.push_back(stud.get_MathOzenka());
	OzenkiPhys.push_back(stud.get_FizOzenka());
	if (stud.get_MathOzenka() == 5 && stud.get_FizOzenka() == 5) {
		Countof5 += 1;
	}
	if (stud.get_MathOzenka() == 2 && stud.get_FizOzenka() == 2) {
		Countof2 += 1;
	}
	update();
}

void Group::del()
{
	if (Students.empty()) {
		std::cout << "It's empty";
		return;
	}
	Students.pop_back();
	StudentsNum -= 1;
	OzenkiMath.pop_back();
	OzenkiPhys.pop_back();
	update();
}

void Group::print_Students()
{
	for (auto it = Students.begin(); it != Students.end(); it++) {
		std::cout << *it;
		std::cout << std::endl;
	}
}


void Group::print_5()
{
	for (int i = 0; i < Students.size(); i++) {
		if (Students[i].get_MathOzenka() == 5 && Students[i].get_FizOzenka() == 5) cout << Students[i];
	}
}

void Group::print_2()
{
	for (int i = 0; i < Students.size(); i++) {
		if (Students[i].get_MathOzenka() == 2 && Students[i].get_FizOzenka() == 2)cout << Students[i];
	}
}

Group Group::operator+(Student& stud)
{
	add(stud);
	return *this;
}

std::ostream& operator<<(std::ostream& out, Group& Gr)
{
	out << "Group:" <<
		"name = " << Gr.get_NameGroup() << ";" << endl <<
		"number of Students = " << Gr.get_StudentsNum() << ";" << endl <<
		"Average ball = " << Gr.get_AverageBall() << ";" << endl <<
		"Average ball (Phys) = " << Gr.get_AverageBallPhys() << ";" << endl <<
		"Average ball (Math) = " << Gr.get_AverageBallMath() << ";" << endl <<
		"Number of 5 = " << Gr.get_Countof5() << ";" << endl <<
		"Nice = " << endl;
	Gr.print_5();
	out << endl << "Number of 2 = " << Gr.get_Countof2() << ";" << endl 
		<< "Bad = " << endl;
	Gr.print_2();
	out << std::endl;
	return out;
}
