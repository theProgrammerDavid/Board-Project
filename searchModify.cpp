#include "searchModify.h"


void searchModify::searchDeleteElement(element *ele, int option)
{
    /**
    this function accepts an element to search for as parameter and searches for the element in the data file
    if found, it proceeds to use the second argument
    if option == -1, the element will be deleted
    if option == 0, the element will be modified
        if option == 1, the element will be displayed*/
    /*
       -1 is delete; 0 is modify ; 1 is search
       */

    int found=-1;
    element test;


    for(int i=0; i<noOfElements; i++)
    {

        fh.readElementFromFile(&test);


        if(strcmp(test.getName(), ele->getName())  == 0)
        {
            found=1;
            if(option == 1)
            {

                _out.columnLines(2);
                _out.column("Element Found");
                _out.column();
                view v;
                v.viewOneElement(&test);
                break;
            }

            else if (option ==0 )
            {
                modify(&test);
                fh.writeToTempFile(&test);
            }
            else
            {
                /** if element is found and options == -1, then we simply skip writing it to the new file */
                continue;
            }

        }
        else
        {
            fh.writeToTempFile(&test);
        }
    }


    if(option==1)
    {

        fh.~fileHandler();
        /** standard function defined to delete a file */
        std::remove("elements_temp.data");

    }
    else
        fh.rename();



    if(found==-1)
    {

        _out.columnLines(2);
        _out.column("element not found");
        return;
    }
     _out.columnLines(2);
    _out.column("Action Completed");

}



void searchModify::modify(element *ele)
{
    /** asks the user to enter new details about the current instance of element */
    _out.columnLines(2);
    _out.column("Enter new Element Details");
    element ele2;

    ele->addNewElement();
}
