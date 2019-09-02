#include "Worker.h"
Worker::Worker() :Person()//initialization defult  c'tor
{
	Period=0;
}
Worker::Worker(Worker&worker) : Person(worker)//initialization copy c'tor
{
	this->Period = worker.Period;

}
Worker::~Worker()//Worker d'tor
{
	cout << "Worker D'tor" << endl;
}
void Worker::PrintDetails()//prints the worker details
{
	Person::PrintDetails();
	cout << "Amount of period in work is: " ;
	cout << Period<<endl;	
	cout << " salary is: " ;
	cout << GetSalary() << endl;
}

