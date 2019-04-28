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

int drawing[TIP_SIZE];
char separator;
FILE* fd;


bool 	init_lottery (const char *csv_file, char csv_separator)
{
  FILE* file = fopen(csv_file, "r");
  separator = csv_separator;
  fd = file;
  for (int i = 0; i < TIP_SIZE; i++) {
    drawing[i] = 0;
  }
  return fd != 0;

}
bool 	get_tip (int tip_number, int tip[TIP_SIZE])
{
  int index = 0;
  int x = 0;
  char line[MAX_LINE_LEN];
  fseek(fd, 0 , SEEK_SET);
  if(tip_number<0)
  { return false; }
  for (int i = 0; i <= tip_number; i++)
  {
    if(fgets(line, MAX_LINE_LEN, fd) == 0)
    { return false; }
  }
  for (int i = get_to_start(line); i < MAX_LINE_LEN; i++)
  {
    char y[2];
    if (line[i] != separator && line[i] != '\0' && line[i] != '\n') {
      y[x++] = line[i];
    }
    else {
      int number = 0;
      for (int i = 0; i < x; i++) {
        number = number * 10 + (y[i] - '0');
      }
      tip[index++] = number;
      x = 0;
      if(index == TIP_SIZE) {
        return true;
      }
    }
  }
  return true;
}
bool 	set_drawing (int drawing_numbers[TIP_SIZE])
{
  for(int i = 0; i < TIP_SIZE; i++)
  {
    if(!(drawing_numbers[i] >= 1 && drawing_numbers[i] <= 45)) {
      return false;
    }
    drawing[i] = drawing_numbers[i];
  }
  return true;
}
int 	get_tip_result (int tip_number)
{
  if (drawing[0] == 0){
    return -1;
  }
  int tip[TIP_SIZE];
  if (!get_tip(tip_number, tip)){
    return -2;
  }
  int count = 0;
  for (int i = 0; i < TIP_SIZE; i++)
  {
    for (int u = 0; u < TIP_SIZE; u++)
    {
      if (tip[i] == drawing[u])
      {
        count++;
      }
    }
  }
  return count;
}

int 	get_right_tips_count (int right_digits_count)
{
  if(right_digits_count < 0 || right_digits_count > TIP_SIZE || drawing[0] == 0) {
    return -1;
  }
  int count=0;
  fseek(fd, 0, SEEK_SET);
  char line[MAX_LINE_LEN];
  for (int i = 0; i < 1000000; i++){
    if(fgets(line, MAX_LINE_LEN, fd)==0) {
      return count;
    }
    if(get_tip_result(i)==right_digits_count) {
      count++;
    }
  }
  return count;
}

int get_to_start(char* line)
{
  for (int i = 0; i < MAX_LINE_LEN; i++)
  {
    if(line[i] == separator) {
      return i+1;
    }
  }
  return 0;
}
