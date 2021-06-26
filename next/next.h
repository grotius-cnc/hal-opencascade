#ifndef NEXT_H
#define NEXT_H

#include "next_global.h"
#include <string>

#include <iostream>
#include <chrono>
#include <thread>

struct data {
    double x;
};
extern data databucket;

class NEXT_EXPORT Next{
public:

    Next();

    data init_wrapper(data d);
    data init(data d);


    void init_opencascade();
    void start();
    void gui();

    void meat(data d); // extern void meat(struct data d);

    struct data mymeat;

private:
    std::thread* Thread;
};

#endif // NEXT_H
