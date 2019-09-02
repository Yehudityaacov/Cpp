#define _CRT_SECUERE_NO_WARNINGS
#ifndef _MANAGER_M
#define _MANAGER_M
#include <iostream>
#include <string> 
#include "Worker.h"
#include "Person.h"
using namespace std;
class Person;
class Worker;
class Manager : public Worker
{
public:
	void Setdetails(Manager&);//input details  of the Manager from the user
	int GetID(){ return this->i_d; }//returning the id of the Manager
	void PrintDetails();//prints the Manager details
	bool CheakExllent();//checks if the Manager is Exllent
	double GetSalary();// returns the Manager salary
	Manager();//default construcor
	~Manager();//distructor
private:

};
#endif

