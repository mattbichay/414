/* Name: Matthew Bichay
 * Course: Systems Development in the Unix Environment
 * Semester: Fall 2017
 * Description: Main file for conv_to_cent binary
 */

#include <iostream>
#include <stdlib.h>
#include "temp_convert.hpp"
#include "getarg.hpp"

using namespace std;

int main(int argc, char* argv[])
{
    /* Get valid argument */
    double * return_value = new double();
    bool error = get_argument(argc, argv, return_value);
    if (error)
    {
        cout << "Error: Please enter a numeric value as the first argument." << endl;
        return -1;
    }

    /* If valid, return conversion from Fahrenheit to Centigrade */
    cout << *return_value 
         << " degrees Fahrenheit is " 
         << convert_to_cent(*return_value)
         << " degrees centigrade."
         << endl;
    return 0;
}
