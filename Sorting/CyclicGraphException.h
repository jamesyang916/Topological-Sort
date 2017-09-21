#pragma once
#include <exception>
#include <stdexcept>

class CyclicGraphException : public std::runtime_error {
public:
	CyclicGraphException();
	virtual const char* what() const throw();
};
