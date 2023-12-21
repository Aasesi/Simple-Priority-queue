#include "Priority_queue.h"
#include "Exceptions.h"

 /**
  * Default constructor assigns values for size and capacity.
  *
  */
template<typename T>
inline Priority_queue<T>::Priority_queue()
{
	capacity = 10;
    size = 0;
	data = std::make_unique<T[]>(capacity);
}

/**
 * Constructor with some parameter for capacity.
 *
 * @param some_num
 */
template<typename T>
Priority_queue<T>::Priority_queue(int some_num)
{
    size = 0;
    capacity = some_num;
    data = std::make_unique<T[]>(capacity);
}

/**
 * Moves everything to another object.
 * 
 * @param diff difrent priority queue
 * @return 
 */
template<typename T>
Priority_queue<T>::Priority_queue(Priority_queue&& diff) noexcept
{
    data = std::move(diff.data);
    size = diff.size;
    capacity = diff.capacity;
    diff.data = nullptr;
    diff.size = 0;
    diff.capacity = 0;
}

/**
 * Destructor. Function does not contain anything because it does not need to beacuse
 * of the use smart pointers.
 *
 */
template<typename T>
Priority_queue<T>::~Priority_queue()
{

}

/**
 * The function checks if the capacity is max, if it is then makes it larger.
 * Next it assigns value and makes size of priority queue higher and finally uses max_heap to maintain heap property.
 * 
 * @param value that will be inserted.
 */
template<typename T>
void Priority_queue<T>::push(T some_value)
{
    if (size == capacity)
    {
        change_size();
    }
    data[size] = some_value;
    size++;
    max_heap();
}

/**
 * Searches for the object in data then prints it and retuns it.
 * 
 * @param value which we are looking for
 * @return value
 */
template<typename T>
T Priority_queue<T>::search(T some_value)
{
    for (int i = 0; i < size; i++)
    {
        if (data[i] == some_value)
        {
            std::cout << "Searched value is under:";
            std::cout << i << std::endl;
            return data[i];
        }
        if (i == size - 1)
        {
            std::cout << "There is no such value inside an priority queue" << std::endl;
            return NULL;
        }
    }
}

/**
 * Highest value is removed then it restores heap property.
 *
 * @throw my_priority::out_of_range() is thrown if there are no elements inside priority queue.
 *
 */
template<typename T>
void Priority_queue<T>::pop()
{
    try
    {
        if (empty() == false)
        {
            size--;
            std::swap(data[0], data[size]);
            std::cout << data[size] << std::endl;;
            max_heap();
        }
        else
        {
            throw my_priority::out_of_range();
        }
    }
    catch (const std::exception& m)
    {
        std::cout << m.what() << std::endl;
    }
}

/**
 * @brief Checks if queue is empty.
 * 
 * @return true if it is.
 */
template<typename T>
bool Priority_queue<T>::empty()
{
    if (size == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * @brief Copies all data to Priority queue from another object.
 * 
 * @param Object we are copying from
 * @return 
 */
template<typename T>
Priority_queue<T>& Priority_queue<T>::operator=(const Priority_queue& to_copy)
{
    data = std::make_unique<T[]>(to_copy.capacity);
    size = to_copy.size;
    capacity = to_copy.capacity;
    std::copy(to_copy.data.get(), to_copy.data.get() + to_copy.size, data.get());
    return *this;
}

/**
 * Returns highest value.
 * 
 * @throw my_priority::out_of_range() if priority queue is empty.
 * @return 
 */
template<typename T>
T Priority_queue<T>::top()
{
    try
    {
        if (empty == false)
        {
            return data[0];
        }
        else
        {
            throw my_priority::out_of_range();
        }
    }
    catch (const std::exception& m)
    {
        std::cout << m.what() << std::endl;
    }
}

/**
 * Creates new smart pointer with higher capacity and copies current elements to it then it replaces the old smart pointer.
 *
 */
template<typename T>
void Priority_queue<T>::change_size()
{
    capacity = capacity + 20;
    auto new_data = std::make_unique<T[]>(capacity);
    std::copy(data.get(), data.get() + size, new_data.get());
    data = std::move(new_data);
}

/**
 * Show value under x index.
 *
 * @param x
 * @return the wanted value
 * @throw my_priority::out_of_range() if the index is not in priority queue.
 */
template<typename T>
T Priority_queue<T>::operator[](int x) const
{
    try
    {
        if (x >= 0 && x < size)
        {
            return data.get()[x];
        }
        else
        {
            throw my_priority::out_of_range();
        }
    }
    catch (const std::exception& m)
    {
        std::cout << m.what() << std::endl;
    }
}

/**
 * Returns size of priority queue.
 * 
 * @return 
 */
template<typename T>
int Priority_queue<T>::size_of_queue()
{
    return size;
}

/**
 * Saves data in ascending order to some txt file.
 * Then it restores heap property.
 * 
 * @param file_name
 */
template<typename T>
void Priority_queue<T>::save(std::string file_name)
{
    sort_heap();
    std::ofstream file;
    file.open(file_name);
    try
    {
        if (!file.is_open())
        {
            throw my_priority::could_not_open_a_file();
        }
        else
        {

        }
    }
    catch (const std::exception& c)
    {
        std::cout << c.what() << std::endl;
    }
    for (int i = 0; i < size; i++)
    {
        file << data.get()[i] << std::endl;
    }
    file.close();
    max_heap();
}

/**
 * Process of creating a heap data structure.
 * 
 * @param index
 */
template<typename T>
void Priority_queue<T>::heapify(int index)
{
    int largest = index;
    int l = 2 * index + 1;
    int r = 2 * index + 2;

    if (l < size && data[l] > data[largest])
        largest = l;

    if (r < size && data[r] > data[largest])
        largest = r;

    if (largest != index) {
        std::swap(*(data.get() + index), *(data.get() + largest));
        heapify(largest);
    }
}

/**
 * Function that sorts heap in ascending order.
 * 
 */
template<typename T>
void Priority_queue<T>::sort_heap()
{
    int original_size = size;
    for (int i = original_size - 1; i > 0; i--)
    {
        std::swap(*data.get(), *(data.get()+i));
        size--;
        heapify(0);

    }
    size = original_size;
}

/**
 * We give data property of max heap.
 * 
 */
template<typename T>
void Priority_queue<T>::max_heap()
{
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(i);
    }
}

/**
 * Loads data from some text file.
 * 
 * @param name of the file or path to it
 */
template<typename T>
void Priority_queue<T>::load_data(const std::string& file_name)
{
    T a;
    std::ifstream myfile(file_name);
    try
    {
        if (!myfile.is_open())
        {
            throw my_priority::could_not_open_a_file();
        }
        else
        {

        }
    }
    catch (const std::exception& c)
    {
        std::cout << c.what() << std::endl;
    }
    while (myfile >> a)
    {
        push(a);
    }
    myfile.close();
}

/**
 * Printing function.
 * 
 */
template<typename T>
void Priority_queue<T>::print()
{
    for (int i = 0; i < size; i++)
    {
        std::cout << data[i] << std::endl;
    }
}