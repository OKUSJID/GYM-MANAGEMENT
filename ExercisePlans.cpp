#include "ExercisePlans.h"

ExercisePlans::ExercisePlans()
{
	planID = {};
	trainerID = {};
	equipmentID = {};
	durations = {};
}

ExercisePlans::ExercisePlans(const int& planID, const int& trainerID, const int& equipmentID, const int& durations)
{
	setPlanID(planID);
	setTrainerID(trainerID);
	setEquipmentID(equipmentID);
	setDurations(durations);
}

void ExercisePlans::setPlanID(const int& planID)
{
	if (planID >= 0)
	{
		this->planID = planID;
	}
	else
	{
		this->planID = {};
	}
}

int ExercisePlans::getPlanID() const
{
	return this->planID;
}

void ExercisePlans::setTrainerID(const int& trainerID)
{
	if (trainerID >= 0)
	{
		this->trainerID = trainerID;
	}
	else
	{
		this->trainerID = {};
	}
}

int ExercisePlans::getTrainerID() const
{
	return this->trainerID;
}

void ExercisePlans::setEquipmentID(const int& equipmentID)
{
	if (equipmentID>=0)
	{
		this->equipmentID = equipmentID;
	}
	else
	{
		this->equipmentID = {};
	}
}

int ExercisePlans::getEquipmentID() const
{
	return this->equipmentID;
}

void ExercisePlans::setDurations(const int&)
{
	if (durations>=0)
	{
		this->durations = durations;
	}
	else
	{
		this->durations = {};
	}
}

int ExercisePlans::getDurations() const
{
	return this->durations;
}

void ExercisePlans::display() const
{
	cout << "Plan ID: " << planID << endl;
	cout << "Trainer ID: " << trainerID << endl;
	cout << "Equipment ID: " << equipmentID << endl;
	cout << "Durations: "<<durations << endl;
}