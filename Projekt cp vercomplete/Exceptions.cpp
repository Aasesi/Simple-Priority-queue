#include "Exceptions.h"

const char* my_priority::out_of_range::what() const throw()
{
	return "Priority queue out of range";
}

const char* my_priority::could_not_open_a_file::what() const throw()
{
	return "Could not open a file";
}