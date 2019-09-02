#define _CRT_SECUERE_NO_WARNINGS
#ifndef _SCOOL_S
#define _SCOOL_S
#include <iostream>
#include <string> 
#include <typeinfo>
#include "Layer.h"
#include "Person.h"
#include "Pupil.h"
#include "Teacher.h"
#include "Tutor.h"
#include "Secretary.h"
#include "Manager.h"
using namespace std;
class Pupil;
class Teacher;
class Tutor;
class Manager;
class Secretary;
class Person;
class Layer;
class School
{
public:
	void Menu();//School Menegemant Menu
	School();//Default constructor
	~School();//distructor
	//------MAMABERS----//
private:
	Layer**pLayer;
	int AmountAllaLayer;
	Person**Allpersons;
	int AmountAllPerson;
	bool ManagerExsit;

	void AddPupil();//CASE 1 add pupil to school
	void AddTeacher();//CASE 2 add Teacher to school
	void AddTutor();//CASE 3 add Tutor to school
	void AddManager();//CASE 4 add Manager to school
	void AddSecretary();//CASE 5 add Secretary to school
	void PrintAllPersonInSchool();//CASE 6 printing All the Persons In School
	void PrintOutstandingPepole();//CASE 7 Printing Outstanding Pepole in school
	void printTutorClass();//CASE 8 print tutor's class
	void printHighSalaryWorker();//CASE 9 print details of the worker with biggest salary
};
#endif
