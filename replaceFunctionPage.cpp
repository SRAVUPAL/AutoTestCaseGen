/*
 * File name : replaceFunctionPage.cpp
 * Author : @SRAVUPAL
 * Page description : this page has got the function to replace the given delemeter with the replace string.
 * -----------------------------------------
 * Start Date : MAY 12 2020
 * -----------------------------------------
 * Change History
 * -----------------------------------------
 * Change Date : MAY 12 2020
 * Author : @SRAVUPAL
 * Change Description : Created replaceFunctionPage file.
 * -----------------------------------------
 * Change Date : AUG 03 2020
 * Author : @SRAVUPAL
 * Change Description : Changed the comments in the page.
 * -----------------------------------------
 */

/*
 * Declarations
 */
#include <iostream>
#include <string.h>
#include "serviceFunctions.h"
using namespace std;

/*
 * replaceFunction() is a function that can be used to replace the given delemeter with the replace string.
 */
char replaceFunction(string &pcvec_cpy, string delemeter, string replaceWith)
{
    size_t pos = pcvec_cpy.find(delemeter);
    while( pos != string::npos)
    {
        pcvec_cpy.replace(pos, delemeter.size(), replaceWith);
        pos = pcvec_cpy.find(delemeter, pos + replaceWith.size());
    }
}
