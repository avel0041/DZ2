#include "Student.h"

Student::Student()
{
	age = FizOzenka = MathOzenka = 0;
	name = nullptr;
}

Student::Student(string n, int a, int MO, int FO)
{
	age = a;
	FizOzenka = FO;
	MathOzenka = MO;
	name = n;
}

void Student::set_age(int a)
{
	age = a;
}
void Student::set_FizOzenka(int FO)
{
	FizOzenka = FO;
}
void Student::set_MathOzenka(int MO)
{
	MathOzenka = MO;
}
void Student::set_name(string n)
{
	name = n;
}


int Student::get_age()
{
	return age;
}
int Student::get_FizOzenka()
{
	return FizOzenka;
}
int Student::get_MathOzenka()
{
	return MathOzenka;
}
string Student::get_name()
{
	return name;
}


std::ostream& operator<<(std::ostream& out, Student& H)
{
	out << "Student:" << endl << 
		"name = " << H.get_name() << ";" << endl <<
		"age = " << H.get_age() << ";" << endl << 
		"Ocenka Math = " << H.get_MathOzenka() << "," << endl <<
		"Ocenka Phys = " << H.get_FizOzenka() << "." << endl;
	return out;
}

Student::~Student(){

}