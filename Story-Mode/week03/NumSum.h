#pragma once
class NumSum
{
public:
	NumSum();
	NumSum(unsigned int);
	NumSum(const NumSum &);
	NumSum &operator=(const NumSum &) = delete;
	void add(unsigned int);
	void sub(unsigned int);
	unsigned int sum() const;
	unsigned int changes() const;
	double average() const;
private:
	unsigned int currentSum;
	unsigned int currentChanges;
};