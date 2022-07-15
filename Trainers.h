#include <iostream>
using namespace std;

#pragma once
class Trainers
{
private:
	int trainerID;
	char* name;
public:
	Trainers();
	Trainers(const int& trainerID, const char* name);
	Trainers(const Trainers& obj);
	~Trainers();
	void setTrainerID(const int&);
	int getTrainerID()const;
	void setName(const char*);
	char* getName()const;
	void display()const;
	Trainers& operator =(const Trainers&);
};