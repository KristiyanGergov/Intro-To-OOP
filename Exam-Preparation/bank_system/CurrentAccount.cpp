#include "CurrentAccount.h"

CurrentAccount::~CurrentAccount()
{
	delete[] this->iban;
}

CurrentAccount::CurrentAccount(unsigned int ownerId, const char * iban, double amount)
	: Account(ownerId, iban, amount)
{
}

void CurrentAccount::deposit(double amount)
{
	Account::deposit(amount);
}

bool CurrentAccount::withdraw(double amount)
{
	return Account::withdraw(amount);
}

void CurrentAccount::display() const
{
	cout << "Account type: Current" << endl;
	Account::display();
}

char * CurrentAccount::getIban() const
{
	return Account::getIban();
}

unsigned int CurrentAccount::getOwnerId() const
{
	return Account::getOwnerId();
}

Account * CurrentAccount::newInstanceOf() const
{
	return new CurrentAccount(*this);
}