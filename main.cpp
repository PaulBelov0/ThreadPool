#include <thread>
#include <menu.h>

int main()
{
    size_t thread_count;
    if (std::thread::hardware_concurrency() >= 2)
    {
        thread_count = 2;
    }
    else
    {
        thread_count = 1;
    }

    Menu menu(thread_count);

    std::pair <uint64_t, uint64_t> pair;

    while (menu.selectingActions() != 3);

    return 0;
}