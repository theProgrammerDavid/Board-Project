#ifndef FILEHANDLER_H
#define FILEHANDLER_H
#include <vector>
#include <ios>
#include <fstream>
#include <string>
#include <stdio.h>
#include "element.h"
using namespace std;
class fileHandler
{

    /**class prototype for performing input and output operations to files */

public:
    int noOfElements();
    int fileExists();
    fileHandler();

    void rename()
    {
        /**closes the streams, deletes the existing file and renames the temporary file to the main file */
        ftemp.close();
        fout.close();
        fin.close();
        std::remove("elements.data");
        std::rename("elements_temp.data", "elements.data");
    }

    ~fileHandler()
    {
        /**destructor definition */
        fout.close();
        ftemp.close();
        fin.close();
    }
    void writeElementToFile(element *ele);
    void writeToTempFile(element *ele);
    void readElementFromFile(element *ele);

private:

    ofstream fout;
    ifstream fin;
    ofstream ftemp;
    void split(const string& str, const string& delim, vector<string>& parts);


};
#endif // FILEHANDLER_H
