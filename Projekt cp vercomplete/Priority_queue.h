#pragma once
#include <memory>
#include <string>
#include <algorithm>
#include <iostream>
#include <fstream>

template<typename T>
class Priority_queue
{
private:
	std::unique_ptr<T[]> data; /**< Data stored in priority queue */
	int capacity; /**< Maximum capacity of priority queue */
	int size; /**< variable that holds information on how many elements are inside priority queue */
	void heapify(int index);
	void max_heap();
public:
	/**
	 * @brief Constructor of the class.
	 *
	 */
	Priority_queue();
	/**
	 * @brief Constructor with some capacity.
	 *
	 * @param some_num
	 */
	Priority_queue(int some_num);
	/**
	 * @brief Move constructor.
	 * 
	 * @param difrent queue
	 * @return 
	 */
	Priority_queue(Priority_queue&& diff) noexcept;
	~Priority_queue();
	/**
	 * @brief Sorts in ascending order.
	 * Do not use this funciton unless you use max_heap to fix it afterwards.
	 * 
	 */
	void sort_heap();
	/**
	 * @brief Adds elements to the priority queue.
	 *
	 * @param the value that will be pushed to priority queue.
	 */
	void push(T some_value);
	/**
	 * @brief Searches for the value in the priority queue.
	 *
	 * @param Searched value
	 */
	T search(T some_value);
	/**
	 * @brief Pops the maximum value inside priority queue.
	 *
	 */
	void pop();
	/**
	 * @brief Checks if the container is empty.
	 *
	 * @return Returns true for empty and false if it has some elements.
	 */
	bool empty();
	/**
	 * @brief Overloads operator=.
	 *
	 * @param value that is going to get copied.
	 * @return reference to to the current Priority queue.
	 */
	Priority_queue<T>& operator=(const Priority_queue& to_copy);
	/**
	 * @brief Shows the maximum element inside priority queue.
	 *
	 * @return Maximum value.
	 */
	T top();
	/**
	 * @brief Function that changes size of priority queue.
	 *
	 */
	void change_size();
	/**
	 * @brief Overloads operator[].
	 *
	 * @param index s.
	 * @return value under index x.
	 */
	T operator[](int x) const;
	/**
	 * @brief Shows size of the queue.
	 *
	 * @return size.
	 */
	int size_of_queue();
	/**
	 * @brief Saves priority queue elements to text file.
	 *
	 * @param name of the file.
	 */
	void save(std::string file_name);
	/**
	 * @brief Loads data from txt file into priority queue.
	 * 
	 * @param file_name name of the txt file
	 */
	void load_data(const std::string& file_name);
	/**
	 * @brief Prints current state of priority queue.
	 * 
	 */
	void print();

};

