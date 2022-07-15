#include "Customers.h"

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
