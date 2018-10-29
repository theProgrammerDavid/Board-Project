#include "view.h"


void view::viewElements()
{
    /**function to start building the table of elements */
    storeElements();
    printHeader();
    m.sleepFor(500);
    printTable();

}

void view::viewOneElement(element *ele)
{
    /** accepts an element as parameter and constructs a table to view that element's fields */
    printHeader();
    _out.singleFoot();
    std::cout<<"\t"<<left<<setw(20)<<ele->getName();
    std::cout<<left<<setw(20)<<ele->getAtNo();
    std::cout<<ele->getAtWt()<<"\t"<<ele->getSymbol()<<std::endl;
    _out.singleFoot();
    system("pause");
}

void view::storeElements()
{
    /** reads from file and stores the elements in a vector of type element */
    element ele;

    for(int i=0; i<noOfElements; i++)
    {
        fh.readElementFromFile(&ele);



        if(strcmp(longest[0].c_str(), ele.getName() )<0)
        {
            longest[0]=ele.getName();
        }

        if(strcmp(longest[1].c_str(), to_string(ele.getAtNo()).c_str() )<0)
        {
            longest[1]=to_string(ele.getAtNo());
        }

        if(strcmp(longest[2].c_str(), to_string(ele.getAtWt()).c_str() )<0)
        {
            longest[2]=to_string(ele.getAtWt());
        }

        if(strcmp(longest[3].c_str(), ele.getSymbol() )<0)
        {
            longest[3]=ele.getSymbol();
        }



        vec.push_back(ele);
    }

}


void view::printHeader()
{
    /**prints the header for the table */
    _out.singleFoot();
    space=0;
    std::cout<<"\t|";
    for(int i=0; i<4; i++)
    {
        m.sleepFor(200);
        space=longest[i].length() - header[i].length ();
        space /=2;

        for(int j=0; j<space; j++)
        {
            cout<<" ";
        }
        cout<<header[i];

        for(int j=0; j<space; j++)
        {
            cout<<" ";
        }
        cout<<"|";
    }
    cout<<"\n";
    _out.singleFoot();
}

void view::printTable()
{
    /**prints the table which consists of all the element and their corresponding fields*/
    string arr[4];

    for(int k=0; k<noOfElements; k++)
    {
        m.sleepFor(200);
        arr[0]=vec[k].getName();
        arr[1]= to_string(vec[k].getAtNo());
        arr[2]= to_string(vec[k].getAtWt());
        arr[3]= vec[k].getSymbol();

        space=0;
        std::cout<<"\t|";
        for(int i=0; i<4; i++)
        {

            cout<<left<<setw(header[i].length())<<arr[i]<<"|";


        }
        cout<<"\n";
        cout<<"\n";


    }
}
