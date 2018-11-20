#pragma once
#include "Account.h"

class CurrentAccount : public Account
{
public:
	~CurrentAccount();

	CurrentAccount(unsigned int ownerId, const char* iban, double amount);

	void deposit(double amount) override;
	bool withdraw(double amount) override;
	void display() const override;

	
	char* getIban() const override;
	unsigned int getOwnerId() const override;

protected:
	Account * newInstanceOf() const override;
};