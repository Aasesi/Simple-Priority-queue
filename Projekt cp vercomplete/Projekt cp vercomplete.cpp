#include <iostream>
#include<random>
#include "Priority_queue.h"
#include "Priority_queue.cpp"
#include <algorithm>

int main()
{
    Priority_queue<int> some_example(9);
    some_example.push('h');
    some_example.push('i');
    some_example.push('z');
    some_example.pop();
    some_example.pop();
    some_example.pop();

}
