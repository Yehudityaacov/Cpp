#define _CRT_SECUERE_NO_WARNINGS
#ifndef _WORKER_R
#define _WORKER_R
#include <iostream>
#include <string> 
#include "Person.h"
#define basis 5000
using namespace std;
class Person;
class Worker :public Person
{
public:
	virtual void PrintDetails();//prints the worker details
	virtual double GetSalary() = 0;//pur virtual  worker salary
	Worker(Worker&);//copy c'tor 
	Worker();// defult  c'tor
	virtual~Worker();//virtual distrctor
	//------MAMABERS----//
protected:
	int Period;

};
#endif

