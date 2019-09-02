#include "Manager.h"
Manager::Manager() :Worker()//defult  c'tor
{

}
void Manager::Setdetails(Manager&manager)//gat the details  of the Manager from the user
{
	cout << "Please enter name:" << endl;
	cin >> manager.F_name;
	cout << "Please enter last name:" << endl;
	cin >> manager.L_name;
	cout << "Please enter ID :" << endl;
	cin >> manager.i_d;
	cout << "Please enter the Period Manager in School:" << endl;
	cin >> manager.Period;

}
Manager::~Manager()//distructor
{

}
double Manager::GetSalary()//returns the manager salary
{
	int y = Period;
	return (double)(basis * 2 + 500 * y);
}
bool Manager::CheakExllent()//checks if the Manager is Exllent
{
	if (3 < Period)
		return true;
	return false;
}
void Manager::PrintDetails()//prints the Manager details
{
	cout << "----------MANAGER----------" << endl;
	cout << "the Manager Details: " << endl;
	Worker::PrintDetails();
}