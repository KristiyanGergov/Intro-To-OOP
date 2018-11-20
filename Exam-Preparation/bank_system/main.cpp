#include "SavingsAccount.h"
#include "Account.h"
#include "CurrentAccount.h"
#include "PrivilegeAccount.h"
#include "Bank.h"

int main() {
	Bank* bank = new Bank("OBB", "Sofia");

	Account* acc = new SavingsAccount(1, "iban", 500, 5.1);

	bank->addCustomer(1, "tosho", "Sofia zapad");
	bank->addCustomer(2, "gosho", "Sofia sever");
	bank->addCustomer(3, "pesho", "Sofia iug");

	bank->listCustomers();

	bank->addAccount(AccountType::Current, "hard-iban", 1, 500);
	bank->addAccount(AccountType::Privilege, "easy-iban", 2, 2500);
	bank->addAccount(AccountType::Savings, "medium-iban", 3, 1500);

	bank->transfer("hard-iban", "easy-iban", 500);

	bank->listAccounts();


	return 0;
}