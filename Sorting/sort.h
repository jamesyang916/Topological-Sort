#pragma once
#include <iostream>
#include <iterator>
#include <vector>

class Sort {
private:
	template <class Iter>
	static void merge(Iter begin, Iter mid, Iter end);
public:
	Sort(); 
	~Sort();
	
	template <class Iter>
	static void insertion(Iter begin, Iter end);

	template <class Iter>
	static void selection(Iter begin, Iter end);

	template <class Iter>
	static void merge(Iter begin, Iter end, const int size);

	template <class Iter>
	static void print(Iter begin, Iter end, bool increasing = true);

	template <class T>
	static void topological();
};



Sort::Sort() {}
Sort::~Sort() {}

template <class Iter>
void Sort::insertion (Iter begin, Iter end) {
	for (Iter it = begin + 1; it < end; ++it) {
		auto key = *it;
		Iter it2 = it - 1;
		int t = 1;
		while (it2 >= begin && *it2 > key) {
			*(it2 + 1) = *it2;
			if (it2 > begin) {
				--it2;
				t = 1;
			}
			else {
				t = 0;
				break;
			}
		}
		*(it2 + t) = key;
	}
}

template <class Iter>
void Sort::selection(Iter begin, Iter end) {
	for (Iter it = begin; it < end - 1; ++it) {
		Iter min = it;
		for (Iter it2 = it + 1;  it2 < end; ++it2) {
			min = *it2 < *min ? it2 : min;
		}

		// Swap min and current pos
		auto temp = *it;
		*it = *min;
		*min = temp;
	}
}

template <class Iter>
void Sort::merge(Iter begin, Iter end, const int size) {
	if (size < 2) {
		return;
	}
	Iter mid =  begin + size/2;
	merge(begin, mid, size/2);
	merge(mid, end, size - size/2);
	merge(begin, mid, end);
}

template <class Iter>
void Sort::merge(Iter begin, Iter mid, Iter end) {
	typedef typename std::iterator_traits<Iter>::value_type T;
	std::vector<T> L;
	std::vector<T> R;
	Iter it = begin;
	while (it < mid) {
		L.push_back(*(it++));
	}
	while (it < end) {
		R.push_back(*(it++));
	}
 
	std::vector<T>::iterator itL = L.begin(), itR = R.begin();
	it = begin;
	while (it < end && itL < L.end() && itR < R.end()) {
		if (*itL <= *itR) {
			*it = *(itL++);
		}
		else {
			*it = *(itR++);
		}
		++it;
	}
	if (itL == L.end()) {
		while (itR < R.end()) {
			*(it++) = *(itR++);
		}
	}
	else if (itR == R.end()) {
		while (itL < L.end()) {
			*(it++) = *(itL++);
		}
	}
}

template <class Iter>
void Sort::print(Iter begin, Iter end, bool increasing) {
	if (increasing) {
		Iter it = begin;
		std::cout << '[' << *(it++);
		for (; it < end; ++it) {
			std::cout << ", " << *it;
		}
		std::cout << ']' << std::endl;
	}
	else {
		Iter it = end - 1;
		std::cout << '[';
		for (; it > begin; --it) {
			std::cout << *it << ", ";
		}
		std::cout << *it << ']' << std::endl;
	}
}
