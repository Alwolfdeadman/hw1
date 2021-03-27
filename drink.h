#ifndef DRINK_H
#define DRINK_H


#include <iostream>
#include <cstring>



class Drink {
public:
    Drink(const char* init_name, const int init_calories, const double& init_quantity, const double& init_price);
    Drink(const Drink&);
    Drink& operator=(const Drink&);
    bool operator==(const Drink& other) const;

    const char* get_name() const;
    int get_calories() const;
    double get_quantity() const;
    double get_price() const;
    
    void set_name(const char* new_name);
    
    ~Drink();
private:
	int cal;
	double quantity;
	double price;
	
	char* name;
};


#endif
