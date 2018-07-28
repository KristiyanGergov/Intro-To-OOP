#include "BankAccount.h"
#include <iostream>

using namespace std;

BankAccount merge(const BankAccount &first, const BankAccount &second) {
	BankAccount merged = BankAccount();
	merged.setBalance(first.getBalance() + second.getBalance());
	merged.setHolderName(first.getHolderName());
	merged.setId(first.getId());
	return merged;
}
void getMax(BankAccount arr[]) {
	for (size_t i = 0; i < sizeof(arr); i++)
	{

	}
}
int maxIndex(const BankAccount *accountArr, int len) {
	double currentMax = accountArr[0].getBalance();
	int currentMaxIdx = 0;

	for (int i = 1; i < len; i++) {
		double currentBalance = accountArr[i].getBalance();

		if (currentBalance > currentMax) {
			currentMaxIdx = i;
			currentMax = currentBalance;
		}
	}

	return currentMaxIdx;
}

int main() {
	BankAccount account = BankAccount("test", 5, 10);
	BankAccount account2 = BankAccount("test2", 3, 20);
	BankAccount account3 = merge(account, account2);
	account3.print();
	return 0;
}