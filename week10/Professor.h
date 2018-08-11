#pragma once
#include "Person.h"

class Professor : public Person
{
public:
	Professor();

	~Professor() override;

	Professor(const char* name, const unsigned int age, const unsigned int papers);

	Professor(const Professor&);

	Professor &operator=(const Professor&);

	void greet() const override;

	unsigned int getPapers() const;

	void setPapers(unsigned int papers);

	friend std::ostream &operator<<(std::ostream &, const Professor &);
private:
	unsigned int papers;
};

