#include <menu.h>

Menu::Menu(size_t thread_count)
{
    thread_count_ = thread_count;
    pool_ = new ThreadPool(thread_count_);
}


Menu::~Menu() { delete pool_; }


int Menu::selectingActions()
{
    output_list_.clear();

    bool pool_result_ = false;

    system("cls");

    std::cout << "Threads used: " << thread_count_ << std::endl;
    std::cout << "\nEnter you action: \n1) Enter the numbers\n2) Repeat\n3) Exit\n\nYour selection: ";

    std::cin >> user_message_;

    if (user_message_ == "1")
    {
        getNumberPair();

        output_list_ = task.calculate(user_pair_.first);

        std::function<void()> func([this]() {

            system("cls");
            std::cout << "Calculating result: " << std::endl;

            output_list_.sort();

            for (auto& element : output_list_)
            {
                std::cout << element << "\t";
            }
            std::cout << "\n"; 
            });

        do
        {
            pool_result_ =  pool_->enqueue(func);
        }
        while (pool_result_ != true);
        
        std::this_thread::sleep_for(std::chrono::seconds(5));

        selectingActions();

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
        wrongInputError();
    }
}

void Menu::getNumberPair()
{
    system("cls");

    std::cout << "Enter the first number(value): " << std::endl;
    std::cin >> user_message_;
    try
    {
        user_pair_.first = std::stoul(user_message_);
    }
    catch (const std::invalid_argument& e)
    {
        wrongInputError();
    }

    std::cout << "Enter the second number(priority): " << std::endl;
    std::cin >> user_message_;

    try
    {
        user_pair_.second = std::stoul(user_message_);
    }
    catch (const std::invalid_argument& e)
    {
        wrongInputError();
    }
}

void Menu::wrongInputError()
{
    system("cls");
    std::cout << "Error! Wrong input!" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(3));
    selectingActions();
}