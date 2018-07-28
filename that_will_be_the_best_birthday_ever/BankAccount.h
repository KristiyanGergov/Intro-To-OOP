#pragma once
class BankAccount
{
public:
	BankAccount();
	BankAccount(const char*, int, double);
	const char* getHolderName() const;
	void setHolderName(const char*);
	int getId() const;
	void setId(int);
	double getBalance() const;
	void setBalance(double);
	void withdraw(double);
	void deposit(double);
	void initialize();
	void print() const;
private:
	char holderName[50];
	int id;
	double balance;
};