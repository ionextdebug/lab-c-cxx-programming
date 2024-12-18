#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

std::mutex gLock;
static int shared_value = 0;

void shared_value_increment()
{
    std::lock_guard<std::mutex> lockGuard(gLock);

    try{
        shared_value = shared_value + 1;
        throw "dangerous abort";
    }catch(...){
        std::cout << "handle exception" << std::endl;
    }
}

int main()
{
    std::vector<std::jthread> jthreads;

    auto lambda = [](int x)
    {
        std::cout << "child jthread, argument: " << x << std::endl;
    };

    for (int i = 0; i < 10; i++)
    {
        jthreads.push_back(std::jthread(shared_value_increment));
    }


    std::cout << "Shared value: " << shared_value << std::endl;

    return 0;
}