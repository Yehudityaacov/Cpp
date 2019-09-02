#define _CRT_SECUERE_NO_WARNINGS
#ifndef _LAYER_L
#define _LAYER_L
#include <iostream>
#include <string> 
#include "Class.h"
using namespace std;
class Class;
class Layer
{
public:
	Class* ClassByIndex(int index);//gets a number and return the pointer to the class by it's index in the array class list
	Layer(char ch);//Constructor that recieve the name of the layer and creates 3 classes in the  ech layer
	~Layer();//distructor
	Layer();//default construcor
	
private:
	char NameLayer;
	Class**AllClass;
	int AmountAllClass;
	
};
#endif
