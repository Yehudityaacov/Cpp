#define _CRT_SECUERE_NO_WARNINGS
#ifndef _PERSON_P
#define _PERSON_P
#include <iostream>
#include <string> 
using namespace std;
class Person
{
public:
	Person();//default construcor
	Person(string, string, int);//nond default construcor
	virtual~Person();// virtual distructor
	virtual void PrintDetails(); // printing the details of the person
	virtual bool CheakExllent() = 0;//pur Virtual function that checks if the person is Exllent
	int Getid(){ return this->i_d; } // returning the id of the person
	//---------MAMBERS-----//
protected:
	string F_name;
	string L_name;
	int i_d;
};
#endif