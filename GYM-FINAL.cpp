#include<iostream>
#include<fstream>
using namespace std;

//                        DATE
class Date
{
private:
	int day;
	int month;
	int year;
public:
	Date();
	Date(const int&, const int&, const int&);
	void setDay(const int&);
	int getDay()const;
	void setMonth(const int&);
	int getMonth()const;
	void setYear(const int&);
	int getYear()const;
	void display()const;
};
Date::Date()
{
	day = {};
	month = {};
	year = {};
}

Date::Date(const int& day, const int& month, const int& year)
{
	setDay(day);
	setMonth(month);
	setYear(year);
}

void Date::setDay(const int& day)
{
	if (day >= 1 && day <= 31)
	{
		this->day = day;
	}
	else
	{
		this->day = {};
	}
}

int Date::getDay() const
{
	return this->day;
}

void Date::setMonth(const int& month)
{
	if (month >= 1 && month <= 12)
	{
		this->month = month;
	}
	else
	{
		this->month = {};
	}
}

int Date::getMonth() const
{
	return this->month;
}

void Date::setYear(const int& year)
{
	if (year >= 1900 && year <= 3000)
	{
		this->year = year;
	}
	else
	{
		this->year = {};
	}
}

int Date::getYear() const
{
	return this->year;
}

void Date::display() const
{
	cout << this->day << " / " << this->month << " / " << this->year << endl;
}
//------------------------------------------------------------------------------------------


//                         CUSTOMER
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
char* copyCustomerString(const char* oldptr)
{
	int size = strlen(oldptr);
	char* ptr = new char[size + 1];
	for (int i = 0; i < size; ++i)
	{
		ptr[i] = oldptr[i];
	}
	ptr[size] = '\0';
	return ptr;
}

Customers::Customers()
{
	customerID = {};
	name = nullptr;
	address = nullptr;
	phone = nullptr;
	email = nullptr;

	
}


Customers::Customers(const int& customerID, const char* name, const char* address, const char* phone, const char* email)
{
	setCustomerID(customerID);
	setName(name);
	setAddress(address);
	setPhone(phone);
	setEmail(email);
}

Customers::Customers(const Customers& obj)
{
	setCustomerID(obj.customerID);
	setName(obj.name);
	setAddress(obj.address);
	setPhone(obj.phone);
	setEmail(obj.email);
}

Customers::~Customers()
{
	if (this->name != nullptr)
	{
		delete[] this->name;
		this->name = nullptr;
	}
	if (this->address != nullptr)
	{
		delete[] this->address;
		this->address = nullptr;
	}
	if (this->phone != nullptr)
	{
		delete[] this->phone;
		this->phone = nullptr;
	}
	if (this->email != nullptr)
	{
		delete[] this->email;
		this->email = nullptr;
	}
}

void Customers::setCustomerID(const int& customerID)
{
	if (customerID >= 0)
	{
		this->customerID = customerID;
	}
}

int Customers::getCustomerID() const
{
	return this->customerID;
}

void Customers::setName(const char* name)
{
	if (name != nullptr)
	{
		if (this->name != nullptr)
		{
			delete[] this->name;
			this->name = nullptr;
		}
		this->name = copyCustomerString(name);
	}
	else
	{
		this->name = nullptr;
	}
}

char* Customers::getName() const
{
	if (name != nullptr)
	{
		return copyCustomerString(name);
	}
	return nullptr;
}

void Customers::setAddress(const char* address)
{
	if (address != nullptr)
	{
		if (this->address != nullptr)
		{
			delete[] this->address;
			this->address = nullptr;
		}
		this->address = copyCustomerString(address);
	}
	else
	{
		this->address = nullptr;
	}
}


char* Customers::getAddress() const
{
	if (address != nullptr)
	{
		return copyCustomerString(address);
	}
	return nullptr;
}

void Customers::setPhone(const char* phone)
{
	if (phone != nullptr)
	{
		if (this->phone != nullptr)
		{
			delete[] this->phone;
			this->phone = nullptr;
		}
		this->phone = copyCustomerString(phone);
	}
	else
	{
		this->phone = nullptr;
	}
}

char* Customers::getPhone() const
{
	if (phone != nullptr)
	{
		return copyCustomerString(phone);
	}
	return nullptr;
}

void Customers::setEmail(const char* email)
{
	if (email != nullptr)
	{
		if (this->email != nullptr)
		{
			delete[] this->email;
			this->email = nullptr;
		}
		this->email = copyCustomerString(email);
	}
	else
	{
		this->email = nullptr;
	}
}

char* Customers::getEmail() const
{
	if (email != nullptr)
	{
		return copyCustomerString(email);
	}
	return nullptr;
}

void Customers::display() const
{
	cout << "Customer ID: " << this->getCustomerID() << endl;
	cout << "Customer Name: " << this->name << endl;
	cout << "Customer Address: " << this->address << endl;
	cout << "Customer Phone: " << this->phone << endl;
	cout << "Customer Email: " << this->email << endl;
}

Customers& Customers::operator=(const Customers& obj)
{
	setCustomerID(obj.customerID);
	setName(obj.name);
	setAddress(obj.address);
	setPhone(obj.phone);
	setEmail(obj.email);
	return *this;
}
//--------------------------------------------------------------------------------------------------

//                               EQUIPMENTS

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

char* copyEquipmentString(const char* oldptr)
{
	int size = strlen(oldptr);
	char* ptr = new char[size + 1];
	for (int i = 0; i < size; ++i)
	{
		ptr[i] = oldptr[i];
	}
	ptr[size] = '\0';
	return ptr;
}

Equipment::Equipment()
{
	equipmentID = {};
	name = nullptr;
}

Equipment::Equipment(const int& equipmentID, const char* name)
{
	setEquipmentID(equipmentID);
	setName(name);
}

Equipment::Equipment(const Equipment& obj)
{
	setEquipmentID(obj.equipmentID);
	setName(obj.name);
}

Equipment::~Equipment()
{
	if (this->name != nullptr)
	{
		delete[] this->name;
		this->name = nullptr;
	}
}

void Equipment::setEquipmentID(const int& equipmentID)
{
	if (equipmentID >= 0)
	{
		this->equipmentID = equipmentID;
	}
	else
	{
		this->equipmentID = {};
	}
}

int Equipment::getEquipmentID() const
{
	return this->equipmentID;
}

void Equipment::setName(const char* name)
{
	if (name != nullptr)
	{
		if (this->name != nullptr)
		{
			delete[] this->name;
			this->name = nullptr;
		}
		this->name = copyEquipmentString(name);
	}
	else
	{
		this->name = nullptr;
	}
}

char* Equipment::getName()const
{
	if (this->name != nullptr)
	{
		return copyEquipmentString(name);
	}
	return nullptr;
}

void Equipment::display() const
{
	cout << "Equipment ID: " << getEquipmentID() << endl;
	cout << "Equipment Name: " << getName() << endl;
}

Equipment& Equipment::operator=(const Equipment& obj)
{
	setEquipmentID(obj.equipmentID);
	setName(obj.name);
	return *this;
}
//-----------------------------------------------------------------------------------------------------

//                                  TRAINER
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


char* copyTrainersString(const char* oldptr)
{
	int size = strlen(oldptr);
	char* ptr = new char[size + 1];
	for (int i = 0; i < size; ++i)
	{
		ptr[i] = oldptr[i];
	}
	ptr[size] = '\0';
	return ptr;
}

Trainers::Trainers()
{
	trainerID = {};
	name = nullptr;
}

Trainers::Trainers(const int& trainerID, const char* name)
{
	setTrainerID(trainerID);
	setName(name);
}

Trainers::Trainers(const Trainers& obj)
{
	setTrainerID(obj.trainerID);
	setName(obj.name);
}

Trainers::~Trainers()
{
	if (this->name != nullptr)
	{
		delete[] this->name;
		this->name = nullptr;
	}
}

void Trainers::setTrainerID(const int& trainerID)
{
	if (trainerID > 0)
	{
		this->trainerID = trainerID;
	}
	else
	{
		this->trainerID = {};
	}
}

int Trainers::getTrainerID() const
{
	return this->trainerID;
}

void Trainers::setName(const char* name)
{
	if (name != nullptr)
	{
		if (this->name != nullptr)
		{
			delete[] this->name;
			this->name = nullptr;
		}
		this->name = copyTrainersString(name);
	}
	else
	{
		this->name = nullptr;
	}
}

char* Trainers::getName()const
{
	if (this->name != nullptr)
	{
		return copyTrainersString(name);
	}
	return nullptr;
}

void Trainers::display() const
{
	cout << "Trainers ID: " << getTrainerID() << endl;
	cout << "Trainers Name: " << getName() << endl;
}

Trainers& Trainers::operator=(const Trainers& obj)
{
	setTrainerID(obj.trainerID);
	setName(obj.name);
	return *this;
}
//-----------------------------------------------------------------------------------------------
//                                           SUBSCRIPTIONS
class Subscriptions
{
private:
	int subscriptionID;
	Date date;
	int customerID;
	int planID;
public:
	Subscriptions();
	Subscriptions(const int&, const Date&, const int&, const int&);
	void setSubscriptionID(const int&);
	int getSubscriptionID()const;
	void setDate(const Date&);
	Date getDate()const;
	void setCustomerID(const int&);
	int getCustomerID()const;
	void setPlanID(const int&);
	int getPlanID()const;
	void display()const;
};
Subscriptions::Subscriptions() :date()
{
	subscriptionID = {};
	customerID = {};
	planID = {};
}

Subscriptions::Subscriptions(const int& subscriptionID, const Date& date, const int& customerID, const int& planID)
{
	setSubscriptionID(subscriptionID);
	setDate(date);
	setCustomerID(customerID);
	setPlanID(planID);
}

void Subscriptions::setSubscriptionID(const int& subscriptionID)
{
	if (subscriptionID >= 0)
	{
		this->subscriptionID = subscriptionID;
	}
	else
	{
		this->subscriptionID = {};
	}
}

int Subscriptions::getSubscriptionID() const
{
	return this->subscriptionID;
}

void Subscriptions::setDate(const Date& date)
{
	this->date = date;
}

Date Subscriptions::getDate() const
{
	return this->date;
}

void Subscriptions::setCustomerID(const int& customerID)
{
	if (customerID >= 0)
	{
		this->customerID = customerID;
	}
	else
	{
		this->customerID = {};
	}
}

int Subscriptions::getCustomerID() const
{
	return this->customerID;
}

void Subscriptions::setPlanID(const int& planID)
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

int Subscriptions::getPlanID() const
{
	return this->planID;
}

void Subscriptions::display() const
{
	cout << "Subscription ID: " << subscriptionID << endl;
	cout << "Date: ";
	date.display();
	cout << "Customer ID: " << customerID << endl;
	cout << "Plan ID: " << planID << endl;
}
//------------------------------------------------------------------------------------------

//                               EXERSICE PLANS
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
	if (equipmentID >= 0)
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
	if (durations >= 0)
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
	cout << "Durations: " << durations << endl;
}
//------------------------------------------------------------------------------------------------
//                              GYM
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
		++noOfSubscriptions; \

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
//---------------------------------------------------------------------------------------------------------


//j





int main(void)
{
	Gym A;
	Gym B;
	A.setGymID(1);
	A.Menu();
	return 0;
}