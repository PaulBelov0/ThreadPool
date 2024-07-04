#ifndef MENU_H
#define MENU_H

#include <string>
#include <iostream>
#include <threadpool.h>
#include <exception>
#include <memory>
#include <cstdint>
#include <task.h>
#include <chrono>

class Menu
{
public:
    Menu(size_t thread_count);

    ~Menu();

    int selectingActions();

    void getNumberPair();

    void wrongInputError();

private:
    Task task;

    size_t thread_count_;

    std::string user_message_;

    ThreadPool* pool_;

    std::pair<uint64_t, uint64_t> user_pair_;

    std::list<uint64_t> output_list_;
};

#endif // MENU_H
