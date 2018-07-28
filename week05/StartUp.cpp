#include "PhonebookRecord.h"
#include <iostream>
#include <cstring>
#include "Phonebook.h"

using namespace std;

int main() {
	PhonebookRecord ph = PhonebookRecord("first", "8882", PhoneType::personal);
	PhonebookRecord ph2 = PhonebookRecord("first", "8882", PhoneType::personal);
	PhoneType t = personal;
	PhoneType t2 = personal;

	Phonebook phonebook = Phonebook(5, 6, ph);
	return 0;
}