#include"Teacher.h"
Teacher::Teacher() :Worker()//defult C'tur
{
	this->AmountProfession = 0;
	this->NameProfession = NULL;

}
Teacher::Teacher(Teacher&teacher) :Worker(teacher)//copy C'tur
{
	this->F_name = teacher.F_name;
	this->L_name = teacher.L_name;
	this->i_d = teacher.i_d;
	this->AmountProfession = teacher.AmountProfession;
	this->Period = teacher.Period;
	this->NameProfession = new string[this->AmountProfession];
	if( teacher.AmountProfession != 0)
	{
		for (int i = 0; i < AmountProfession; i++)
		{
			this->NameProfession[i] = teacher.NameProfession[i];
		}
	}
	
}
Teacher::~Teacher()//distructor
{
	cout << "Teacher D'tor" << endl;
	if (this->NameProfession != NULL)
		delete[]NameProfession;

}
double Teacher::GetSalary()
{
	int x =this-> AmountProfession;
	int y = this->Period;
	return basis*(1 + x / 10.) + 300 * y;
}
bool Teacher::CheakExllent()//checks if the teacher is Exllent
{
	if (this->AmountProfession>5)
		return true;
	return false;
}
void Teacher::PrintProfession()//prints the teacher's professions
{
	if (this->AmountProfession != 0)
	{
		cout << "The worker teach " << this->AmountProfession << " professions" << endl;
		for (int i = 0; i < this->AmountProfession; i++)
		{
			cout << "The " << i + 1 << " profession is: " << this->NameProfession[i] << endl;
		}
	}
}
void Teacher::PrintDetails()//prints the teacher details
{
	cout << "----------TEACHER----------" << endl;
	Worker::PrintDetails();
	cout << "his Profession is: " << endl;
	this->PrintProfession();
}
void Teacher::Setdetails(Teacher &teacher)//input details of the teacher from the user
{
	cout << "Please enter name: " << endl;
	cin >> teacher.F_name;
	cout << "Please enter last name: " << endl;
	cin >> teacher.L_name;
	cout << "Please enter ID: " << endl;
	cin >> teacher.i_d;
	cout << "Please enter the period in school of the teacher (in years): " << endl;
	cin >> teacher.Period;
	cout << "Please enter the Amount of Professions: " << endl;
	cin >> teacher.AmountProfession;
	teacher.NameProfession = new string[teacher.AmountProfession];
	for (int i = 0; i < this->AmountProfession; i++)
	{
		cout << "Please enter profession number " << i + 1<<": ";
		_flushall();
		cin >> teacher.NameProfession[i];
	}
	cout << endl;

}
