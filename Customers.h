#include <iostream>
using namespace std;

#pragma once
class Customers
{
private:
	int customerID;
	char* name;
	char* address;
	char* phone;
	char* email;
public:
	Customers();
	Customers(const int& customerID, const char* name, const char* address, const char* phone, const char* email);
	Customers(const Customers& obj);
	~Customers();
	void setCustomerID(const int&);
	int getCustomerID()const;
	void setName(const char*);
	char* getName()const;
	void setAddress(const char*);
	char* getAddress()const;
	void setPhone(const char*);
	char* getPhone()const;
	void setEmail(const char*);
	char* getEmail()const;
	void display()const;
	Customers& operator = (const Customers& obj);
};