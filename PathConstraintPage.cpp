/*
 * File name : testCaseGenerationMain.cpp
 * Author : @SRAVUPAL
 * Page description : This page has got the functionality to deal with cleaning path constraints and storing the test cases in a vector.
 * -----------------------------------------
 * Start Date : MAY 12 2020
 * -----------------------------------------
 * Change History
 * -----------------------------------------
 * Change Date : MAY 12 2020
 * Author : @SRAVUPAL
 * Change Description : Created testCaseGenerationMain file.
 * -----------------------------------------
 * Change Date : AUG 03 2020
 * Author : @SRAVUPAL
 * Change Description : Made some changes to vector names and comments.
 * -----------------------------------------
 */


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

/*
 * pathConstraintFunction() function takes failed path constrain as input and calls pathconstraintSolver function.
 */
vector<vector<vector<string> > > pathConstraintFunction(string FailedPC)
{
    vector<string> PCVector, testCases;
    vector<vector<int> > asciiVec;
    vector<vector<vector<string> > >testCaseVector;

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
     * code to store all the generated test cases in a vector by calling testCaseGeneratorFunction().
     */
    testCaseVector.push_back(testCaseGeneratorFunction(PCVector));
    for(size_t i=0; i < testCases.size(); i++)
    {
        vector<string> testCase_cpy;
        testCase_cpy = pcSolvingFunction(testCases[i]);
        testCaseVector.push_back(testCaseGeneratorFunction(testCase_cpy));
    }

    for (size_t i = 0; i < testCaseVector.size(); i++)
    {
        cout<<endl;
        for (size_t j = 0; j < testCaseVector[i].size(); j++)
        {
            for (size_t k = 0; k < testCaseVector[i][j].size(); k++)
            {
                if(testCaseVector[i][j][k].find("\"")== string::npos)
                {
                    replaceFunction(testCaseVector[i][j][k], "<", "=");
                    replaceFunction(testCaseVector[i][j][k], ">", "=");
                    replaceFunction(testCaseVector[i][j][k], "!", "=");
                    replaceFunction(testCaseVector[i][j][k], "==", "=");
                }
                cout<<testCaseVector[i][j][k]<<" ";
            }
            cout<<endl;
        }
    }
    return testCaseVector;
}


