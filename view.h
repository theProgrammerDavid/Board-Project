#ifndef VIEW_H
#define VIEW_H

#include "fileHandler.h"
#include <stdio.h>
#include <iomanip>
#include "misc.h"
#include <iostream>
#include <string>
#include "output.h"
using namespace std;
class view
{
    /** contains the class prototype for the viewing elements  */
private:
    misc m;
    void printHeader();
    output _out;
    fileHandler fh;
    int noOfElements;
    void storeElements();

    void printTable();
    int space;
    string line;
    /** Vectors are sequence containers representing arrays that can change in size.
    Just like arrays, vectors use contiguous storage locations for their elements
    which means that their elements can also be accessed using offsets on regular pointers to its elements,
    and just as efficiently as in arrays.
    In other words, it is a template to create a sort of a linked list of a particular type which is specified
    in the <type>
    */
    vector<element> vec;
    /** pre-defined values for the headers and longest word in each column */
    string longest[4]= {"Name of element"," Atomic Number ","Atomic Mass","Symbol"};
    string header[4]= {" Name of element "," Atomic Number "," Atomic Mass ","  Symbol  "};
public:

    view()
    {
        /**finds out how many elements are in the file */
        noOfElements= fh.noOfElements();

    }
    void viewElements();
    void viewOneElement(element *ele);

};
#endif // VIEW_H
