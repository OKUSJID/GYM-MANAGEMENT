#include "Equipment.h"

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