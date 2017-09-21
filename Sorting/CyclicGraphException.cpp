#include "CyclicGraphException.h"

CyclicGraphException::CyclicGraphException()
	: std::runtime_error("There exists a cycle.") {}

const char* CyclicGraphException::what() const throw() {
	return std::runtime_error::what();
}