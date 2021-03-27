#include <iostream>
#include "drink.h"

using namespace std;

int main()
{
	Drink drink1("cola", 500, 2, 50);
	cout<<drink1.get_name()<<endl;
	Drink drink2(drink1);
	cout<<drink2.get_price();
	if(drink1==drink2)cout<<true;


	return 0;
	
}
