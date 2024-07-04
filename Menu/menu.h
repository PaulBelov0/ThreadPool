#ifndef MENU_H
#define MENU_H

#include <string>
#include <iostream>
#include <threadpool.h>
#include <exception>
#include <memory>
#include <cstdint>

class Menu
{
public:
    Menu(size_t threadCount);

    ~Menu();

    int selectingActions();

    std::pair<uint64_t, uint64_t> getNumberPair();

    void output();

private:
    size_t thread_count_;

    std::string user_message_;

    ThreadPool* pool_;

    std::pair<uint64_t, uint64_t> user_pair_;
};

#endif // MENU_H
