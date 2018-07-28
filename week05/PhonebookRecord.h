#pragma once
using namespace std;
#include <ostream>

enum PhoneType {
	home,
	personal,
	work
};

class PhonebookRecord
{
public:
	PhonebookRecord() = default;
	PhonebookRecord(const char* name, const char* phoneNumber, const PhoneType phoneType);
	PhonebookRecord(const PhonebookRecord &);
	PhonebookRecord &operator=(const PhonebookRecord&);
	friend ostream &operator<<(ostream &os, const PhonebookRecord &record);
	friend bool operator==(const PhonebookRecord&, const PhonebookRecord &);
	friend bool operator<(const PhonebookRecord&, const PhonebookRecord &);
	const char* getName();
private:
	char name[50];
	char phoneNumber[10];
	PhoneType phoneType;
};