/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class name here>
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			lottery.c
 * Author(s):		Peter Bauer
 * Due Date:		#due#
 *-----------------------------------------------------------------------------
 * Description:
 * Implementation of a library for analyzing lottery tips.
 *-----------------------------------------------------------------------------
*/
#include "lottery.h"
#include "stdio.h"
#include "stdlib.h"

#define 	UUID_LEN   40
#define 	MAX_TIP_LEN   17
#define 	MAX_LINE_LEN   (UUID_LEN + 1 + MAX_TIP_LEN + 1)

char seperator;


bool 	init_lottery (const char *csv_file, char csv_separator)
{
  FILE* fd = fopen(csv_file, "r");
  seperator = csv_separator;
  return fd != 0;
}
bool 	get_tip (int tip_number, int tip[TIP_SIZE])
{
  return false;
}
bool 	set_drawing (int drawing_numbers[TIP_SIZE])
{
  return false;
}
int 	get_tip_result (int tip_number)
{
  return 0;
}
int 	get_right_tips_count (int right_digits_count)
{
  return 0;
}
