#include "drink.h"

Drink::Drink(const char* init_name, const int init_calories, const double& init_quantity, const double& init_price)
{
	cal=init_calories;
	quantity= init_quantity;
	price=init_price;
	
	name= new char[strlen(init_name)+1];
	strcpy(name, init_name);
	name[strlen(init_name)]='\0';
}

Drink::Drink(const Drink& other)
{
	this->cal= other.cal;
	this->quantity= other.quantity;
	this->price= other.price;
	
	
	this->name = new char [strlen(name) + 1];
	strcpy(this->name, other.name);
	this->name[strlen(this->name)] = '\0';
}




int Drink::get_calories() const
{
	return this->cal;
}

double Drink::get_quantity() const
{
	return this->quantity;
}

double Drink::get_price() const
{
	return this->price;
}

const char* Drink:: get_name() const
{
	return this->name;
}



void Drink::set_name(const char* new_name)
{
	delete[] this->name;
	name= new char[strlen(new_name)+1];
	strcpy(name, new_name);
	name[strlen(new_name)]='\0';
}



Drink::~Drink()
{
	delete[] this->name;
}


Drink& Drink::operator=(const Drink& other)  
{
	if (this != &other)
    {
		this->cal= other.cal;
		this->quantity= other.quantity;
		this->price= other.price;
		
		if(this->name != nullptr)
		{
			delete[] this->name;
		}
		this->name = new char [strlen(other.name) + 1];
    	strncpy(this->name, other.name, strlen(other.name));
    	this->name[strlen(this->name)] = '\0';
		
    }
    return *this;
}


bool Drink::operator==(const Drink& other) const 
{
	
	if (this != &other)
    {
    	if(this->cal==other.cal && this->quantity==other.quantity && this->price==other.price && strcmp(this->name, other.name)==0)
		{
			return true;
		}
		else return false; 
	}
    return true;
}
