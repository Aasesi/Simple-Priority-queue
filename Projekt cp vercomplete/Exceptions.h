#pragma once
#include <iostream>
#include<memory>

/**
 * @namespace my_priority
 *
 * @brief contains some exceptions for priority queue
 */
namespace my_priority {
	/**
	 * @class out_of_range.
	 *
	 * @brief exception is thrown if index is out of range
	 */
	class out_of_range : public std::exception
	{
	public:
		const char* what() const throw();
	};
	/**
	 * @class could_not_open_a_file.
	 *
	 * @brief exception is thrown if the file could not be opened.
	 */
	class could_not_open_a_file : public std::exception
	{
	public:
		const char* what() const throw();
	};
}

