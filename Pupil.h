#define _CRT_SECUERE_NO_WARNINGS
#ifndef _PUPIL_P
#define _PUPIL_P
#include <iostream>
#include <string> 
#include <iomanip>
#include "Person.h"
using namespace std;
class Person;
class Pupil : public Person
{
public:
	void Setdetails(Pupil &Pupildet);//input details  of the pupil from the user
	char Getlayername(){ return this->LayarName; }//returning the name of the layer of the pupil
	int GetclassNumber(){ return this->ClassNumb; }//returning the number of the class of the pupil
	int getID(){ return this->i_d; }//returning the id of the pupil
	string GetFirstName(){return this->F_name;}//returning first name
	string GetLastName(){ return this->L_name; }//returning last name
	void PrintDetails();// prints the student details
	bool CheakExllent();// checks if the pupil is Exllent
	float GatAvg()const;// calculate the average grade of pupil
	Pupil(Pupil&Pupil);//copy c'tor construcor
	Pupil();//default construcor
	~Pupil();//distructor
	//------MAMABERS----//
private:
	int* Allgrades;
	int AmountGrades;
	char LayarName;
	int ClassNumb;
};
#endif
