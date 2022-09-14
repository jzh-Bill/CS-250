/* This program reads from the standard input and rotates each
   printable character forward in the ASCII character set by a
   specifed number of positions.  The character is then written to the
   standard output.

   The number of positions is specified on the command line.

   Author: Bob Matthews
   Date: Apr. 1, 2020
   Written for CS 250
*/
#include <stdio.h>
#include <stdlib.h>

/* Shifting module */
#include "shift.h"

/* Print message about correct usage. */
void usage(const char *prog_name);

int main (int argc, char *argv[])
{
  int n_positions; // The default value

  /* Get number of positions to rotate from command line. */
  if (argc == 2) {
    
    /* Grab the number of positions to rotate from command line. */
    if (sscanf (argv[1], "%d", &n_positions) != 1) {
      /* Something went wrong converting command line argument to
	 int. */
      usage(argv[0]);
      exit (-1);
    }
    
  } else {
    
    usage (argv[0]);
    exit (-1);
    
  }
  
  if (n_positions < 0) {
    /* Can't shift backwards, yet. */
    usage (argv[0]);
    exit (-1);
  }

  /* Read each character in the standard input, rotate it the
     requested number of positions, and print it out. */
  char c;
  while ( (c = getchar()) != EOF) {
    putchar (rotate (c, n_positions));
  }

  exit (0);

}


/* Print usage message. */
void usage(const char* prog_name)
{
  printf ("Usage: %s [non-negative position]\n", prog_name);
}

	     
