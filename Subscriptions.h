#include "Date.h"
#pragma once

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