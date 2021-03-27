#include "VendingMachine.h"


VendingMachine::VendingMachine()
{
	size =1;
	drinks = new Drink*[size];
	income =0.0;
}

VendingMachine::VendingMachine(const VendingMachine& from)
{
	this->income=from.income;
	this->size=from.size;

	
	int counter=(this->size)-1;
	while(counter==-1)
	{
		delete this->drinks[counter];
		counter--;
	}
	delete[] this->drinks;
	drinks=new Drink*[from.size];
	counter=(this->size)-1;
	while(counter==-1)
	{
		this->drinks[counter]=from.drinks[counter];
		counter--;
	}
}

VendingMachine& VendingMachine::operator=(const VendingMachine& from) 
{
    this->income=from.income;
    this->size=from.size;
    
    
    int counter=(this->size)-1;
    if(this->drinks != nullptr)
	{
		while(counter==-1)
		{
			delete this->drinks[counter];
			counter--;
		}
		delete[] this->drinks;
	}
	drinks=new Drink*[size];
	counter=(this->size)-1;
	while(counter==-1)
	{
		this->drinks[counter]=from.drinks[counter];
		counter--;
	}
}


bool VendingMachine::add_drink(const Drink& to_add) 
{
	int counter=0;
	while(counter<this->size)
	{
		if(*drinks[counter]==to_add)return false;
		else if(counter == this->size-1)
		{
			size++;
			counter++;
			*drinks[counter]=to_add;
			break;
		}
	counter++;
	}
	return true;
}


int VendingMachine::buy_drink(const char* drink_name, const double money)
{
	int counter=0,check;
	int size2=size;
	Drink** newDrinks=new Drink*[size];
	while(counter<this->size)
	{
		if(*drinks[counter]->get_name()==drink_name) 
		{
			if(*drinks[counter]->get_price()>money)
			{
				this->income=this->income + money;
				*newDrinks[counter]=*drinks[counter];
				check=1;
			}
			else if(*drinks[counter]->get_price()<=money )
			{
				this->income=this->income + money;
				check=0;
			}	
		}else *newDrinks[counter]=*drinks[counter];
		counter++;
		if(counter==this->size)check= 2;
	}
	counter=0;
	if (check == 0)
	{
		size2=size2-1;
		delete newDrinks[size2];
	}
	while(counter<this->size)
	{
		delete this->drinks [counter];
		counter++;
	}
	this->drinks=newDrinks;
	delete[] newDrinks;
	this->size=size2;
	return check;
}	



double VendingMachine::get_income() const
{
	return this->income;
}





VendingMachine::~VendingMachine()
{
	int counter=this->size;
	while(counter==-1)
	{
		delete this->drinks[counter];
		counter--;
	}
	delete[] this->drinks;
}



