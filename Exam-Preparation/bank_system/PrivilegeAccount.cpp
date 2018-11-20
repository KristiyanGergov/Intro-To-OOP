#include "PrivilegeAccount.h"

PrivilegeAccount::PrivilegeAccount(unsigned int ownerId, const char * iban, double amount, double overdraft)
	: Account(ownerId, iban, amount)
{
	this->overdraft = overdraft;
}

double PrivilegeAccount::getOverdraft() const
{
	return overdraft;
}

void PrivilegeAccount::deposit(double amount)
{
	Account::deposit(amount);
}

bool PrivilegeAccount::withdraw(double amount)
{
	return Account::withdraw(amount);
}

void PrivilegeAccount::display() const
{
}

unsigned int PrivilegeAccount::getOwnerId() const
{
	return Account::getOwnerId();

}

char * PrivilegeAccount::getIban() const
{
	return Account::getIban();
}

Account * PrivilegeAccount::newInstanceOf() const
{
	return new PrivilegeAccount(*this);
}