#include "Class.h"
Class::Class()//initialization defult  c'tor
{
	this->AmountPupil = 0;
	this->NameLayer = '0';
	this->NumberClass = 0;
	this->PTuotr =NULL;
	this->AllPupil =NULL;
}
Class::Class(Class&cls)//copy ctor
{
	this->NameLayer = cls.NameLayer;
	this->NumberClass = cls.NumberClass;
	this->AmountPupil = cls.AmountPupil;
	if (cls.PTuotr != NULL)
	{
		this->PTuotr = new Tutor;
		this->PTuotr = cls.PTuotr;
	}
	if (AmountPupil != 0)
	{
		this->AllPupil = new Pupil*[AmountPupil];
		for (int i = 0; i <cls.AmountPupil; i++)
		{
			this->AllPupil[i] = cls.AllPupil[i];
		}
	}
}
Class::Class(int numClass, char N_Layer)// non defult  c'tor
{
	
	this->AmountPupil = 0;
	this->NameLayer = N_Layer;
	this->NumberClass = numClass;
	PTuotr = NULL;
	AllPupil = NULL;
}
Class::~Class()//distructor
{
	if (PTuotr != NULL)
		delete[] PTuotr;
	if (AllPupil != NULL)
		delete[] AllPupil;


}
void Class::AddPupil(Pupil*pPupil)// add pupil to the class
{
		Pupil** tampAllPupil = new Pupil*[AmountPupil + 1];

		for (int i = 0; i <AmountPupil; i++)
		{
			tampAllPupil[i] = this->AllPupil[i];
		}
		tampAllPupil[AmountPupil] = pPupil;
		if (AllPupil != NULL)//free memory allocated
			delete[] AllPupil;
		this->AllPupil = new Pupil*[AmountPupil + 1];
		AmountPupil++;
		for (int i = 0; i < AmountPupil; i++)
		{
			AllPupil[i] = tampAllPupil[i];
		}
		if (tampAllPupil != NULL)
			delete[]tampAllPupil;//free memory allocated
	cout<< "the Pupil add to the class !" << endl;
}
Pupil* Class::GetPupilByIndex(int index) //recieve a number and returns pointer to the pupil  in the array list of pupils by the number(index of the pupil in the list)
{
	return this->AllPupil[index];
}
bool Class::AddTutor(Tutor*tuotr)//adding tutor to the class
{

	if (PTuotr == NULL)
	{
		this->PTuotr = tuotr;
		cout << "The tutor add to the class: " << NameLayer << "\\" << NumberClass << " !" << endl;
		return true;
	}
	else
		cout << "There is alredy a tutor to the class: " << NameLayer << "\\" << NumberClass << " !" << endl;
	return false;
}

