
#ifndef MISC_H
#define MISC_H

#include <chrono>
#include <thread>
#include <iostream>
class misc
{
    /**class prototype for miscellaneous functions   */
public:
    void sleepFor(int n)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(n));
    }
};
#endif // MISC_H
