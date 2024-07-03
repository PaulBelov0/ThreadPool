#include "ThreadPool/ThreadPool.h"
#include <iostream>
#include <exception>

int main(){

    size_t threadCount;

    if (std::thread::hardware_concurrency() >= 2){
        threadCount = 2 ;
    }
    else{
        threadCount = 1;
    }

    ThreadPool pool(threadCount);

    return 0;
}
