#include "Set.h"

template <typename T>
Set<T> unionOf(const Set<T>& first, const Set<T>& second) {
	Set<T> result = new Set<T>(first.getCapacity() + second.getCapacity());

	result.getSize() = first.getSize() + second.getSize();

	for (size_t i = 0; i < first.getSize(); i++)
	{
		result.arr[i] = first[i];
	}

	for (size_t i = first.getSize() + second.getSize(); i < result.getSize(); i++)
	{
		result.arr[i] = second[i];
	}

	return result;
}

int main() {

	Set<const char*> set = Set<const char*>();
	Set<const char*> set2 = Set<const char*>();
	set.add("first");
	set.add("second");
	set.add("third");

	set2.add("first2");
	set2.add("second2");
	set2.add("third2");

	//Set<const char*> result = unionOf(set, set2);

	set.print();

	return 0;
}