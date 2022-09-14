/* This module contains functions to shift printable ASCII characters a given 
   number of positions forward.
*/

#include "shift.h"

#define FIRST ' ' // First printable ASCII character: ' '
#define LAST '~' // ASCII code of last printable character: '~'

char shift (char c);

/* Rotate c forward n places, wrapping around as necessary. */
char rotate (char c, const int n_positions)
{
  /* Only printable characters get shifted.  Luckily, all printable
     characters in ASCII are in a contiguous range. */
  if (c < FIRST || c > LAST) {
    return c;
  }
  
  unsigned int i;
  for (i = 0; i < n_positions; ++i) {
    c = shift (c);
  }

  return c;
}

/* Shift c forward 1 place in the printable ASCII char set, wrapping
   around from the last char to the first, if necessary. */
char shift (char c)
{
  /* If c is '~', shift it around to ' '. */
  if (c == LAST) {
    c = FIRST;
  } else {
    /* The cast isn't strictly necessary here. */
    c = (char) ((int) c + 1);
  }
  return c;
}

