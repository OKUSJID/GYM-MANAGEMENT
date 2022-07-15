#include <iostream>
using namespace std;

#pragma once
class Equipment
{
private:
	int equipmentID;
	char* name;
public:
	Equipment();
	Equipment(const int& equipmentID, const char* name);
	Equipment(const Equipment& obj);
	~Equipment();
	void setEquipmentID(const int&);
	int getEquipmentID()const;
	void setName(const char*);
	char* getName()const;
	void display()const;
	Equipment& operator =(const Equipment&);
};