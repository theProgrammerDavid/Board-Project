#ifndef SEARCHMODIFY_H
#define SEARCHMODIFY_H

#include "output.h"
#include <string.h>
#include <vector>
#include "view.h"
#include "fileHandler.h"


class searchModify
{

public:
    searchModify()
    {
        /**  constructor that calculates number of elements in the file */
        noOfElements=fh.noOfElements();
    }

    void searchDeleteElement(element *ele, int option);

private:
    int noOfElements;
    fileHandler fh;
    output _out;
    void modify(element *ele);

};
#endif // SEARCHMODIFY_H
