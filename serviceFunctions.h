/*
 * File name : serviceFunction.cpp
 * Author : @SRAVUPAL
 * -----------------------------------------
 * Start Date : MAY 12 2020
 * -----------------------------------------
 * Change History
 * -----------------------------------------
 * Change Date : MAY 12 2020
 * Author : @SRAVUPAL
 * Change Description : Created serviceFunction file.
 * -----------------------------------------
 */

/*
 * Declarations
 */
#include<string.h>
#include<vector>
using namespace std;

char replaceFunction(string &pcvec_cpy, string delemeter, string replaceWith);
vector<string> pcSolvingFunction(string FailedPC);
vector<vector<string>> testCaseGeneratorFunction(vector<string> PCVector);
vector<vector<vector<string> > > pathConstraintFunction(string PCVector);

