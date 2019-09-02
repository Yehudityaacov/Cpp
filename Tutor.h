#define _CRT_SECUERE_NO_WARNINGS
#ifndef _TUOTR_T
#define _TUOTR_T
#include <iostream>
#include <string> 
using namespace std;
#include "Teacher.h"
#include "Class.h"
class Teacher;
class Class;
class Tutor :public Teacher
{
public:
	int GetClassNumb();//gets the class number of the tutor
	char GetNameLayer(); //gets the layer name of the tutor
	void addClass(Class *pclass);//add class to the tutor
	/*Tuotr* GetTutor(){ return this; }*/
	//int GetID(){ return this->i_d; }//returning the id of the Tutor
	void PrintDetails();//prints the tutor details
	void PrintDetailsPupil();//prints the details of the pupils in the class
	bool CheakExllent();//checks if the teacher is Exllent
	double GetSalary();// returns the Tutor salary
	void Setdetails(Tutor&);//input details  of the Tutor from the user
	Tutor( Tutor& pTuotr);//initialization copy c'tor
	Tutor();//default construcor
	~Tutor();//distructor
	//------MAMABERS----//
private:		

	Class* pClass;

};
#endif

