
#include "output.h"
extern int space;
extern int l;


void output::singleFoot()
{
    /**prints on the screen a single line of "-" */
    std::cout<<"\t";
    for (int i = 1; i <= l; i++)
    {

        std::cout << "-";
    }
    std::cout << std::endl;
}
void output::column()
{

    /**prints a column */

    std::cout << "\t";

    for (int i = 1; i <= 4; i++)
    {
        std::cout << "|";
    }



    space = (l - (2*4));


    for (int i = 1; i <= space; i++)
    {
        std::cout << " ";
    }



    for (int a = 1; a <= 4; a++)
    {
        std::cout << "|";
    }
    std::cout << std::endl;


}


void output::menuFoot()
{
    /**just like singleFoot(), but prints 2 lines */
    for (int a = 1; a <= 2; a++)
    {
        std::cout << "\t";

        for (int i = 1; i <= l; i++)
        {

            std::cout << "-";
        }
        std::cout << std::endl;
    }

}


void output::menuHeader()
{
    /** prints a header  */
    newLines(2);


    menuFoot();
}


void output::columnLines(int n)
{
    for(int i=1; i<=n; i++)
    {
        column();
    }
    /**prints n columns */

}


void output::menuFooter()
{

    column();
    column();
    /**prints a footer which is basically a line of "=" */

    menuFoot();



}


void output::topMenuBox()
{

    menuFoot();
    /**makes a box  */
    column();
    column();
    column();


}


void output::column(const char *str)
{
    /**prints a column with the string str in the center */
    std::cout << "\t";

    for (int i = 1; i <= 4; i++)
    {
        std::cout << "|";
    }

    space = l - (2*4) - strlen(str);
    space /= 2;




    for (int i = 1; i <= space; i++)
    {
        std::cout << " ";
    }
    std::cout << str;
    if (strlen(str) % 2 == 0)
    {
        for (int i = 1; i <= space; i++)
        {
            std::cout << " ";
        }
    }
    else
    {
        for (int i = 1; i <= space+1; i++)
        {
            std::cout << " ";
        }
    }


    for (int a = 1; a <= 4; a++)
    {
        std::cout << "|";
    }
    std::cout << std::endl;
}


void output::newLines(int n)
{
    /**prints n new lines  */
    for(int i=0; i<n; i++)cout<<"\n";
}


void output::spaces(int n)
{
    /**prints n spaces */
    for(int i=0; i<n; i++)cout<<" ";

}



