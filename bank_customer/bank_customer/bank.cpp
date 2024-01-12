#include <iostream>
#include "bank.h"
using namespace std;

Bank::Bank(int _id, string _name, string _lastname, int _balance) {
	id = _id;    first_name = _name;    last_name = _lastname;    balance = _balance;
}
int Bank::get_id() {
	return id;
}
string Bank::get_first_name() {
	return first_name;
}
string Bank::get_last_name() {
	return last_name;
}
int Bank::get_balance() {
	return balance;
}