#include "Account.h"

#pragma once
class SavingsAccount : public Account
{
public:
	SavingsAccount(unsigned int ownerId, const  char* iban, double amount, double interestRate);
	double getInterestRate() const;

	void deposit(double amount) override;
	bool withdraw(double amount) override;
	void display() const override;

	unsigned int getOwnerId() const override;
	char* getIban() const override;


protected:
	Account * newInstanceOf() const override;

private:
	double interestRate;
};