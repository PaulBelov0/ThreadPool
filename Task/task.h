#ifndef TASK_H
#define TASK_H

#include <cmath>
#include <memory>
#include <list>
#include <iostream>

class Task
{
public:
    Task();
    ~Task();

    std::list<uint64_t>& calculate(uint64_t& value);
private:
    std::pair <uint64_t, uint64_t> pair;

    std::list<uint64_t> output_list_;
};

#endif //TASK_H