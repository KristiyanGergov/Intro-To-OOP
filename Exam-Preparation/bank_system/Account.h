#include <iostream>
#include <cstring>

using namespace std;

#pragma once
class Account
{
public:
	Account();
	virtual ~Account();
	Account(unsigned int ownerId, const char* iban, double amount);

	virtual void deposit(double amount) = 0;
	virtual bool withdraw(double amount) = 0;

	virtual void display() const = 0;
	virtual double getBalance();
	virtual unsigned int getOwnerId() const = 0;
	virtual char* getIban() const = 0;

protected:
	virtual Account* newInstanceOf() const = 0;

	unsigned int ownerId;
	char* iban = nullptr;
	double amount;
	void setIban(const char* iban);
};

enum AccountType {
	Current,
	Privilege,
	Savings
};