#define _CRT_SECUERE_NO_WARNINGS
#ifndef _TEACHER_T
#define _TEACHER_T
#include <iostream>
#include <string> 
#include "Worker.h"
using namespace std;
class Worker;
class Teacher : public Worker
{
public:
	void Setdetails(Teacher&);//input details of the teacher from the user
	int GetID(){ return this->i_d; }//returning the id of the teacher
	void PrintProfession();//prints the teacher's professions
	void PrintDetails();//prints the teacher details
	bool CheakExllent();//checks if the teacher is Exllent
	double GetSalary();//returns the teacher salary
	Teacher(Teacher&);//copy c'tor 
	Teacher();//defult C'tur
	~Teacher();//distructor
	//------MAMABERS----//
protected:
	string* NameProfession;
	int AmountProfession;

};
#endif
