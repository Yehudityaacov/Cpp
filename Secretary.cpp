#include"Secretary.h"
Secretary::Secretary()//defult  c'tor
{
	AmountChild_Sec = 0;
}
Secretary::~Secretary()//distructor
{
}
void Secretary::PrintDetails()//prints the details of the secretary
{ 
	cout << "----------SECRETARY----------" << endl;
	Worker::PrintDetails();

}
bool Secretary::CheakExllent()// checks if the Secretary is Exllent
{
	if (Period < 10)
		return true;
	return false;
}
double Secretary::GetSalary()//returns the Secretary salary
{
	return (double)(basis + AmountChild_Sec * 200);
}
void Secretary::Setdetails(Secretary& secretary)//gat the details  of the Secretary from the user
{
	cout << "Please enter name: " << endl;
	cin >> secretary.F_name;
	cout << "Please enter last name: " << endl;
	cin >> secretary.L_name;
	cout << "Please enter ID: " << endl;
	cin >> secretary.i_d;
	cout << "Please enter the Period Secretary in School: " << endl;
	cin >> secretary.Period;
	cout << "Please enter the number of the Secretary children: " << endl;
	cin >> secretary.AmountChild_Sec;

}
