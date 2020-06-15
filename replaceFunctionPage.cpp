
#include <iostream>
#include <string.h>
#include "serviceFunctions.h"
using namespace std;
/*
 *
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
