#include "Subscriptions.h"

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
	cout << "Subscription ID: "<< subscriptionID <<endl;
	cout << "Date: ";
	date.display();
	cout << "Customer ID: "<< customerID <<endl;
	cout << "Plan ID: "<< planID <<endl;
}