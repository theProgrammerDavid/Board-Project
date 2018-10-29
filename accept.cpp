#include <stdio.h>
#include "accept.h"
/** int l and int space are predefined values.
 *
 * These values are predefined elsewhere in the program (main.cpp)
 * to help with alignment and table making
 * \return
 *
 */

extern int l;
extern int space;


int accept::enterInt()
{
    int temp_var;

    while(1)
    {


        std::cout << "\t";

        for (int i = 1; i <= 4; i++)
        {
            std::cout << "|";
        }

        _out.space = l - (2*4) ;
        _out.space /= 2;



        for (int i = 1; i <= _out.space-5; i++)
        {
            std::cout << " ";
        }

        cout<<"Enter Number : ";
//  accept _acc;


        try
        {
            temp_var = getValidatedInput<int>();
        }
        catch (exception e)
        {
            _out.column();
            _out.column("Invalid Input");
            _out.column();
            continue;
        }

        break;
    }
    return temp_var;

}

void accept::getString(char *ch)
{
    std::cout << "\t";

    for (int i = 1; i <= 4; i++)
    {
        std::cout << "|";
    }

    _out.space = l - (2*4) ;
    _out.space /= 2;



    for (int i = 1; i <= _out.space-5; i++)
    {
        std::cout << " ";
    }

    cout<<"Enter : ";
   // std::cin>>ch;
   gets(ch);

}
void accept::getChar(char ch)
{
    while(1)
    {
        std::cout << "\t";

        for (int i = 1; i <= 4; i++)
        {
            std::cout << "|";
        }

        _out.space = l - (2*4) ;
        _out.space /= 2;



        for (int i = 1; i <= _out.space-5; i++)
        {
            std::cout << " ";
        }

        cout<<"Enter : ";

        try
        {
            ch = getValidatedInput<char>();
        }
        catch (exception e)
        {
            _out.column();
            _out.column("Invalid Input");
            _out.column();
            continue;
        }

        break;

    }
}


template <typename T>
T accept::getValidatedInput(){


  // Get input of type T
    T result;
    cin >> result;

    // Check if the failbit has been set, meaning the beginning of the input
    // was not type T. Also make sure the result is the only thing in the input
    // stream, otherwise things like 2b would be a valid int.
    if (cin.fail() || cin.get() != '\n')
    {
        // Set the error state flag back to goodbit. If you need to get the input
        // again (e.g. this is in a while loop), this is essential. Otherwise, the
        // failbit will stay set.
        cin.clear();

        // Clear the input stream using and empty while loop.
        while (cin.get() != '\n')
            ;

        // Throw an exception. Allows the caller to handle it any way you see fit
        // (exit, ask for input again, etc.)
        throw ios_base::failure("Invalid input.");
    }

    return result;


}

