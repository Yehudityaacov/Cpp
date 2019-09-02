#include "Pupil.h"
Pupil::Pupil() :Person()//initialization defult  c'tor
{
	
	this->AmountGrades = 0;
	this->Allgrades = new int[this->AmountGrades];
	this->LayarName = ' ';
	this->ClassNumb = 0;
}
Pupil::~Pupil()//distructor
{
	if (this->Allgrades != NULL)
	{
		delete[] Allgrades;
	}
}
Pupil::Pupil(Pupil&Pupil) :Person(Pupil)//copy construcor
{ 

	this->AmountGrades = Pupil.AmountGrades;
	this->Allgrades = new int[this->AmountGrades];
		for (int i = 0; i < AmountGrades; i++)
		{
			this->Allgrades[i] = Pupil.Allgrades[i];
		}
		this->LayarName = Pupil.LayarName;
		this->ClassNumb = Pupil.ClassNumb;
}
void Pupil::PrintDetails()// prints the Pupil details
{
	cout << "----------PUPIL----------" << endl;
	Person::PrintDetails();
	cout << "The pupil layer is: " << this->LayarName << endl;
	cout << "The pupil clas number is: " << this->ClassNumb << endl;
	cout << "The pupil of the grades are :" << endl;
	for (int i = 0; i <AmountGrades; i++)
	{
		cout << "the grade in " << i + 1 << " "<<"is: " << endl;
		cout << Allgrades[i] << endl;
	}
	cout << "the averag is :" << endl;
	cout << GatAvg() << endl;
}
bool Pupil::CheakExllent()// checks if the pupil is Exllent
{
	int count = 0;
	for (int i = 0; i < AmountGrades; i++)
	{
		if (Allgrades[i]>65)
			count++;
	}
	if (count == AmountGrades && this->GatAvg() > 85)
			return true;
	return false;
}
float Pupil::GatAvg()const// calculate the average grade of pupil
{
	int sum = 0, count = 0;
	for (int i = 0; i <AmountGrades; i++)
	{
		sum += this->Allgrades[i];
	}
	float avg = sum / (float)AmountGrades;
	return avg;
}
void Pupil::Setdetails(Pupil &Pupildet)//gat the details  of the pupil from the user
{
	cout << "Please enter name :" << endl;
	cin >> Pupildet.F_name;
	cout << "Please enter last name :" << endl;
	cin >> Pupildet.L_name;
	_flushall();
	cout << "Please enter ID :" << endl;
	cin >> Pupildet.i_d;
	while (!(cin))//chack if the user input contin are right
	{
		cin.clear();//clearers all error invalid input
		cin.ignore(numeric_limits<streamsize>::max(), '\n');//ignore all the invalid input
		cout << "rong input, please try again " << endl;
		fflush(stdin);
		cin >> Pupildet.i_d;
	}
	cout << "Please enter the layer: " << endl;
	cin >> Pupildet.LayarName;
	while (!(cin))//chack if the user input contin are right
	{
		cin.clear();//clearers all error invalid input
		cin.ignore(numeric_limits<streamsize>::max(), '\n');//ignore all the invalid input
		cout << "rong input, please try again " << endl;
		fflush(stdin);
		cin >> Pupildet.LayarName;
	}
	while (!(Pupildet.LayarName >= 'a'&& Pupildet.LayarName <= 'f'))
	{
		if (!(Pupildet.LayarName >= 'a'&&Pupildet.LayarName <= 'f'))
		{
			cout << " the layer is not exist" << endl;
			cout << "Please enter the layer: " << endl;
			cin >> Pupildet.LayarName;
			continue;
		}
	}
	cout << "Please enter class number: " << endl;
	cin >> Pupildet.ClassNumb;
	while (!(Pupildet.ClassNumb >= 1 && Pupildet.ClassNumb <= 3))
	{
		cout << " the class is not exist" << endl;
		cout << "Please enter class number: " << endl;
		cin >> Pupildet.ClassNumb;
		continue;
	}
	Pupildet.AmountGrades = Pupildet.LayarName - 92;
	Allgrades = new int[Pupildet.AmountGrades];
	cout << "Please enter the grades: " << endl;
	for (int i = 0; i <Pupildet.AmountGrades; i++)
	{
		cout << "Please enter grade to the course number" << i + 1 << ": ";
		cin >> Pupildet.Allgrades[i];
	}
}
