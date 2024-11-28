#include <iostream>
#include <thread>
#include <chrono>
#include <future>

int square(int x)
{
    return x * x;
}

int main()
{
    std::future<int> asyncFunction = std::async(&square, 12);
    std::cout << asyncFunction.get() << std::endl;
}