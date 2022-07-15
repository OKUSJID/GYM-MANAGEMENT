#include <iostream>
#include <cstring>
using namespace std;

#include "Equipment.h"
#include "Trainers.h"
#include "Customers.h"
#include "ExercisePlans.h"
#include "Subscriptions.h"

#pragma once
class Gym
{
private:
	int gymID;
	int noOfEquipments;
	Equipment* equipments;

	int noOfTrainers;
	Trainers* trainers;

	int noOfCustomers;
	Customers* customers;

	int noOfExercisePlans;
	ExercisePlans* exercisePlans;

	int noOfSubscriptions;
	Subscriptions* subscriptions;
public:	
	Gym();
	Gym(const int&, const int&, Equipment*, const int&, Trainers*, const int&, Customers*, const int&, ExercisePlans*, const int&, Subscriptions*);
	~Gym();

	void setGymID(const int&);
	int getGymID()const;

	void setNoOfEquipments(const int&);
	int getNoOfEquipments()const;

	void setNoOfTrainers(const int&);
	int getNoOfTrainers()const;

	void setNoOfCustomers(const int&);
	int getNoOfCustomers()const;

	void setNoOfExercisePlans(const int&);
	int getNoOfExercisePlans()const;

	void setNoOfSubscriptions(const int&);
	int getNoOfSubscriptions()const;

	bool addEquipment(const int&, const char*);
	void modifyEquipment();
	void deleteEquipment();

	bool addTrainer(const int&, const char*);
	void modifyTrainer();
	void deleteTrainer();

	bool addCustomer(const int&, const char*, const char*, const char*, const char*);
	void modifyCustomer();
	void deleteCustomer();

	bool addExercisePlan(const int&, const int&, const int&, const int&);
	void modifyExercisePlan();
	void deleteExercisePlan();

	bool addSubscription(const int&, const Date&, const int&, const int&);
	void modifySubscription();
	void deleteSubscription();

	void Menu();

	void display()const;
};