#ifndef ACCEPT_H
#define ACCEPT_H

#include <iostream>
#include <ios>  // Provides ios_base::failure
#include "output.h"
/** class definition to accept values from the user
 *
 * this class accepts values from the user and
 * checks for correct input.
 * if wrong input, it asks the user to enter again
 *
 */

class accept
{

private:

template <typename T>
T getValidatedInput();

public:

    output _out;

    int enterInt();
    void getString(char *ch);
    void getChar(char ch);
};
#endif // ACCEPT_H

