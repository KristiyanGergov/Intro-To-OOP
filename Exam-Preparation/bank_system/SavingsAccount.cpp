#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(unsigned int ownerId, const char * iban, double amount, double interestRate)
	: Account(ownerId, iban, amount)
{
	this->interestRate = interestRate;
}

double SavingsAccount::getInterestRate() const
{
	return this->interestRate;
}

void SavingsAccount::deposit(double amount)
{
	Account::deposit(amount);
}

bool SavingsAccount::withdraw(double amount)
{
	return Account::withdraw(amount);
}

void SavingsAccount::display() const
{
	cout << "Account type: Savings" << endl;
	cout << "Interest rate: " << interestRate << endl;
	Account::display();
}

unsigned int SavingsAccount::getOwnerId() const
{
	return Account::getOwnerId();

}

char * SavingsAccount::getIban() const
{
	return Account::getIban();
}

Account * SavingsAccount::newInstanceOf() const
{
	return new SavingsAccount(*this);
}