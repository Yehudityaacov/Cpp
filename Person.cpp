#include "Person.h"
Person::Person()//initialization defult  c'tor
{ 
	F_name = " ";
	L_name = " ";
	i_d= 0;

}
Person::Person(string fname, string Lname, int id) :F_name(fname), L_name(Lname), i_d(id)
{
}
Person::~Person()
{
	cout << "person D'tor" << endl;
}
void Person::PrintDetails()
{
	cout << "FIRST NAME: "<<F_name<< endl; 
	cout << "LAST NAME: "<<L_name<<endl;
	cout << "ID: " << i_d << endl;
}
