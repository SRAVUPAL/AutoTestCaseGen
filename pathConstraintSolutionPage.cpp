#include <iostream>
#include <string.h>
#include <vector>
#include <sstream>
#include <iterator>
#include "serviceFunctions.h"
using namespace std;

/*
 *
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
 *
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
