#pragma once
#include <iostream>
#include <string>
using namespace std;

class Bank {
private:
	int id;
	string first_name;
	string last_name;
	int balance;
public:
	Bank(int _id, string _name, string _lastname, int _balance);
	int get_id();
	string get_first_name();
	string get_last_name();
	int get_balance();



};