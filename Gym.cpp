#include "Gym.h"

Gym::Gym()
{
	gymID = {};
	noOfEquipments = {};
	noOfTrainers = {};
	noOfCustomers = {};
	noOfExercisePlans = {};
	noOfSubscriptions = {};
	equipments = nullptr;
	trainers = nullptr;
	customers = nullptr;
	exercisePlans = nullptr;
	subscriptions = nullptr;
}

Gym::Gym(const int& gymID, const int& noOfEquipments, Equipment* equipments, const int& noOfTrainers, Trainers* trainers, const int& noOfCustomers, Customers* customers, const int& noOfExercisePlans, ExercisePlans* exercisePlans, const int& noOfSubscriptions, Subscriptions* subscriptions)
{
	setGymID(gymID);
	
	setNoOfEquipments(noOfEquipments);
	this->equipments = new Equipment[getNoOfEquipments()];
	for (int i = 0; i < getNoOfEquipments(); ++i)
	{
		this->equipments[i] = equipments[i];
	}

	setNoOfTrainers(noOfTrainers);
	this->trainers = new Trainers[getNoOfTrainers()];
	for (int i = 0; i < getNoOfTrainers(); ++i)
	{
		this->trainers[i] = trainers[i];
	}

	setNoOfCustomers(noOfCustomers);
	this->customers = new Customers[getNoOfCustomers()];
	for (int i = 0; i < getNoOfCustomers(); ++i)
	{
		this->customers[i] = customers[i];
	}

	setNoOfExercisePlans(noOfExercisePlans);
	this->exercisePlans = new ExercisePlans[getNoOfExercisePlans()];
	for (int i = 0; i < getNoOfExercisePlans(); ++i)
	{
		this->exercisePlans[i] = exercisePlans[i];
	}

	setNoOfSubscriptions(noOfSubscriptions);
	this->subscriptions = new Subscriptions[getNoOfSubscriptions()];
	for (int i = 0; i < getNoOfSubscriptions(); ++i)
	{
		this->subscriptions[i] = subscriptions[i];
	}
}

Gym::~Gym()
{
	if (this->equipments != nullptr)
	{
		delete this->equipments;
		this->equipments = nullptr;
	}
	if (this->trainers != nullptr)
	{
		delete this->trainers;
		this->trainers = nullptr;
	}
	if (this->customers != nullptr)
	{
		delete this->customers;
		this->customers = nullptr;
	}
	if (this->exercisePlans != nullptr)
	{
		delete this->exercisePlans;
		this->exercisePlans = nullptr;
	}
	if (this->subscriptions != nullptr)
	{
		delete this->subscriptions;
		this->subscriptions = nullptr;
	}
}

void Gym::setGymID(const int& gymID)
{
	if (gymID > 0)
	{
		this->gymID = gymID;
	}
	else
	{
		this->gymID = {};
	}
}

int Gym::getGymID() const
{
	return this->gymID;
}

void Gym::setNoOfEquipments(const int& noOfEquipments)
{
	if (noOfEquipments > 0)
	{
		this->noOfEquipments = noOfEquipments;
	}
	else
	{
		this->noOfEquipments = {};
	}
}

int Gym::getNoOfEquipments() const
{
	return this->noOfEquipments;
}

void Gym::setNoOfTrainers(const int& noOfTrainers)
{
	if (noOfTrainers >= 0)
	{
		this->noOfTrainers = noOfTrainers;
	}
	else
	{
		this->noOfTrainers = {};
	}
}

int Gym::getNoOfTrainers() const
{
	return this->noOfTrainers;
}

void Gym::setNoOfCustomers(const int& noOfCustomers)
{
	if (noOfCustomers >= 0)
	{
		this->noOfCustomers = noOfCustomers;
	}
	else
	{
		this->noOfCustomers = {};
	}
}

int Gym::getNoOfCustomers() const
{
	return this->noOfCustomers;
}

void Gym::setNoOfExercisePlans(const int& noOfExercisePlans)
{
	if (noOfExercisePlans >= 0)
	{
		this->noOfExercisePlans = noOfExercisePlans;
	}
	else
	{
		this->noOfExercisePlans = {};
	}
}

int Gym::getNoOfExercisePlans() const
{
	return this->noOfExercisePlans;
}

void Gym::setNoOfSubscriptions(const int& noOfSubscriptions)
{
	if (noOfSubscriptions >= 0)
	{
		this->noOfSubscriptions = noOfSubscriptions;
	}
	else
	{
		this->noOfSubscriptions = {};
	}
}

int Gym::getNoOfSubscriptions() const
{
	return this->noOfSubscriptions;
}

bool Gym::addEquipment(const int& equipmentID, const char* name)
{
	bool status = {};
	for (int i = 0; i < noOfEquipments; ++i)
	{
		if (this->equipments[i].getEquipmentID() == equipmentID)
		{
			status = true;
			break;
		}
	}
	if (!status)
	{
		Equipment* TempoArray = new Equipment[noOfEquipments + 1]();
		
		for (int i = 0; i < noOfEquipments; ++i)
		{
			TempoArray[i] = equipments[i];
		}
		
		TempoArray[noOfEquipments].setEquipmentID(equipmentID);
		TempoArray[noOfEquipments].setName(name);
		++noOfEquipments;

		if (this->equipments != nullptr)
		{
			delete[] this->equipments;
			this->equipments = nullptr;
		}

		this->equipments = new  Equipment[noOfEquipments]();
		for (int i = 0; i < noOfEquipments; ++i)
		{
			equipments[i] = TempoArray[i];
		}
		return true;
	}
	else
	{
		cout << "\nThere exist a Equipment already with this ID.\n";
	}
	return false;
}

void Gym::modifyEquipment()
{
	int ID = {};
	cout << "Enter ID of Equipment: ";
	cin >> ID;

	int index = {};

	bool check = {};
	for (int i = 0; i < noOfEquipments; ++i)
	{
		if (this->equipments[i].getEquipmentID() == ID)
		{
			check = true;
			index = i;
			break;
		}
	}
	if (check)
	{
		char choice = {};
		cout << "Do you want to change the name of equipment<Press Y for Yes/N for No>: ";
		
		cout << "\nPress Enter your Choice: ";
		cin >> choice;
		
		if (toupper(choice) == 'Y')
		{
			char name[40] = {};
			cout << "Enter Equipment Name: ";
			cin.get(name, sizeof(name));
			this->equipments[index].setName(name);
			this->equipments[index].display();
		}
	}
	else
	{
		cout << "\nThere is no Equipment Available with this ID.\n";
	}
}

void Gym::deleteEquipment()
{
	int ID = {};
	cout << "Enter ID of Equipment: ";
	cin >> ID;

	bool check = {};
	for (int i = 0; i < noOfEquipments; ++i)
	{
		if (this->equipments[i].getEquipmentID() == ID)
		{
			check = true;
			for (int j = i; j < noOfEquipments - 1; ++j)
			{
				this->equipments[j] = this->equipments[j + 1];
			}
			--noOfEquipments;
			break;
		}
	}
	if (check)
	{
		cout << "\nThe Equipment has been deleted sucessfully.\n";
	}
	else
	{
		cout << "\nThere is no Equipment Available with this ID.\n";
	}
}

bool Gym::addTrainer(const int& trainerID, const char* name)
{
	bool status = {};
	for (int i = 0; i < noOfTrainers; ++i)
	{
		if (this->trainers[i].getTrainerID() == trainerID)
		{
			status = true;
			break;
		}
	}
	if (!status)
	{
		Trainers* TempoArray = new Trainers[noOfTrainers + 1]();

		for (int i = 0; i < noOfTrainers; ++i)
		{
			TempoArray[i] = trainers[i];
		}

		TempoArray[noOfTrainers].setTrainerID(trainerID);
		TempoArray[noOfTrainers].setName(name);
		++noOfTrainers;

		if (this->trainers != nullptr)
		{
			delete[] this->trainers;
			this->trainers = nullptr;
		}
		this->trainers = TempoArray;
		return true;
	}
	else
	{
		cout << "\nThere exist a Trainer already with this ID.\n";
	}
	return false;
}

void Gym::modifyTrainer()
{
	int ID = {};
	cout << "Enter ID of Trainer: ";
	cin >> ID;

	int index = {};

	bool check = {};
	for (int i = 0; i < noOfTrainers; ++i)
	{
		if (this->trainers[i].getTrainerID() == ID)
		{
			check = true;
			index = i;
			break;
		}
	}
	if (check)
	{
		char choice = {};
		cout << "Do you want to change the name of Trainer<Press Y for Yes/N for No>: ";
		cout << "\nPress Enter your Choice: ";
		cin >> choice;
		if (toupper(choice) == 'Y')
		{
			char name[40] = {};
			cout << "Enter Trainer Name: ";
			cin.get(name, sizeof(name));
			this->trainers[index].setName(name);
			this->trainers[index].display();
		}
	}
	else
	{
		cout << "\nThere is no Trainer Available with this ID.\n";
	}
}

void Gym::deleteTrainer()
{
	int ID = {};
	cout << "Enter ID of Trainer: ";
	cin >> ID;

	bool check = {};
	for (int i = 0; i < noOfTrainers; ++i)
	{
		if (this->trainers[i].getTrainerID() == ID)
		{
			check = true;
			for (int j = i; j < noOfTrainers - 1; ++j)
			{
				this->trainers[j] = this->trainers[j + 1];
			}
			--noOfTrainers;
			break;
		}
	}
	if (check)
	{
		cout << "\nThe Trainer has been deleted sucessfully.\n";
	}
	else
	{
		cout << "\nThere is no Trainer Available with this ID.\n";
	}
}

bool Gym::addCustomer(const int& customerID, const char* name, const char* address, const char* phone, const char* email)
{
	bool status = {};
	for (int i = 0; i < noOfCustomers; ++i)
	{
		if (this->customers[i].getCustomerID() == customerID)
		{
			status = true;
			break;
		}
	}
	if (!status)
	{
		Customers* TempoArray = new Customers[noOfCustomers + 1];

		for (int i = 0; i < noOfCustomers; ++i)
		{
			TempoArray[i] = customers[i];
		}

		TempoArray[noOfCustomers].setCustomerID(customerID);
		TempoArray[noOfCustomers].setName(name);
		TempoArray[noOfCustomers].setAddress(address);
		TempoArray[noOfCustomers].setPhone(phone);
		TempoArray[noOfCustomers].setEmail(email);
		++noOfCustomers;

		if (this->customers != nullptr)
		{
			delete[] this->customers;
			this->customers = nullptr;
		}
		this->customers = TempoArray;
		return true;
	}
	else
	{
		cout << "\nThere exist a Customer already with this ID.\n";
	}
	return false;
}

void Gym::modifyCustomer()
{
	int ID = {};
	cout << "Enter ID of Customer: ";
	cin >> ID;

	int index = {};

	bool check = {};
	for (int i = 0; i < noOfCustomers; ++i)
	{
		if (this->customers[i].getCustomerID() == ID)
		{
			check = true;
			index = i;
			break;
		}
	}
	if (check)
	{
		char choice = {};
		while (toupper(choice) != '0')
		{
			cout << "\nA. Do you want to change the Name of Customer: ";
			cout << "B. Do you want to change the Address of Customer: ";
			cout << "C. Do you want to change the Phone of Customer: ";
			cout << "D. Do you want to change the Email of Customer: ";
			cout << "E. Do you want to display the details of Customer: ";
			cout << "0: Quit ";
			cout << "\nPress Enter your Choice: ";
			cin >> choice;

			if (toupper(choice) == 'A')
			{
				char name[40] = {};
				cout << "Enter Customer Name: ";
				cin.get(name, sizeof(name));
				this->customers[index].setName(name);
			}
			else if (toupper(choice) == 'B')
			{
				char address[70] = {};
				cout << "Enter Customer Address: ";
				cin.get(address, sizeof(address));
				this->customers[index].setAddress(address);
			}
			else if (toupper(choice) == 'C')
			{
				char phone[15] = {};
				cout << "Enter Customer Phone: ";
				cin.get(phone, sizeof(phone));
				this->customers[index].setPhone(phone);
			}
			else if (toupper(choice) == 'D')
			{
				char email[50] = {};
				cout << "Enter Customer Email: ";
				cin.get(email, sizeof(email));
				this->customers[index].setEmail(email);
			}
			else if (toupper(choice) == 'E')
			{
				this->customers[index].display();
			}
			else
			{
				cout << "\nWrong Input.\nTry Again.\n";
			}
		}
	}
	else
	{
		cout << "\nThere is no Customer Available with this ID.\n";
	}
}

void Gym::deleteCustomer()
{
	int ID = {};
	cout << "Enter ID of Customer: ";
	cin >> ID;

	bool check = {};
	for (int i = 0; i < noOfCustomers; ++i)
	{
		if (this->customers[i].getCustomerID() == ID)
		{
			check = true;
			for (int j = i; j < noOfCustomers - 1; ++j)
			{
				this->customers[j] = this->customers[j + 1];
			}
			--noOfCustomers;
			break;
		}
	}
	if (check)
	{
		cout << "\nThe Customer has been deleted sucessfully.\n";
	}
	else
	{
		cout << "\nThere is no Customer Available with this ID.\n";
	}
}

bool Gym::addExercisePlan(const int& PlanID, const int& trainerID, const int& equipmentID, const int& durations)
{
	bool status = {};
	for (int i = 0; i < noOfExercisePlans; ++i)
	{
		if (this->exercisePlans[i].getPlanID() == PlanID)
		{
			status = true;
			break;
		}
	}
	if (!status)
	{
		ExercisePlans* TempoArray = new ExercisePlans[noOfExercisePlans + 1]();

		for (int i = 0; i < noOfExercisePlans; ++i)
		{
			TempoArray[i] = exercisePlans[i];
		}

		TempoArray[noOfExercisePlans].setPlanID(PlanID);
		TempoArray[noOfExercisePlans].setTrainerID(trainerID);
		TempoArray[noOfExercisePlans].setEquipmentID(equipmentID);
		TempoArray[noOfExercisePlans].setDurations(durations);
		++noOfExercisePlans;

		if (this->exercisePlans != nullptr)
		{
			delete[] this->exercisePlans;
			this->exercisePlans = nullptr;
		}
		this->exercisePlans = TempoArray;
		return true;
	}
	else
	{
		cout << "\nThere exist a Exercise Plan already with this ID.\n";
	}
	return false;
}

void Gym::modifyExercisePlan()
{
	int ID = {};
	cout << "Enter ID of Exercise Plan: ";
	cin >> ID;

	int index = {};

	bool check = {};
	for (int i = 0; i < noOfExercisePlans; ++i)
	{
		if (this->exercisePlans[i].getPlanID() == ID)
		{
			check = true;
			index = i;
			break;
		}
	}
	if (check)
	{
		char choice = {};
		while (toupper(choice) != '0')
		{
			cout << "\nA. Do you want to change the Trainer ID of the Exercise Plan: ";
			cout << "B. Do you want to change the Equipment of Exercise Plan: ";
			cout << "C. Do you want to change the Duration of Exercise Plan: ";
			cout << "D. Do you want to display the details of Exercise Plan: ";
			cout << "0: Quit ";
			cout << "\nPress Enter your Choice: ";
			cin >> choice;

			if (toupper(choice) == 'A')
			{
				bool status = {};
				
				while (true)
				{
					int ID = {};
					cout << "Enter Trainer ID: ";
					cin >> ID;

					for (int i = 0; i < noOfTrainers; ++i)
					{
						if (this->trainers[i].getTrainerID() == ID)
						{
							status = true;
							break;
						}
					}

					if (status)
					{
						this->exercisePlans[index].setTrainerID(ID);
						break;
					}
					else
					{
						cout << "\nNo Trainer Available with the ID.";
						cout << "Try Again.\n";
					}
				}
			}
			else if (toupper(choice) == 'B')
			{
				bool status = {};

				while (true)
				{
					int ID = {};
					cout << "Enter Equipment ID: ";
					cin >> ID;

					for (int i = 0; i < noOfEquipments; ++i)
					{
						if (this->equipments[i].getEquipmentID() == ID)
						{
							status = true;
							break;
						}
					}

					if (status)
					{
						this->exercisePlans[index].setEquipmentID(ID);
						break;
					}
					else
					{
						cout << "\nNo Equipment Available with the ID.";
						cout << "Try Again.\n";
					}
				}
			}
			else if (toupper(choice) == 'C')
			{
				int durations = {};
				cout << "Enter Durations: ";
				cin >> durations;
				this->exercisePlans[index].setDurations(durations);
			}
			else if (toupper(choice) == 'D')
			{
				this->exercisePlans[index].display();
			}
			else
			{
				cout << "\nWrong Input.\nTry Again.\n";
			}
		}
	}
	else
	{
		cout << "\nThere is no Exercise Plan Available with this ID.\n";
	}
}

void Gym::deleteExercisePlan()
{
	int ID = {};
	cout << "Enter ID of Exercise Plan: ";
	cin >> ID;

	bool check = {};
	for (int i = 0; i < noOfExercisePlans; ++i)
	{
		if (this->exercisePlans[i].getPlanID() == ID)
		{
			check = true;
			for (int j = i; j < noOfExercisePlans - 1; ++j)
			{
				this->exercisePlans[j] = this->exercisePlans[j + 1];
			}
			--noOfExercisePlans;
			break;
		}
	}
	if (check)
	{
		cout << "\nThe Exercise Plan has been deleted sucessfully.\n";
	}
	else
	{
		cout << "\nThere is no Exercise Plan Available with this ID.\n";
	}
}

bool Gym::addSubscription(const int& subscriptionID, const Date& date, const int& customerID, const int& planID)
{
	bool status = {};
	for (int i = 0; i < noOfSubscriptions; ++i)
	{
		if (this->subscriptions[i].getSubscriptionID() == subscriptionID)
		{
			status = true;
			break;
		}
	}
	if (!status)
	{
		Subscriptions* TempoArray = new Subscriptions[noOfSubscriptions + 1]();

		for (int i = 0; i < noOfSubscriptions; ++i)
		{
			TempoArray[i] = subscriptions[i];
		}

		TempoArray[noOfSubscriptions].setSubscriptionID(subscriptionID);
		TempoArray[noOfSubscriptions].setDate(date);
		TempoArray[noOfSubscriptions].setCustomerID(customerID);
		TempoArray[noOfSubscriptions].setPlanID(planID);
		++noOfSubscriptions;\

		if (this->subscriptions != nullptr)
		{
			delete[] this->subscriptions;
			this->subscriptions = nullptr;
		}
		this->subscriptions = TempoArray;
		return true;
	}
	else
	{
		cout << "\nThere exist a Subscription Plan already with this ID.\n";
	}
	return false;
}

void Gym::modifySubscription()
{
	int ID = {};
	cout << "Enter ID of Subscription Plan: ";
	cin >> ID;

	int index = {};

	bool check = {};
	for (int i = 0; i < noOfSubscriptions; ++i)
	{
		if (this->subscriptions[i].getSubscriptionID() == ID)
		{
			check = true;
			index = i;
			break;
		}
	}
	if (check)
	{
		char choice = {};
		while (toupper(choice) != '0')
		{
			cout << "\nA. Do you want to change the Date of Subscription Plan.\n";
			cout << "B. Do you want to change the Customer ID of Subscription Plan: ";
			cout << "C. Do you want to change the Exercise Plan ID of Subscription Plan: ";
			cout << "D. Do you want to display the details of Subscription Plan: ";
			cout << "0: Quit ";
			cout << "\nPress Enter your Choice: ";
			cin >> choice;

			if (toupper(choice) == 'A')
			{
				Date A;
				int day;
				int month;
				int year;
				cout << "Enter Day<1-31>: ";
				cin >> day;
				cout << "Enter Month<1-12>: ";
				cin >> month;
				cout << "Enter Year<1900-3000>: ";
				cin >> year;

				A.setDay(day);
				A.setMonth(month);
				A.setYear(year);
				this->subscriptions[index].setDate(A);
			}
			else if (toupper(choice) == 'B')
			{
				bool status = {};

				while (true)
				{
					int ID = {};
					cout << "Enter Customer ID: ";
					cin >> ID;

					for (int i = 0; i < noOfCustomers; ++i)
					{
						if (this->customers[i].getCustomerID() == ID)
						{
							status = true;
							break;
						}
					}

					if (status)
					{
						this->subscriptions[index].setCustomerID(ID);
						break;
					}
					else
					{
						cout << "\nNo Customer Available with the ID.";
						cout << "Try Again.\n";
					}
				}
			}
			else if (toupper(choice) == 'C')
			{
				bool status = {};

				while (true)
				{
					int ID = {};
					cout << "Enter Exercise Plan ID: ";
					cin >> ID;

					for (int i = 0; i < noOfExercisePlans; ++i)
					{
						if (this->exercisePlans[i].getPlanID() == ID)
						{
							status = true;
							break;
						}
					}

					if (status)
					{
						this->subscriptions[index].setPlanID(ID);
						break;
					}
					else
					{
						cout << "\nNo Customer Available with the ID.";
						cout << "Try Again.\n";
					}
				}
			}
			else if (toupper(choice) == 'D')
			{
				this->subscriptions[index].display();
			}
			else
			{
				cout << "\nWrong Input.\nTry Again.\n";
			}
		}
	}
	else
	{
		cout << "\nThere is no Subscription Plan Available with this ID.\n";
	}
}

void Gym::deleteSubscription()
{
	int ID = {};
	cout << "Enter ID of Subscription Plan: ";
	cin >> ID;

	bool check = {};
	for (int i = 0; i < noOfSubscriptions; ++i)
	{
		if (this->subscriptions[i].getSubscriptionID() == ID)
		{
			check = true;
			for (int j = i; j < noOfSubscriptions - 1; ++j)
			{
				this->subscriptions[j] = this->subscriptions[j + 1];
			}
			--noOfSubscriptions;
			break;
		}
	}
	if (check)
	{
		cout << "\nThe Subscription Plan has been deleted sucessfully.\n";
	}
	else
	{
		cout << "\nThere is no Subscription Plan Available with this ID.\n";
	}
}

void Gym::Menu()
{
	int mainchoice = -1;
	bool checkE = {};
	bool checkT = {};
	bool checkC = {};
	bool checkEP = {};

	cout << "--------<WELCOME TO THE GYM>--------\n\n";

	while (mainchoice != 0)
	{
		cout << "\nPress 1 for Equipments.\n";
		cout << "Press 2 for Trainers.\n";
		cout << "Press 3 for Customers.\n";
		cout << "Press 4 for Exercise Plans.\n";
		cout << "Press 5 for Subscriptions.\n";
		cout << "Press 6 to display Gym Details.\n";
		cout << "Press 0 to Exit.\n";
		cout << "\nPlease Enter Your Command: ";
		cin >> mainchoice;

		if (mainchoice == 1)
		{
			int A = {};
			cout << "\n1. Do you want to Add New Equipment.\n";
			cout << "2. Do you want to Modify Equipment Details.\n";
			cout << "3. Do you want to Delete a Equipment.\n";
			cout << "\nPlease Enter Your Command: ";
			cin >> A;

			if (A == 1)
			{
				int ID = {};
				char name[40] = {};
				cout << "Enter ID: ";
				cin >> ID;
				cin.ignore();
				cout << "Enter Name: ";
				cin.get(name, sizeof(name));
				if (addEquipment(ID, name))
				{
					checkE = true;
				}
			}
			else if (A == 2)
			{
				modifyEquipment();
			}
			else if (A == 3)
			{
				deleteEquipment();
				if (noOfEquipments == 0)
				{
					checkE = false;
				}
			}
			else
			{
				cout << "Invalid Input.\n";
			}
		}

		else if (mainchoice == 2)
		{
			int B = {};

			cout << "\n1. Do you want to Add New Trainer.\n";
			cout << "2. Do you want to Modify Trainer Details.\n";
			cout << "3. Do you want to Delete a Trainer.\n";
			cout << "\nPlease enter your command: ";
			cin >> B;

			if (B == 1)
			{
				int ID = {};
				char name[40] = {};
				cout << "Enter ID: ";
				cin >> ID;
				cin.ignore();
				cout << "Enter Name: ";
				cin.get(name, sizeof(name));
				if (addTrainer(ID, name))
				{
					checkT = true;
				}
			}
			else if (B == 2)
			{
				modifyTrainer();
			}
			else if (B == 3)
			{
				deleteTrainer();
				if (noOfTrainers == 0)
				{
					checkT = {};
				}
			}
			else
			{
				cout << "\nInvalid Command.\n";
			}
		}

		else if (mainchoice == 3)
		{
			int C = {};
			cout << "\n1. Do you want to Add New Customer.\n";
			cout << "2. Do you want to Modify Customer Details.\n";
			cout << "3. Do you want to Delete a Customer.\n";

			cout << "\nPlease enter your command: ";
			cin >> C;

			if (C == 1)
			{
				int ID = {};
				char name[40] = {};
				char address[70] = {};
				char phone[15] = {};
				char email[20] = {};

				cout << "Enter ID: ";
				cin >> ID;
				cin.ignore();
				cout << "Enter Name: ";
				cin.get(name, sizeof(name));
				cin.ignore();
				cout << "Enter Address: ";
				cin.get(address, sizeof(address));
				cin.ignore();
				cout << "Enter Phone: ";
				cin.get(phone, sizeof(phone));
				cin.ignore();
				cout << "Enter Email: ";
				cin.get(email, sizeof(email));

				if (addCustomer(ID, name, address, phone, email))
				{
					checkC = true;
				}
			}
			else if (C == 2)
			{
				modifyCustomer();
			}
			else if (C == 3)
			{
				deleteCustomer();
				if (noOfCustomers == 0)
				{
					checkC = {};
				}
			}
			else
			{
				cout << "\nInvalid Command.\n";
			}
		}

		else if (mainchoice == 4)
		{
			int D = {};
			cout << "\n1. Do you want to Add New Exercise Plan.\n";
			cout << "2. Do you want to Modify Exercise Plan.\n";
			cout << "3. Do you want to Delete a Exercise Plan.\n";

			cout << "\nPlease enter your command: ";
			cin >> D;

			if (D == 1)
			{
				if (noOfEquipments == 0)
				{
					checkE = {};
				}
				if (noOfTrainers == 0)
				{
					checkT = {};
				}
				if (noOfCustomers == 0)
				{
					checkC = {};
				}

				if ((checkE == true) && (checkT == true) && (checkC == true))
				{
					int ID;
					int equipmentID = {};
					int trainerID = {};
					int durations = {};

					cout << "Enter ID: ";
					cin >> ID;

					bool statusE = false;

					while (statusE != true)
					{
						cout << "Enter Equipment ID: ";
						cin >> equipmentID;
						for (int i = 0; i < noOfEquipments; ++i)
						{
							if (this->equipments[i].getEquipmentID() == equipmentID)
							{
								statusE = true;
								break;
							}
						}
						if (!statusE)
						{
							cout << "\nNo Equipment with the entered ID exists.\n";
							cout << "Try Again.\n";
						}
					}

					bool statusT = false;

					while (statusT != true)
					{
						cout << "Enter Trainer ID: ";
						cin >> trainerID;

						for (int i = 0; i < noOfTrainers; ++i)
						{
							if (this->trainers[i].getTrainerID() == trainerID)
							{
								statusT = true;
								break;
							}
						}
						if (!statusT)
						{
							cout << "\nNo Trainer with the entered ID exists.\n";
							cout << "Try Again.\n";
						}
					}

					while (durations < 1)
					{
						cout << "Enter Durations: ";
						cin >> durations;
						if (durations <= 0)
						{
							cout << "\nPlease Enter A Valid Value: ";
						}
					}

					if (addExercisePlan(ID, equipmentID, trainerID, durations))
					{
						checkEP = true;
					}
				}
				else
				{
					if (!checkE)
					{
						cout << "No Equipment Added Yet.\n";
					}
					if (!checkT)
					{
						cout << "No Trainer Added Yet.\n";
					}
					if (!checkC)
					{
						cout << "No Customer Added Yet.\n";
					}
				}
			}
			else if (D == 2)
			{
				modifyExercisePlan();
			}
			else if (D == 3)
			{
				deleteExercisePlan();
				if (noOfExercisePlans == 0)
				{
					checkEP = {};
				}
			}
		}

		else if (mainchoice == 5)
		{
			int E = {};
			cout << "\n1. Do you want to Add New Subscription.\n";
			cout << "2. Do you want to Modify Subscription.\n";
			cout << "3. Do you want to Delete a Subscription.\n";

			cout << "\nPlease enter your command: ";
			cin >> E;

			if (E == 1)
			{
				int ID = {};
				Date A;
				int customerID = {};
				int PlanID = {};
				if ((checkC == true) && (checkEP == true))
				{
					cout << "Enter ID: ";
					cin >> ID;

					cout << "<Date>\n";
					int day = {};
					int month = {};
					int year = {};

					cout << "Enter Day<1-31>: ";
					cin >> day;

					cout << "Enter Month<1-12>: ";
					cin >> month;

					cout << "Enter Year<1900-3000>: ";
					cin >> year;

					A.setDay(day);
					A.setMonth(month);
					A.setYear(year);

					bool statusC = {};

					while (statusC != true)
					{
						cout << "Enter Customer ID: ";
						cin >> customerID;

						for (int i = 0; i < noOfCustomers; ++i)
						{
							if (this->customers[i].getCustomerID() == customerID)
							{
								statusC = true;
								break;
							}
						}
						if (!statusC)
						{
							cout << "\nNo Customer Exist With Given ID.\n";
							cout << "Try Again.\n";
						}
					}

					bool statusEP = {};

					while (statusEP != true)
					{
						cout << "Enter Exercise Plan ID: ";
						cin >> PlanID;

						for (int i = 0; i < noOfExercisePlans; ++i)
						{
							if (this->exercisePlans[i].getPlanID() == customerID)
							{
								statusEP = true;
								break;
							}
						}
						if (!statusEP)
						{
							cout << "\nNo Exercise Plan Exist With Given ID.\n";
							cout << "Try Again.\n";
						}
					}

					addSubscription(ID, A, customerID, PlanID);
				}
				else
				{
					cout << endl;
					if (!checkC)
					{
						cout << "No Customer Available.\n";
					}
					if (!checkEP)
					{
						cout << "No Exercise Plan Available Yet.\n";
					}
					cout << endl;
				}
			}
			else if (E == 2)
			{
				modifySubscription();
			}
			else if (E == 3)
			{
				deleteSubscription();
			}
			else
			{
				cout << "Invalid Command.\n";
			}
		}

		else if (mainchoice == 6)
		{
			display();
		}

		else if (mainchoice == 0)
		{
			cout << "Thank you for Using Gym Services.\n";
		}

		else
		{
			cout << "\nWrong Input.\n";
			cout << "Try Again.\n\n";
		}
	}
}

void Gym::display() const
{
	cout << "\nGym ID: " << gymID << endl;

	cout << "\nNo of Equipments: " << noOfEquipments << endl;
	if (noOfEquipments == 0)
	{
		cout << "No Equipment Details Available.\n";
	}
	else
	{
		for (int i = 0; i < noOfEquipments; ++i)
		{
			cout << "Equipment No " << i + 1 << ": <>\n";
			this->equipments[i].display();
			cout << endl;
		}
	}

	cout << "\nNo of Trainers: " << noOfTrainers << endl;
	if (noOfTrainers == 0)
	{
		cout << "No Trainer Details Available.\n";
	}
	else
	{
		for (int i = 0; i < noOfTrainers; ++i)
		{
			cout << "Trainer No " << i + 1 << ": <>\n";
			this->trainers[i].display();
			cout << endl;
		}
	}

	cout << "\nNo of Customers:" << noOfCustomers << endl;
	if (noOfCustomers == 0)
	{
		cout << "No Customer Details Available.\n";
	}
	else
	{
		for (int i = 0; i < noOfCustomers; ++i)
		{
			cout << "Customer No " << i + 1 << ": <>\n";
			this->customers[i].display();
			cout << endl;
		}
	}

	cout << "\nNo of Exercise Plans: " << noOfExercisePlans << endl;
	if (noOfExercisePlans == 0)
	{
		cout << "\nNo Exercise Plans Details Available.\n";
	}
	else
	{
		for (int i = 0; i < noOfExercisePlans; ++i)
		{
			cout << "Exercise Plan No " << i + 1 << ": <>\n";
			this->exercisePlans[i].display();
			cout << endl;
		}
	}

	cout << "\nNo of Subscriptions: " << noOfSubscriptions << endl;
	if (noOfSubscriptions == 0)
	{
		cout << "No Subscription Details Available.\n";
	}
	else
	{
		for (int i = 0; i < noOfSubscriptions; ++i)
		{
			cout << "Subscription No " << i + 1 << ": <>\n";
			this->subscriptions[i].display();
			cout << endl;
		}
	}
	cout << endl;
}