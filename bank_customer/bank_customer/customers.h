#pragma once
#include <iostream>
#include "bank.h"
using namespace std;

class Customers : public Bank {
private:
	string adress;
	string phone_number;
	int credit_limit;
public:
	Customers(int _id, string _name, string _lastname, int _balance, string _adress, string _phonenumber, int _credit_limit);
	string get_adress();
	string get_phone_number();
	int get_credit_limit();

};