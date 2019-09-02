#define _CRT_SECUERE_NO_WARNINGS
#ifndef _SECRETARY_S
#define _SECRETARY_S
#include <iostream>
#include <string> 
#include "Worker.h"
using namespace std;
class Worker;
class Secretary :public Worker
{
public:
	void Setdetails(Secretary& secretary);//gat the details  of the Secretary from the user
	int GetID(){ return this->i_d; }//returning the id of the Secretary
	void PrintDetails();//prints the details of the secretary
	bool CheakExllent();// checks if the Secretary is Exllent
	double GetSalary();//returns the Secretary salary
	Secretary();//default construcor
	~Secretary();//distructor
private:
	unsigned int AmountChild_Sec;
};
#endif
