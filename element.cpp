
#include "element.h"

char* element::getName()
{
    /**returns the current value of the field name of the invoking instance */
    return name;
}


void element::addNewElement()
{
    /** starts asking the user to fill in the fields of the current instance
     */

    addName();
    addAtNo();
    addAtWt();
    addSymbol();
}

void element::addAtWt()
{
    /** Asks the user to enter a value for the data field atomic_weight of the current instance */


    _out.columnLines(1);
    _out.column("Enter element's atomic weight " );
    _out.column();
    atomic_weight=_acc.enterInt();
    _out.columnLines(1);
}

void element::addAtNo()
{
    /** Asks the user to enter a value for the data field atomic_number of the current instance */
    _out.columnLines(1);
    _out.column("Enter element's atomic number " );
    _out.column();
    atomic_number=_acc.enterInt();
    _out.columnLines(1);


}

void element::addSymbol()
{

    /** Asks the user to enter a symbol for the data field symbol of the current instance */
    _out.columnLines(1);
    _out.column("Enter element's symbol" );
    _out.column();
    _acc.getString(symbol);

    _out.menuFooter();
}

void element::addName()
{
    /** Asks the user to enter a name for the data field name of the current instance */

    _out.columnLines(2);
    _out.column("Enter Name of the element");
    _out.column();
    _out.columnLines(1);
    _acc.getString(name);

}


int element::getAtNo()
{
    /** returns the field atomic_number of the current instance */
    return atomic_number;
}
int element::getAtWt()
{
    /** returns the field atomic_weight of the current instance */
    return atomic_weight;
}
char* element::getSymbol()
{
    /** returns the field symbol of the current instance */
    return symbol;
}

