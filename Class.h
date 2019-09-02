#define _CRT_SECUERE_NO_WARNINGS
#ifndef _CLASS_C
#define _CLASS_C
#include <iostream>
#include <string> 
#include"Pupil.h"
#include "Tutor.h"
using namespace std;
class Pupil;
class Tutor;
class Class
{
public:
	bool AddTutor(Tutor* tuotr);//foradding thetutor to the class
	Pupil*GetPupilByIndex(int);//get the pupil in the class by index
	void setNameLayer(char Name) { this->NameLayer = Name; }// set the name of the layer of the class
	void setNumberClass(int Number){ this->NumberClass = Number; }// set the class number
	int GetNumberClass(){ return NumberClass; }// gets the number of the class
	char GetNameLayer(){ return NameLayer; }// gets the name of the layer
	int GetAmountPupil(){ return AmountPupil; }//return the amount of pupil in the class
	void AddPupil(Pupil* pPupil);//add new Pupil
	Class(int, char);//non defult c'tor
	Class(Class&);//copy ctor
	Class();//defult c'tor
	~Class();//destractor
	//-----------ALL MAMBERS------//
private:
	Tutor* PTuotr;
	Pupil**AllPupil;
	int AmountPupil;
	char NameLayer;
	int NumberClass;
};
#endif

