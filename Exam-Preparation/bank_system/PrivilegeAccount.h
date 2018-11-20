#include "Account.h"

#pragma once
class  PrivilegeAccount : public Account
{
public:
	PrivilegeAccount(unsigned int ownerId, const  char* iban, double amount, double overdraft);

	double getOverdraft() const;

	void deposit(double amount) override;
	bool withdraw(double amount) override;

	void display() const override;

	unsigned int getOwnerId() const override;
	char* getIban() const override;

protected:
	Account* newInstanceOf() const override;

private:
	double overdraft;
};