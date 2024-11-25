#include <iostream>
#include <thread>
#include <vector>

int main()
{

    auto lambda = [](int x){
        std::cout << "Hello from child thread with id: " << std::this_thread::get_id() << std::endl;
        std::cout << "Argument passed: " << x << std::endl;
    };

    std::vector<std::thread> threads;
    
    for(int i=0; i < 10; i++)
    {
        threads.push_back(std::thread(lambda, i));
        threads[i].join();
    }

    std::cout << "Hello from the main thread." << std::endl;
}