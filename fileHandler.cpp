#include "fileHandler.h"

fileHandler::fileHandler()
{
    /**constructor to open the streams to the files */
    ftemp.open("elements_temp.data", ios::out);
    fout.open("elements.data", ios::out|ios::app);
    fin.open("elements.data", ios::in);
}

int fileHandler::fileExists()
{
    /**checks if the file exists or not */

    ifstream fs;
    fs.open("elements.data", ios::in);

    return fs.good();
}


void fileHandler::split(const string& str, const string& delim, vector<string>& parts)
{
    /**accepts a string which is a line from the file and splits it using the delimiter
    and stores the individual fields in a vector of type string */
    size_t start, end = 0;
    while (end < str.size())
    {
        start = end;
        while (start < str.size() && (delim.find(str[start]) != string::npos))
        {
            start++;  // skip initial whitespace
        }
        end = start;
        while (end < str.size() && (delim.find(str[end]) == string::npos))
        {
            end++; // skip to end of word
        }
        if (end-start != 0)    // just ignore zero-length strings.
        {
            parts.push_back(string(str, start, end-start));
        }
    }
}


void fileHandler::writeElementToFile(element *ele)
{
    /**accepts element as a parameter and writes the corresponding fields to file */

    fout<<ele->getName()<<"+"<<ele->getAtNo()<<"+"<<ele->getAtWt()<<"+"<<ele->getSymbol()<<"\n";
}

void fileHandler::readElementFromFile(element *ele)
{

    /**reads a line from the file and extracts the data elements and stores it in the parameter passed */
    char line[1024];
    vector<string> parts;
    fin.getline(line, 80);
    string str(line);
    split(str, "+", parts);

    ele->setName(parts[0].c_str());
    ele->setAtNo(stoi(parts[1]));
    ele->setAtWt(stoi(parts[2]));
    ele->setSymbol(parts[3].c_str());


}

void fileHandler::writeToTempFile(element *ele)
{
    /**writes the fields of the parameter to the temp file */
    ftemp<<ele->getName()<<"+"<<ele->getAtNo()<<"+"<<ele->getAtWt()<<"+"<<ele->getSymbol()<<"\n";

}


int fileHandler::noOfElements()
{
    /**counts number of elements based on whether the input file stream is able to get a new line from the file */
    int n=0;
    ifstream flines;
    char line[80];
    flines.open("elements.data", ios::in);
    while(flines.getline(line, 80))
    {

        n++;
    }
    flines.close();
    return n;
}
