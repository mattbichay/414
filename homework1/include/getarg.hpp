/* Name: Matthew Bichay
 * Course: Systems Development in the Unix Environment
 * Semester: Fall 2017
 * Description: Header file for the get_argument library. Defines the function
 * prototype for the get_argument method as well as definitions for OK/ERRROR
 * codes
 */

#define OK 0
#define ERROR -1

/* get_argument takes argc, argv, and a double return_value as inputs and
 * returns whether or not an argument was able to be parsed (OK/ERROR). If an
 * argument is able to be parsed, return_value will retain the value.
 */
int get_argument(int argc, char *argv[], double *&return_value);
