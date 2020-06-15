
/*
 * This file contains main()
 * Author : @SRAVUPAL
 * -----------------------------------------
 * Start Date : MAR 3 2020
 * -----------------------------------------
 * Change History
 * -----------------------------------------
 * Change Date : MAR 3 2020
 * Author : @SRAVUPAL
 * Change Description : Created PathConstraintPage file.
 * -----------------------------------------
 * Change Date : MAR 4 2020
 * Author : @SRAVUPAL
 * Change Description : Included while loop to slice the Path Constraint and display all the sliced path constraints.
 * -----------------------------------------
 * Change Date : MAR 4 2020
 * Author : @SRAVUPAL
 * Change Description : Modified the while loop to store all the sub_PC in an array.
 * -----------------------------------------
 * Change Date : MAR 8 2020
 * Author : @SRAVUPAL
 * Change Description : Modified the file as per the c++ format
 * -----------------------------------------
 * Change Date : APR 27 2020
 * Author : @SRAVUPAL
 * Change Description : Created test cases with the negation of the actual Path constraint
 * -----------------------------------------
 * Change Date : MAY 8 2020
 * Author : @SRAVUPAL
 * Change Description : Created a function to replace all the substrings, and written logic to get the test cases
 * -----------------------------------------
 * Change Date : MAY 11 2020
 * Author : @SRAVUPAL
 * Change Description : Modified the code to generate test cases for all the generated PC types.
 *                      Also organized the code into functions for re usability
 * -----------------------------------------
 * Change Date : MAY 12 2020
 * Author : @SRAVUPAL
 * Change Description : Changed the structure of the project, created separate pages for every function and created a service header file.
 *                      Also changed the data input from user to csv file.
 */

/*
 * Declarations
 */
#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <sstream>
#include "serviceFunctions.h"
using namespace std;

int main()
{
    string line;
    vector<string> failedPCVec;
    ifstream data("data.csv");
    ofstream myfile ("testcases.csv");
    vector<vector<vector<string> > >TCVec;

    if (data.is_open())
    {
        while ( getline (data,line) )
        {
            failedPCVec.push_back(line);
        }
        data.close();
    }

    else
        cout << "Unable to open file";

    for( unsigned int i = 0; i < failedPCVec.size(); i++ )
    {
        TCVec = pathConstraintFunction(failedPCVec[i]);
        myfile <<"Failed Path Constraint : "<<failedPCVec[i] <<"\n";
        myfile <<"Test Cases\n";
        for (size_t i = 0; i < TCVec.size(); i++)
        {
            for (size_t j = 0; j < TCVec[i].size(); j++)
            {
                for (size_t k = 0; k < TCVec[i][j].size(); k++)
                {
                    myfile << TCVec[i][j][k] << ",";
                }
                myfile << "\n";
            }
            myfile << "\n";
        }
    }
    return 0;
}


