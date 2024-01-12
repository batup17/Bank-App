#include "customers.h"
#include "bank.h"

Customers::Customers(int _id, string _name, string _lastname, int _balance, string _adress, string _phonenumber, int _credit_limit) : Bank(_id, _name, _lastname, _balance) {
	adress = _adress;   phone_number = _phonenumber;  credit_limit = _credit_limit;
}

string Customers::get_adress() {
	return adress;
}
string Customers::get_phone_number() {
	return phone_number;
}
int Customers::get_credit_limit() {
	return credit_limit;
}