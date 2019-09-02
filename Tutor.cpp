#include "Tutor.h"
Tutor::Tutor() :Teacher()//initialization defult  c'tor
{
	pClass = NULL;
}
Tutor::Tutor(Tutor& pTuotr) : Teacher(pTuotr)//initialization copy c'tor
{
	i_d = pTuotr.i_d;
	F_name = pTuotr.F_name;
	F_name = pTuotr.L_name;
	this->Period = pTuotr.Period;
	this->AmountProfession = pTuotr.AmountProfession;
	if (pTuotr.AmountProfession != 0)
	{
		this->NameProfession = new string[pTuotr.AmountProfession];
		for (int i = 0; i < pTuotr.AmountProfession; i++)
		{
			NameProfession[i] = pTuotr.NameProfession[i];
		}
	}
	this->pClass = new Class;
	this->pClass = pTuotr.pClass;
}
Tutor::~Tutor()//distructor
{
	if (pClass != NULL)
		delete[] pClass;
}
double Tutor::GetSalary()//returns the Tutor salary
{
	return (double)(Teacher::GetSalary() + 1000);
}
bool Tutor::CheakExllent()//checks if the Tutor is Exllent
{
	int count=0;
	for (int i = 0; i < pClass->GetAmountPupil(); i++)
	{
		Pupil* ptr = pClass->GetPupilByIndex(i);
		if (ptr->CheakExllent() == true)
			count++;
	}
	if (count>(pClass->GetAmountPupil() / 2))
		return true;
	return false;
}
void Tutor::PrintDetailsPupil()//prints the details of the pupils in the class
{
	cout << "the Pupils in this class Details" << endl;
	for (int i = 0; i <pClass->GetAmountPupil(); i++)
	{
		cout << "the Pupils in this class are: " << endl << i + 1 << pClass->GetPupilByIndex(i)->GetFirstName();
cout << " " << pClass->GetPupilByIndex(i)->GetLastName() << endl;
		cout << "The Id of the pupil is: " << pClass->GetPupilByIndex(i)->getID() << endl;
		if (pClass->GetPupilByIndex(i)->CheakExllent() == true)
			cout << "An EXELLANT Pupil: " << pClass->GetPupilByIndex(i)->GetFirstName()<<endl;
	}
}
void Tutor::PrintDetails()// prints the tutor details
{
	cout << "----------TUTOR----------" << endl;
	cout << "the Tutor Details" << endl;
	Worker::PrintDetails();
	this->PrintProfession();
	cout << " the tutor of the class: " << pClass->GetNameLayer() << "\\" << pClass->GetNumberClass() << endl;
	PrintDetailsPupil();
}
void Tutor::Setdetails(Tutor&Tuotrdet)//prints the Tutor details
{
	char tempPLayarName;
	int  tempClassNumb;
	Tuotrdet.pClass = new Class;
	cout << "Please enter name: " << endl;
	cin >> Tuotrdet.F_name;
	cout << "Please enter last name: " << endl;
	cin >> Tuotrdet.L_name;
	cout << "Please enter ID: " << endl;
	cin >> Tuotrdet.i_d;
	cout << "Please enter the period work in school: " << endl;
	cin >> Tuotrdet.Period;
	cout << "Please enter the Amount of Professions he has: " << endl;
	cin >> Tuotrdet.AmountProfession;
	Tuotrdet.NameProfession = new string[Tuotrdet.AmountProfession];
	for (int i = 0; i < Tuotrdet.AmountProfession; i++)
	{
		cout << "Please enter name to the " << i + 1 << " profession: ";
		_flushall();
		cin >> Tuotrdet.NameProfession[i];
	}
	cout << "Please enter the layer (a-f): " << endl;
	cin >> tempPLayarName;
	while (!(tempPLayarName >= 'a'&&tempPLayarName <= 'f'))
	{
		cout << " the layer is not exist" << endl;
		cout << "Please enter the layer: " << endl;
		cin >> tempPLayarName;
		continue;
	}
	Tuotrdet.pClass->setNameLayer(tempPLayarName);
	cout << "Please enter class number (1-3):" << endl;
	cin >> tempClassNumb;
	while (!(tempClassNumb >= 1 && tempClassNumb <= 3))
	{
		cout << " the class is not exist" << endl;
		cout << "Please enter class number: " << endl;
		cin >> tempClassNumb;
		continue;
	}
	Tuotrdet.pClass->setNumberClass(tempClassNumb);
}
void Tutor::addClass(Class *pclass)// add class to the tutor
{
	this->pClass = pclass;
}
int Tutor::GetClassNumb()//gets the class number of the tutor
{
	return pClass->GetNumberClass();
}
char Tutor::GetNameLayer()//gets the layer name of the tutor
{
	return pClass->GetNameLayer();
}