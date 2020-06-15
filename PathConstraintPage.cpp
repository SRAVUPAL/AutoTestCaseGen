/*
 * Declarations
 */
#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <iterator>
#include "serviceFunctions.h"
using namespace std;

vector<vector<vector<string> > > pathConstraintFunction(string FailedPC)
{
    vector<string> PCVector, testCases;
    vector<vector<int> > asciiVec;
    vector<vector<vector<string> > >TCVec;

    if(FailedPC.find("\"")!=string::npos)
    {
        FailedPC.erase( 0, 1 );
        FailedPC.erase( (FailedPC.size()-1), 1 );
        while(FailedPC.find( "\"\"" )!=string::npos)
        {
            FailedPC.erase( FailedPC.find( "\"\"" ), 1 );
        }
    }

    cout<<endl<<FailedPC<<endl;
    PCVector = pcSolvingFunction(FailedPC);
    FailedPC = "";

    for(int siz = PCVector.size(); siz > 0 ; siz--)
    {
        string testCase = "";
        for(int i = 0; i < siz; i++)
        {
            if(i == 0 && i < siz - 1)
            {
                testCase =  PCVector[i];
            }
            else if(i > 0 && i == siz - 1)
            {
                testCase =  testCase + "^!(" + PCVector[i] + ")";
            }
            else if (i == 0 && i == siz - 1)
            {
                testCase =  "!(" + PCVector[i] + ")";
            }
            else
            {
                testCase =  testCase + "^" + PCVector[i];
            }
        }
        testCases.push_back(testCase);
    }

    /*
     * Code to convert the sting vectors to ascii values and store it in a vector
     */

    for(size_t y = 0; y < testCases.size() ; y++)
    {
        vector<int> ascii;
        for(size_t x = 0; x < testCases[y].size() ; x++)
        {
            ascii.push_back(int(testCases[y][x]));
        }
        asciiVec.push_back(ascii);
    }

    for (size_t i = 0; i < asciiVec.size(); i++)
    {
        for (size_t j = 0; j < asciiVec[i].size(); j++)
        {
            testCases[i][j] = (char(asciiVec[i][j]));
        }
    }

    for (size_t i=0; i < testCases.size(); i++)
    {
        cout << endl << testCases[i]<<endl;
    }

    /*
     * Code to change the numeric values in the PC
     */
    for (size_t i = 0; i < asciiVec.size(); i++)
    {
        for (size_t j = 0; j < asciiVec[i].size(); j++)
        {
            if (47<asciiVec[i][j] && asciiVec[i][j]<57)
            {
                asciiVec[i][j] = asciiVec[i][j] + 1;
            }
        }
    }

    for (size_t i = 0; i < asciiVec.size(); i++)
    {
        for (size_t j = 0; j < asciiVec[i].size(); j++)
        {
            if (asciiVec[i][j] == 33 || asciiVec[i][j] == 60 || asciiVec[i][j] == 62)
            {
                while (asciiVec[i][j + 1] <= 61 && asciiVec[i][j + 1] != 60)
                {
                    if (asciiVec[i][j] > 47 && asciiVec[i][j] < 57)
                    {
                        asciiVec[i][j] = asciiVec[i][j] + 1;
                    }
                    j++;
                }
            }
        }
    }

    /*
     *
     */
    TCVec.push_back(testCaseGeneratorFunction(PCVector));
    for(size_t i=0; i < testCases.size(); i++)
    {
        vector<string> testCase_cpy;
        testCase_cpy = pcSolvingFunction(testCases[i]);
        TCVec.push_back(testCaseGeneratorFunction(testCase_cpy));
    }

    for (size_t i = 0; i < TCVec.size(); i++)
    {
        cout<<endl;
        for (size_t j = 0; j < TCVec[i].size(); j++)
        {
            for (size_t k = 0; k < TCVec[i][j].size(); k++)
            {
                if(TCVec[i][j][k].find("\"")== string::npos)
                {
                    replaceFunction(TCVec[i][j][k], "<", "=");
                    replaceFunction(TCVec[i][j][k], ">", "=");
                    replaceFunction(TCVec[i][j][k], "!", "=");
                    replaceFunction(TCVec[i][j][k], "==", "=");
                }
                cout<<TCVec[i][j][k]<<" ";
            }
            cout<<endl;
        }
    }
    return TCVec;
}


