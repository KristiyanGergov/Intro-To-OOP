#include "Set.h"

template<typename T>
Set<T> intersectionOf(const Set<T> a, const Set<T> b) {
	Set<T> result = Set<T>(a.getSize() + b.getSize());

	const T *first = a.asArray();

	for (size_t i = 0; i < a.getSize(); i++) {
		if (b.contains(first[i])) {
			result.add(first[i]);
		}
	}

	return result;
}


template <typename T>
Set<T> unionOf(const Set<T> a, const Set<T> b) {
	Set<T> result = Set<T>(a.getCapacity() + b.getCapacity());

	const T* first = a.asArray();
	const T* second = b.asArray();

	for (size_t i = 0; i < a.getSize(); i++)
		result.add(first[i]);
	for (size_t i = 0; i < b.getSize(); i++)
		result.add(second[i]);
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

	Set<int> set3 = Set<int>();
	Set<int> set4 = Set<int>();
	set3.add(1);
	set4.add(4);

	Set<int> set5 = unionOf(set3, set4);
	Set<int> result = unionOf(set3, set4);

	result.print();

	return 0;
}