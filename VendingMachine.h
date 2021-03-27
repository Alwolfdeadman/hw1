#ifndef VENDINGMACHINE_H
#define VENDINGMACHINE_H


#include <iostream>
#include <cstring>
#include "drink.h"


class VendingMachine {
public:
    VendingMachine();
    VendingMachine(const VendingMachine& from);
    VendingMachine& operator=(const VendingMachine& from);
    
    bool add_drink(const Drink& to_add);
    int buy_drink(const char* drink_name, const double money);	

    double get_income() const;
    
    ~VendingMachine();
private:
	double income;
	int size;
	Drink** drinks;

};
#endif
