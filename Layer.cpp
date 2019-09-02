#include  "Layer.h"
Layer::Layer()//default construcor
{		
	NameLayer = ' ';
	AllClass = NULL;
	AmountAllClass = 3;
}
Layer::Layer(char N_Layer) //non  defult  c'tor
{
	AmountAllClass = 3;
	NameLayer = N_Layer;
	AllClass = new Class*[AmountAllClass];
	for (int i = 0; i < AmountAllClass; i++)
	{
		AllClass[i] = new Class(i + 1, NameLayer);
	}
}
Layer::~Layer()//distructor
{
	if (AllClass != NULL)
	for (int i = 0; i < AmountAllClass; i++)
	{
		delete AllClass[i];
	}
		delete[] AllClass;
}
Class* Layer::ClassByIndex(int index)//gets a number and return the pointer to the class by it's index in the array class list
{ 
	return AllClass[index - 1];
}