#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "fileHandler.h"
#include "accept.h"
class menu
{
    /**class prototype for the main menu of the program */
public:
    void start_application(void)
    {
        /**  starts the application loop */
        checkIfFileExists();
        mainMenu();
    }

private:

    void exit_program();
//    addElement _add;
    output _out;
    accept _acc;
    void mainMenu();
    void checkIfFileExists();
    void options(int option);

};

#endif // MENU_H
