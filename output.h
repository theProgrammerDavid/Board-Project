
#ifndef OUTPUT_H
#define OUTPUT_H

#include <iostream>
#include <string.h>

using namespace std;


class output
{
    /**class prototype that holds functions for formatting the console output */
private:


public :
    void column();
    void menuFoot();
    void menuHeader();
    void columnLines(int n);
    void menuFooter();
    void newLines(int n);
    void topMenuBox();
    void singleFoot();
    void column(const char *str);
    void spaces(int n);
    int space=0;


};
#endif
