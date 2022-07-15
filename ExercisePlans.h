#include <iostream>
using namespace std;

#pragma once
class ExercisePlans
{
private:
	int planID;
	int trainerID;
	int equipmentID;
	int durations;
public:
	ExercisePlans();
	ExercisePlans(const int&, const int&, const int&, const int&);
	void setPlanID(const int&);
	int getPlanID()const;
	void setTrainerID(const int&);
	int getTrainerID()const;
	void setEquipmentID(const int&);
	int getEquipmentID()const;
	void setDurations(const int&);
	int getDurations()const;
	void display()const;
};