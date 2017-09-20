/* Name: Matthew Bichay
 * Course: Systems Development in the Unix Environment
 * Semester: Fall 2017
 * Description: Source file for temp_convert library. Provides implementation
 * details for the convert_to_fahr method.
 */

#include "temp_convert.hpp"


double convert_to_fahr(double cent)
{
    /* Formula for Centigrade -> Fahrenheit conversion */
    return cent * 9.0/5.0 + 32;
}
