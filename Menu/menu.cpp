#include "menu.h"

Menu::Menu(size_t thread_count)
{
    thread_count_ = thread_count;
    pool_ = new ThreadPool(thread_count);
}

Menu::~Menu() {}

int Menu::selectingActions()
{
    system("cls");

    std::cout << "Threads used: " << thread_count_ << std::endl;
    std::cout << "Enter you action: \n1) Enter the numbers\n2) Repeat\n3) Exit" << std::endl;;
    std::cin >> user_message_;
    if (user_message_ == "1")
    {
        return 1;
    }
    else if (user_message_ == "2")
    {
        if (thread_count_ >= 2)
        {
            if (std::thread::hardware_concurrency() > 2 && std::thread::hardware_concurrency() >= 1 + thread_count_)
            {
                pool_->~ThreadPool();
                pool_ = new ThreadPool(++thread_count_);
                selectingActions();
            }
            else
            {
                std::cout << "Error! All threads used!" << std::endl;
                selectingActions();
            }
        }
        else
        {
            std::cout << "Error! All threads used!" << std::endl;
            selectingActions();
        }
    }
    else if (user_message_ == "3")
    {
        return 3;
    }
    else
    {
        std::cout << "Wrong input" << std::endl;
        selectingActions();
    }
}

std::pair<uint64_t, uint64_t> Menu::getNumberPair()
{
    system("cls");

    uint64_t value, priority;

    std::cout << "Enter the first number(value): " << std::endl;
    std::cin >> user_message_;
    try
    {
        value = std::stoi(user_message_);
    }
    catch (const std::invalid_argument& e)
    {
        std::cout << "Error! Wrong input!" << std::endl;
        selectingActions();
    }

    std::cout << "Enter the second number(priority): " << std::endl;
    std::cin >> user_message_;

    try
    {
        priority = std::stoi(user_message_);
    }
    catch (const std::invalid_argument& e)
    {
        std::cout << "Error! Wrong input!" << std::endl;
        selectingActions();
        system("cls");
    }

    user_pair_ = std::make_pair(value, priority);

    return user_pair_;
}