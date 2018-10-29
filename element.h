#ifndef ELEMENT_H
#define ELEMENT_H
#include "output.h"
#include "accept.h"
#include <string.h>

/** element.h is the class prototype for the type element
 *  which is what this program is based upon
 *
 */

class element
{

private:
    output _out;
    accept _acc;
    char name[40];
    int atomic_weight;
    int atomic_number;
    char symbol[3];


public:
    element() {}
    void addNewElement();
    void addName();
    void addAtNo();
    void addAtWt();
    void addSymbol();
    char* getName();
    int getAtWt();
    int getAtNo();
    char* getSymbol();

    void setName(const char *ch)
    {
        /**accepts a parameter and sets the field name to the value passed as a parameter */
        strcpy(name,ch);
    }
    void setAtWt(int n)
    {
        /**accepts a parameter and sets the field atomic_weight to the value passed as a parameter */
        atomic_weight=n;
    }
    void setAtNo(int n)
    {
        /**accepts a parameter and sets the field atomic_number to the value passed as a parameter */
        atomic_number=n;
    }
    void setSymbol(const char *ch)
    {
        /**accepts a parameter and sets the field symbol to the value passed as a parameter */
        strcpy(symbol, ch);
    }

};
#endif // ELEMENT_H

