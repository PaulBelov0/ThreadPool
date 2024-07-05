#include <task.h>

Task::Task()
{
    output_list_.push_front(1);
}
Task::~Task() {}

std::list<uint64_t>& Task::calculate(uint64_t& value)
{
    bool flag;

    for (int i = 2; i <= (value/2)+1; i++)
    {
        flag = true;

        if (value % i == 0)
        {
            for (int j = 2; j <= sqrt(i); j++)
                if (i % j == 0)
                {
                    flag = false;
                    break;
                }
        }
        else
        {
            flag = false;
        }

        if (flag == true)
        {
            output_list_.push_back(i);
        }
    }

    return output_list_;
}