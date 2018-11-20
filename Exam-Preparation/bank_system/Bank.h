#include <vector>
#include <iostream>
#include "Customer.h"
#include "Account.h"
#include "CurrentAccount.h"
#include "PrivilegeAccount.h"
#include "SavingsAccount.h"

using namespace std;

#pragma once
class Bank
{
public:
	Bank();
	~Bank();

	Bank(const char* name, const char* address);

	char* getName() const;

	char* getAddress() const;

	bool addCustomer(unsigned int customerId, const char* name, const char* address);

	void listCustomers() const;

	bool deleteCustomer(unsigned int customerId);

	void addAccount(AccountType type, const char* iban, unsigned int ownerId, double amount);

	bool deleteAccount(const char* iban);

	void listAccounts() const;

	void listCustomerAccount(unsigned int customerId) const;

	bool transfer(const char* fromIBAN, const char* toIBAN, double amount);

	void display() const;

private:
	char* name = nullptr;
	char* address = nullptr;
	vector<Customer*> customers;
	vector<Account*> accounts;

	int indexOfCustomer(unsigned int id);
	int indexOfAccount(const char* iban);


	void setName(const char* name);
	void setAddress(const char* address);
};