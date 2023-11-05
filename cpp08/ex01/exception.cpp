#include "Span.hpp"

const char *Span::NotEnoughValuesException::what() const throw() {
	return ("Span class doesn't contain enough values, need at least 2");
}

const char *Span::ContainerFullException::what() const throw() {
	return ("Container is full");
}