#include "Account.h"

Account::Account()
{
	setIban("undentified");
}

Account::~Account()
{
	cout << "account called" << endl;
	delete[] iban;
}

Account::Account(unsigned int ownerId, const char * iban, double amount)
{
	this->ownerId = ownerId;
	setIban(iban);
	this->amount = amount;
}

void Account::display() const
{
	cout << "Owner id: " << this->ownerId << endl;
	cout << "IBAN: " << this->iban << endl;
	cout << "Amount: " << this->amount << endl << endl;
}

double Account::getBalance()
{
	return this->amount;
}

unsigned int Account::getOwnerId() const
{
	return this->ownerId;
}

char * Account::getIban() const
{
	return this->iban;
}

void Account::deposit(double amount)
{
	this->amount += amount;
}

bool Account::withdraw(double amount)
{
	if (this->amount >= amount)
	{
		this->amount -= amount;
		return true;
	}
	return false;
}

void Account::setIban(const char* iban)
{
	if (this->iban)
	{
		delete[] this->iban;
		this->iban = nullptr;
	}

	if (iban)
	{
		int size = strlen(iban) + 1;
		this->iban = new char[size];
		memcpy(this->iban, iban, size);
	}
}