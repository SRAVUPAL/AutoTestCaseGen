/*
 * File name : pathConstrainPage.cpp
 * Author : @SRAVUPAL
 * Page description : This page contains the functionality to separate the conditions from a failed path constraint.
 * -----------------------------------------
 * Start Date : MAY 12 2020
 * -----------------------------------------
 * Change History
 * -----------------------------------------
 * Change Date : MAY 12 2020
 * Author : @SRAVUPAL
 * Change Description : Created pathConstrainPage file.
 * -----------------------------------------
 * Change Date : AUG 03 2020
 * Author : @SRAVUPAL
 * Change Description : Included comments to the page.
 * -----------------------------------------
 */

/*
 * Declarations
 */
#include <iostream>
#include <string.h>
#include <vector>
#include <sstream>
#include <iterator>
#include "serviceFunctions.h"
using namespace std;

/*
 * This part of code separates the special character ^ from the failed path constrain.
 */

struct tokens: ctype<char>
{
    tokens(): ctype<char>(get_table()) {}

    static ctype_base::mask const* get_table()
    {
        typedef ctype<char> cctype;
        static const cctype::mask *const_rc= cctype::classic_table();

        static cctype::mask rc[cctype::table_size];
        memcpy(rc, const_rc, cctype::table_size * sizeof(cctype::mask));

        rc['^'] = ctype_base::space;
        return &rc[0];
    }
};

/*
 * The pcSolvingFunction() takes cleaned PC as input and uses above structure to separate page values
 * and are stored in a vector
 */
vector<string> pcSolvingFunction(string FailedPC)
{
    stringstream ss(FailedPC);
    ss.imbue(locale(locale(), new tokens()));

    istream_iterator<string> begin(ss);
    istream_iterator<string> end;

    vector<string> PCVector(begin, end);
    copy(PCVector.begin(), PCVector.end(), PCVector.begin());
    return PCVector;
}
