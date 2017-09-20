/* Name: Matthew Bichay
 * Course: Systems Development in the Unix Environment
 * Semester: Fall 2017
 * Description: Source file for the getarg library. Provides implementation
 * details for the getargument method.
 */

#include <getarg.hpp>
#include <temp_convert.hpp>
#include <iostream>
#include <stdlib.h>

using namespace std;

int get_argument(int argc, char* argv[], double *&return_value)
{
    /* Test for a valid (existing/numeric) input from argv[] */
    bool fail = false;
    if (argc <= 1)
        fail = true;
    else
    {
        string input_str(argv[1]);
        for (int i = 0; i < input_str.length(); ++i)
        {
            if (!isdigit(input_str[i]))
            {
                    fail=true;
                    break;
            }
        }
    }
    if (fail)
        return ERROR;

    /* Convert to char* to double */
    return_value = new double(atof(argv[1]));
    return OK;
}
