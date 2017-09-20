/* Name: Matthew Bichay
 * Course: Systems Development in the Unix Environment
 * Semester: Fall 2017
 * Description: Main file for the conv_to_fahr binary.
 */

#include <iostream>
#include <stdlib.h>
#include "temp_convert.hpp"

using namespace std;

int main()
{
    /* Request input for centigrade */
    cout << "Enter number of centigrade degrees: ";
    string input_str;
    cin >> input_str;

    /* Check validity of input */
    bool fail = false;
    for (int i=0; i<input_str.length(); ++i)
    {
        if (!isdigit(input_str[i]))
            fail = true;
            break;
    }
    if (!fail)
    {
        /* If valid, convert Centigrade to Fahrenheit */
        double input = atof(input_str.c_str());
        cout << input 
            << " degrees centigrade is " 
            << convert_to_fahr(input) 
            << " degrees Fahrenheit." 
            << endl;
    }
    else
    {
        /* If invalid, inform error and exit with error */
        cout << "Error: " << input_str << " is an invalid input." << endl;
        return -1;
    }
    return 0;
}
