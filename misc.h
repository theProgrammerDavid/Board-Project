
#ifndef MISC_H
#define MISC_H

#define WIN32_LEAN_AND_MEAN
//omits the extra stuff not used in this project from being included in the application
#include <windows.h>
#include <time.h>
class misc
{
    /**class prototype for miscellaneous functions   */
public:
    void sleepFor(int n){


    /** sleeps for n milliseconds */
    clock_t goal = n + clock();
    while(goal > clock());

    }

};
#endif // MISC_H
