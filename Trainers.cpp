#include "Trainers.h"

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