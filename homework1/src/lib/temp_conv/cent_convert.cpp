/* Name: Matthew Bichay
 * Course: Systems Development in the Unix Environment
 * Semester: Fall 2017
 * Description: Source file for temp_convert library. Provides implementation
 * details for the convert_to_cent method.
 */

#include "temp_convert.hpp"

double convert_to_cent(double fahr)
{
    /* Formula for Fahrenheit -> Centigrade conversion */
    return (fahr - 32.0) * 9.0/5.0;
}
