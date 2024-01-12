#include <iostream>
#include <string>
#include <fstream>
#include "bank.h"
#include "customers.h"
#include <cstdlib>
using namespace std;

void show_options() {
	cout << endl;
	cout << "*************************************************" << endl;
	cout << "***************                   ***************" << endl;
	cout << "**********        WELCOME TO MENU     ***********" << endl;
	cout << "***************                   ***************" << endl;
	cout << "*************************************************" << endl;
	cout << "*                1.Add New Customer             *" << endl;
	cout << "*************************************************" << endl;
	cout << "*                2.Show All Customers           *" << endl;
	cout << "*************************************************" << endl;
	cout << "*                3.Delete Customer              *" << endl;
	cout << "*************************************************" << endl;
	cout << "*                4.Search Customer              *" << endl;
	cout << "*************************************************" << endl;
	cout << "*                5.Exit                         *" << endl;
	cout << "*************************************************" << endl;

}
void add_customer() {
	int id, balance, credit_limit;
	string name, lastname, adress, phone_number;

	while (true)
	{
		cout << "- Please insert of customer id:";
		cin >> id;

		if (!cin)
		{
			cout << endl << "Please insert only integer! You are directing back" << endl << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
		else { break; }
	}
	ifstream infile("customers.txt");
	string line;
	while (getline(infile, line)) {
		if (line.find("id:") == 0) {
			int _id = atoi(line.substr(3).c_str());
			if (id == _id) {
				cout << "A customer with the same id already exists. Cannot add a new customer with the same ID!!!!!" << endl;
				infile.close();
				return;
			}
		}
	}
	cout << "- Please insert of customer name:";
	cin.ignore();
	getline(cin, name);
	cout << "- Please insert of customer last name:";
	getline(cin, lastname);
	while (true)
	{
		cout << "- Please insert of customer balance:";
		cin >> balance;
		if (!cin)
		{
			cout << endl << "Please insert only integer! You are directing back" << endl << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
		else { break; }
	}
	cout << "- Please insert of customer adress:";
	cin.ignore();
	getline(cin, adress);
	cout << "- Please insert of customer phone number:";
	getline(cin, phone_number);
	while (true)
	{
		cout << "- Please insert of customer credit limit:";
		cin >> credit_limit;
		if (!cin)
		{
			cout << endl << "Please insert only integer! You are directing back" << endl << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
		else { break; }
	}

	Customers customer(id, name, lastname, balance, adress, phone_number, credit_limit);
	fstream create_customer;
	create_customer.open("customers.txt", ios::out | ios::binary | ios::app);//this txt file created in this project folder.So it will work fine any computer. 
	if (!create_customer.is_open()) {
		cout << "File can not open";
	}
	else
	{

		create_customer << "id:" << customer.get_id() << endl << "Name:" << customer.get_first_name() << endl << "Last Name:" << customer.get_last_name() << endl << "Balance:" << customer.get_balance() << endl << "Adress:" << customer.get_adress() << endl << "Phone Number:" << customer.get_phone_number() << endl << "Credit Limit:" << customer.get_credit_limit() << endl << endl;
		create_customer.close();
	}
}

void show_customers() {
	cout << "**********************************************" << endl;
	cout << "*              LIST OF CUSTOMERS             *" << endl;
	cout << "**********************************************" << endl << endl;
	ifstream read_customers_infos("customers.txt");
	string info;
	if (!read_customers_infos.is_open()) {
		cout << "File can not open";
	}
	else
	{
		while (getline(read_customers_infos, info)) {
			cout << info << endl;
		}
		read_customers_infos.close();
	}

}

void  delete_customer() {
	int id;
	while (true)
	{
		cout << "Please insert id of customer you want delete:";
		cin >> id;
		cout << endl;
		if (!cin)
		{
			cout << "Please insert only integer! You are directing back" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
		else { break; }
	}
	ifstream infile("customers.txt");
	ofstream temporaryfile("temp.txt");

	if (!infile || !temporaryfile) {
		cerr << "File cannot open !!!!";
		exit(1);
	}

	string line;
	bool found = false;

	while (getline(infile, line)) {
		if (line.find("id:") == 0) {
			int _id = atoi(line.substr(3).c_str());
			if (id == _id) {
				found = true;
				while (getline(infile, line) && !line.empty()) {

				}
				continue;
			}
		}
		temporaryfile << line << endl;
	}
	infile.close();
	temporaryfile.close();

	if (!found) {
		cout << "Customer cannot found";
	}
	else {
		remove("customers.txt");
		rename("temp.txt", "customers.txt");
		cout << "Customer is deleted";
	}
}
void search_customer() {

	int id;
	while (true)
	{
		cout << endl << "Please insert id of customer you want search:";
		cin >> id;
		cout << endl;
		if (!cin)
		{
			cout << "Please insert only integer! You are directing back" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
		else { break; }
	}
	ifstream infile("customers.txt");
	string line;
	bool found = false;

	while (getline(infile, line)) {
		if (line.find("id:") == 0) {
			int _id = atoi(line.substr(3).c_str());
			if (id == _id) {
				found = true;
				cout << line << endl;
				while (getline(infile, line) && !line.empty()) {
					cout << line << endl;
				}
				break;
			}
		}
	}
	if (!found) {
		cout << "Customer cannot found";
	}

}

int main()
{

	int option;

	do
	{
		show_options();
		while (true)
		{
			cout << "Please choose a number between 1 and 5 :";
			cin >> option;
			cout << endl;
			if (!cin)
			{
				cout << endl << "Please insert only integer! You are directing back" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				continue;
			}
			else { break; }
		}
		switch (option)
		{
		case 1:
			add_customer();
			break;
		case 2:
			show_customers();
			break;
		case 3:
			delete_customer();
			break;
		case 4:
			search_customer();
			break;
		case 5:
			return 0;
			break;
		default:
			cout << "Please choose a number between 5 and 1" << endl;
			break;
		}
	} while (option != 5);
}