#include "NumSum.h"

NumSum::NumSum()
{
	this->currentSum = 0;
	this->currentChanges = 0;
}

NumSum::NumSum(unsigned int sum) :
	currentSum(sum), currentChanges(1) {}


NumSum::NumSum(const NumSum & other)
{
	this->currentSum = other.currentSum;
	this->currentChanges = other.currentChanges;
}

void NumSum::add(unsigned int value)
{
	this->currentSum += value;
	this->currentChanges++;
}

void NumSum::sub(unsigned int value)
{
	this->currentSum -= value;
	this->currentChanges++;
}

unsigned int NumSum::sum() const
{
	return currentSum;
}

unsigned int NumSum::changes() const
{
	return this->currentChanges;
}

double NumSum::average() const
{
	if (currentChanges == 0)
		return 0;
	
	return ((double)currentSum) / currentChanges;
}
