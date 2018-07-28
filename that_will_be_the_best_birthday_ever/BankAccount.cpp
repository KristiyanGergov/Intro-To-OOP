#include "BankAccount.h"
#include "cstring"
#include <iostream>

using namespace std;

BankAccount::BankAccount()
{
	this->balance = 0;
}

BankAccount::BankAccount(const char * holderName, int id, double balance)
{
	strcpy(this->holderName, holderName);
	this->id = id;
	this->balance = balance;
}

const char * BankAccount::getHolderName() const
{
	return this->holderName;
}

void BankAccount::setHolderName(const char* holderName)
{
	strcpy(this->holderName, holderName);
}

int BankAccount::getId() const
{
	return this->id;
}

void BankAccount::setId(int id)
{
	this->id = id;
}

double BankAccount::getBalance() const
{
	return this->balance;
}

void BankAccount::setBalance(double balance)
{
	this->balance = balance;
}

void BankAccount::withdraw(double value)
{
	this->balance -= value;
}

void BankAccount::deposit(double value)
{
	this->balance += value;
}

void BankAccount::initialize()
{
	this->setBalance(0);
}

void BankAccount::print() const
{
	cout << "Balance: " << getBalance() << endl;
	cout << "Id: " << getId() << endl;
	cout << "Holder name: " << getHolderName() << endl;
}