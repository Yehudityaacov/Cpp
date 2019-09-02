#include"School.h"
School::School()//initialization defult  c'tor
{
	AmountAllaLayer = 6;
	AmountAllPerson = 0;
	pLayer = new Layer*[AmountAllaLayer];
	char ch = 'a';
	for (int i = 0; i < AmountAllaLayer; i++)
	{
		pLayer[i] = new Layer(ch);
		ch++;
	}
	this->Allpersons = new Person*[this->AmountAllPerson];
	ManagerExsit = false;
}
School::~School()//distructor
{
	if (this->pLayer != NULL)
	{
		for (int i = 0; i < this->AmountAllaLayer; i++)
		{
			delete pLayer[i];
		}
		delete[] pLayer;
	}
	
	if (this->Allpersons != NULL)
	{
		for (int i = 0; i < this->AmountAllaLayer; i++)
		{
			delete Allpersons[i];
		}
		delete[] Allpersons;
	}

}
void School::AddPupil()
{
		Pupil*p_ptr=NULL;
		p_ptr = new Pupil();
		char tamplayer,i;
		p_ptr->Setdetails(*p_ptr);
		for ( i = 0; i < AmountAllPerson; i++)
		{
			if (p_ptr->getID() == Allpersons[i]->Getid())//Cheack if the person already exsist in the school
			{
				cout << "the pupil is already exsist !";
				break;
			}
		}
		if (i == AmountAllPerson)
		{
			tamplayer = p_ptr->Getlayername();
			(pLayer[tamplayer - 'a'])->ClassByIndex(p_ptr->GetclassNumber())->AddPupil(p_ptr);//adding the pupil to the class
			Person**newperson = new Person*[AmountAllPerson + 1];//adding the pupil to allperson  school list
			for (int i = 0; i < AmountAllPerson; i++)
			{
				newperson[i] = Allpersons[i];
			}
			newperson[AmountAllPerson] = p_ptr;
			delete[] Allpersons;
			Allpersons = new Person*[AmountAllPerson + 1];
			AmountAllPerson++;
			for (int i = 0; i < AmountAllPerson; i++)
			{
				Allpersons[i] = newperson[i];
			}
			delete[] newperson;
		}
}
void  School::AddTeacher()
{
	Teacher*p_ptr = new Teacher();
	char tampTeacher = 0, i = 0;
	p_ptr->Setdetails(*p_ptr);//Set details of the teacher
	for (i = 0; i < AmountAllPerson; i++)
	{
		if (p_ptr->GetID() == Allpersons[i]->Getid())
		{
			cout << "the Teacher is already exsist !";
			break;
		}
	}
	if (i == AmountAllPerson)
	{
		Person**newperson = new Person*[AmountAllPerson + 1];//adding the Teacher to allperson  school list
		for (int i = 0; i < AmountAllPerson; i++)
		{
			newperson[i] = Allpersons[i];
		}
		newperson[AmountAllPerson] = p_ptr;
		delete[] Allpersons;
		Allpersons = new Person*[AmountAllPerson + 1];
		AmountAllPerson++;
		for (int i = 0; i < AmountAllPerson; i++)
		{
			Allpersons[i] = newperson[i];
		}
		delete[] newperson;
	}

}
void School::AddTutor()
{
	Tutor*p_ptr = NULL;//a pointer for tutor
	p_ptr = new Tutor();
	char tempPlayer;
	int i;
	p_ptr->Setdetails(*p_ptr);//get the detail of the tutor from the user
	
	for (i = 0; i < AmountAllPerson; i++)
	{
	
		if (p_ptr->GetID() == Allpersons[i]->Getid())//cheak if the person is exsist in the holl school
		{
			cout << "the Teacher is alredy exsist !";
			break;
		}
	}
	if (i == AmountAllPerson)//adding the tutor to allperson  school list
	{
		tempPlayer = p_ptr->GetNameLayer();
		if (pLayer[tempPlayer - 'a']->ClassByIndex(p_ptr->GetClassNumb())->AddTutor(p_ptr) == true)//cheak if ther is no tutor in the class already and add the tutor to the class
		{
			p_ptr->addClass(pLayer[tempPlayer - 'a']->ClassByIndex(p_ptr->GetClassNumb()));//add class to the tutor
			Person**newperson = new Person*[AmountAllPerson + 1];//adding the Tutor to allperson  school list
			for (int i = 0; i < AmountAllPerson; i++)
			{
				newperson[i] = Allpersons[i];
			}
			newperson[AmountAllPerson] = p_ptr;
			delete[] Allpersons;
			Allpersons = new Person*[AmountAllPerson + 1];
			AmountAllPerson++;
			for (int i = 0; i < AmountAllPerson; i++)
			{
				Allpersons[i] = newperson[i];
			}
			delete[] newperson;
		}
		else
			cout << "the Tutor is alredy exsist !";
	}
}
void School::AddManager()
{
	int i = 0;
	Manager*tempmanager = new Manager();
	tempmanager->Setdetails(*tempmanager);
	for (i = 0; i < AmountAllPerson; i++)
	{
		if (tempmanager->GetID() == Allpersons[i]->Getid())
		{
			cout << "the Person is alredy exsist !";
			break;
		}
	}
	if (this->ManagerExsit == false)
	{
		if (i == AmountAllPerson)
		{
			ManagerExsit = true;
			Person**newmanager = new Person*[AmountAllPerson + 1]; //adding the Manager to allperson  school list
			for (int i = 0; i < AmountAllPerson; i++)
			{
				newmanager[i] = Allpersons[i];
			}
			newmanager[AmountAllPerson] = tempmanager;
			delete[] Allpersons;
			Allpersons = new Person*[AmountAllPerson + 1];
			AmountAllPerson++;
			for (int i = 0; i < AmountAllPerson; i++)
			{
				Allpersons[i] = newmanager[i];
			}
			delete[] newmanager;
		}

	}
	else
		cout << "There is already a manager to the school" << endl;
}
void School::AddSecretary()
{
	int i = 0;
	Secretary*tempsecretary = new Secretary();
	tempsecretary->Setdetails(*tempsecretary);
	for (i = 0; i < AmountAllPerson; i++)
	{
		if (tempsecretary->GetID() == Allpersons[i]->Getid())
		{
			cout << "the Secretary is alredy exsist !";
			break;
		}
	}
	if (i == AmountAllPerson)
	{
		Person**newperson = new Person*[AmountAllPerson + 1];//adding the Secretary to allperson  school list
		for (int i = 0; i < AmountAllPerson; i++)
		{
			newperson[i] = Allpersons[i];
		}
		newperson[AmountAllPerson] = tempsecretary;
		delete[] Allpersons;
		Allpersons = new Person*[AmountAllPerson + 1];
		AmountAllPerson++;
		for (int i = 0; i < AmountAllPerson; i++)
		{
			Allpersons[i] = newperson[i];
		}
		delete[] newperson;
	}
}
void School::PrintOutstandingPepole()
{
	cout << "-----------Excellent Persons In School----------" << endl;
	for (int i = 0; i < this->AmountAllPerson; i++)
	{
		if (Allpersons[i]->CheakExllent() == true);
		Allpersons[i]->PrintDetails();
		cout << endl;
	}
}
void School::printTutorClass()//CASE 8 print tutor's class
{
	system("cls");
	int tempId;
	cout << "Please enter the id of the tutor: ";
	cin >> tempId;
	if (this->AmountAllPerson == 0)//A condition for checking if the school is empty
	{
		cout << "There are no persons in the school !" << endl;
	}
	else 
	{
		//loop conditions using RTTI to print the request tutor in the pointer to the array of All persons
		for (int i = 0; i < AmountAllPerson; i++)
		{
			Pupil*tempPupil = dynamic_cast<Pupil*>(Allpersons[i]);
			Teacher*tempTeacher = dynamic_cast<Teacher*>(Allpersons[i]);
			Tutor*tempTutor = dynamic_cast<Tutor*>(Allpersons[i]);
			Manager*tempManager = dynamic_cast<Manager*>(Allpersons[i]);
			Secretary*tempSecretary = dynamic_cast<Secretary*>(Allpersons[i]);
			if (tempTutor)
			{
				if (tempTutor->GetID() == tempId)
				{
					tempTutor->PrintDetails();
				}
				else
					cout << "There is no tutor id that identical to the id you entared" << endl;
			}
		}
	}
}
void School::printHighSalaryWorker()//CASE 9 print details of the worker with biggest salary
{
	system("cls");
	int NumIdnex = 0;
	double
		maxsalary = 0;
	if (this->AmountAllPerson == 0)//A condition for checking if the school is not empty
	{
		cout << "There are no persons in the school !" << endl;
	}
	else
	{
		//loop conditions using RTTI to print the worker with the biggest salary
		for (int i = 0; i < AmountAllPerson; i++)
		{
			Worker*tempWorker = dynamic_cast<Worker*>(Allpersons[i]);
			if (tempWorker)
			{
				if (maxsalary < tempWorker->GetSalary())
					maxsalary = tempWorker->GetSalary();
				NumIdnex = i;
			}
		}
		//print details of the worker with biggest salary
		cout << "the worker with the biggest salary is: " << endl;
		Allpersons[NumIdnex]->PrintDetails();
	}
}
void School::PrintAllPersonInSchool()
{
	cout << "-----------AllPersons In School----------" << endl;
	for (int i = 0; i < this->AmountAllPerson; i++)
	{
		Allpersons[i]->PrintDetails();
		cout << endl;
	}
}

void School::Menu()
{
	int option = 0;
	int  flag = 0;
	cout << "******************************************" << endl;
	cout << "School Management System  :" << endl;
	cout << "******************************************" << endl;
	while (flag == 0)
	{
		cout << endl;
		cout << "1. Add pupil" << endl;
		cout << "2. Add teacher" << endl;
		cout << "3. Add tutor" << endl;
		cout << "4. Add manager" << endl;
		cout << "5. Add secretary" << endl;
		cout << "6. Print workers and pupil details " << endl;
		cout << "7. Print outstanding people" << endl;
		cout << "8. Print tutors class" << endl;
		cout << "9. Print worker details biggest salary" << endl;
		cout << "10. Exit" << endl;
		cout << "Please choose one of the above options:" << endl;
		cin >> option;
		switch (option)
		{
		case 1:
			this->AddPupil();
			break;
		case 2:
			this->AddTeacher();
			break;
		case 3:
			this->AddTutor();
			break;
		case 4:
			this->AddManager();
			break;
		case 5:
			this->AddSecretary();
			break;
		case 6:
			this->PrintAllPersonInSchool();
			break;
		case 7:
			this->PrintOutstandingPepole();
			break;
		case 8:
			this->printTutorClass();
			break;
		case 9:
			printHighSalaryWorker();
			break;
		case 10:
			system("cls");
			flag = 1;
			cout << "EXIT" << endl;
			break;
			system("cls");
		default:
			cout << "Wrong input" << endl;
		}
	}
}

