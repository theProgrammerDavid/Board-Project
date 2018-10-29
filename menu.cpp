
#include "menu.h"
#include "view.h"

#include "searchModify.h"
void menu::checkIfFileExists()
{
    /**if file "elements.data" does not exist, this function prompts you to add a new element which will create a new file */
    _out.menuHeader();
    fileHandler fh;
    if(fh.fileExists()!=1)
    {
        _out.column("File does not exist!");
        _out.columnLines(2);
        _out.column("You can only add a new element . This will create a file with that element in it");
        _out.columnLines(2);
        element ele;
        ele.addNewElement();
        fileHandler fh;
        fh.writeElementToFile(&ele);
    }
//as user if this is the first time running. if yes, continue as normal and create files
//if no, say that program has data files missing and will now exit
}

void menu::mainMenu()
{
    int option=-1;
    /**displays the main menu */

    _out.topMenuBox();
//o.menuHeader();
    _out.column("Welcome!");
    _out.menuFooter();

    _out.columnLines(2);
    _out.column("David's Periodic Table");
    do
    {
        _out.menuFooter();

        _out.columnLines(3);

        _out.column("1. Add an element ");

        _out.column();
        _out.column("2. Search for an element");
        _out.column();
        _out.column("3. View the Periodic Table");
        _out.column();
        _out.column("4. Modify an element's details");
        _out.column();
        _out.column("5. Remove an element");
        _out.column();
        _out.column("6. Exit");
        _out.column();
        _out.columnLines(2);

        option=_acc.enterInt();



        if((option>=1 && option<=6))
        {
            _out.columnLines(2);
            _out.menuFooter();
            // option= options(option);
            options(option);
            option = -1;
        }

        else
        {
            _out.columnLines(2);
            _out.column("Invalid Option");
            _out.columnLines(2);
        }

    }
    while(!(option>=1 && option<=6));
}
//extern int again;


void menu::options(int option)
{
    /**based on what the user chose in the main menu, the corresponding sub menu will be opened */
    switch(option)
    {

    case 1:
    {
        element ele;
        ele.addNewElement();
        fileHandler fh;
        fh.writeElementToFile(&ele);

        break;
    }
    case 2:
    {

        searchModify sm;
        element ele;
        ele.addName();
        sm.searchDeleteElement(&ele,1);
        break;
    }
    case 3:
    {
        view v;
        v.viewElements();

        break;
    }
    case 4:
    {
        searchModify sm;
        element ele;
        ele.addName();
        sm.searchDeleteElement(&ele,0);
        break;
    }
    case 5:
    {
        //delete
        searchModify sm;
        element ele;
        ele.addName();
        sm.searchDeleteElement(&ele, -1);
        break;
    }

    case 6:
    {
        exit_program();
    }
    }
}


void menu::exit_program()
{
    _out.columnLines(2);
    _out.column("Program will now exit");
    _out.menuFooter();
    exit(0);

}
