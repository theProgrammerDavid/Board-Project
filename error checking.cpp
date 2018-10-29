#include <ios>  // Provides ios_base::failure
#include <iostream>  // Provides cin
using namespace std;
template <typename T>
T getValidatedInput()
{
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



/*


#include <cstdlib>  // Provides EXIT_SUCCESS
#include <iostream>  // Provides cout, cerr, endl

#include "input.h"  // Provides getValidatedInput<T>()

int main()
{
    using namespace std;

    int input;

    while (true)
    {
        cout << "Enter an integer: ";

        try
        {
            input = getValidatedInput<int>();
        }
        catch (exception e)
        {
            cerr << e.what() << endl;
            continue;
        }

        break;
    }

    cout << "You entered: " << input << endl;

    return EXIT_SUCCESS;
}

*/
