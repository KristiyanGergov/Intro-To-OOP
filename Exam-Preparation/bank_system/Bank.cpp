#include "Bank.h"

Bank::Bank()
{
	setName("undefined");
	setAddress("undefined");
}

Bank::~Bank()
{
	delete[] this->address;
	delete[] this->name;
}

Bank::Bank(const char * name, const char * address)
{
	this->setAddress(address);
	this->setName(name);
}

char * Bank::getName() const
{
	return this->name;
}

char * Bank::getAddress() const
{
	return this->address;
}

bool Bank::addCustomer(unsigned int customerId, const char * name, const char * address)
{
	if (indexOfCustomer(customerId) != -1)
	{
		cout << "Can't add existing customer!" << endl;
		return false;
	}
	Customer* customer = new Customer(customerId, name, address);
	customers.push_back(customer);
}

void Bank::listCustomers() const
{
	for (size_t i = 0; i < customers.size(); i++)
		customers[i]->display();
}

bool Bank::deleteCustomer(unsigned int customerId)
{
	int index = indexOfCustomer(customerId);
	if (index == -1)
	{
		cout << "Customer does not exist" << endl;
		return false;
	}
	customers.erase(customers.begin() + index);
	return true;
}

void Bank::addAccount(AccountType type, const char * iban, unsigned int ownerId, double amount)
{
	if (indexOfCustomer(ownerId) == -1 || indexOfAccount(iban) != -1)
	{
		cout << "Customer does not exist or same account already exist!" << endl;
		return;
	}
	Account* account;
	switch (type)
	{
	case Current:
		account = new CurrentAccount(ownerId, iban, amount);
		break;
	case Privilege:
		cout << "Enter overdraft: " << endl;
		double overdraft;
		cin >> overdraft;
		account = new PrivilegeAccount(ownerId, iban, amount, overdraft);
		break;
	case Savings:
		cout << "Interest rate: " << endl;
		double interestRate;
		cin >> interestRate;
		account = new SavingsAccount(ownerId, iban, amount, interestRate);
		break;
	default:
		break;
	}
	this->accounts.push_back(account);
}

bool Bank::deleteAccount(const char * iban)
{
	int index = indexOfAccount(iban);
	if (index == -1)
	{
		cout << "Account does not exist" << endl;
		return false;
	};
	accounts.erase(accounts.begin() + index);
	return true;
}

void Bank::listAccounts() const
{
	for (size_t i = 0; i < accounts.size(); i++)
		accounts[i]->display();
}

void Bank::listCustomerAccount(unsigned int customerId) const
{
	cout << "Customer: " << customerId << endl;
	for (size_t i = 0; i < accounts.size(); i++)
		if (accounts[i]->getOwnerId() == customerId)
			accounts[i]->display();
}

bool Bank::transfer(const char * fromIBAN, const char * toIBAN, double amount)
{
	int from = indexOfAccount(fromIBAN);
	int to = indexOfAccount(toIBAN);
	if (from != -1 && to != -1 && accounts[from]->withdraw(amount))
	{
		accounts[to]->deposit(amount);
		return true;
	}
	return false;
}

void Bank::display() const
{
	cout << "Bank: " << this->name << endl;
	cout << "Address: " << this->address << endl;
	cout << "Accounts number: " << this->accounts.size() << endl;
	cout << "Customers number: " << this->customers.size() << endl;
}

int Bank::indexOfCustomer(unsigned int id)
{
	for (size_t i = 0; i < customers.size(); i++)
		if (customers[i]->getId() == id)
			return i;
	return -1;
}

int Bank::indexOfAccount(const char * iban)
{
	for (size_t i = 0; i < accounts.size(); i++)
		if (strcmp(accounts[i]->getIban(), iban) == 0)
			return i;
	return -1;
}

void Bank::setName(const char * name)
{
	if (this->name)
	{
		delete[] this->name;
		this->name = nullptr;
	}
	if (name)
	{
		int size = strlen(name) + 1;
		this->name = new char[size];
		memcpy(this->name, name, size);
	}
}

void Bank::setAddress(const char * address)
{
	if (this->address)
	{
		delete[] this->address;
		this->address = nullptr;
	}
	if (address)
	{
		int size = strlen(address) + 1;
		this->address = new char[size];
		memcpy(this->address, address, size);
	}
}
