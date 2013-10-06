/**
    Copyright 2013 Sean Charles

    pidigit.c is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License,
    or (at your option) any later version.

    pidigit.c is distributed in the hope that it will be useful, but
    WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
    General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with pidigit.c. If not, see http://www.gnu.org/licenses/.
*/

#include <stdio.h>
#include <stdlib.h>



/**

   PIDIGIT.C

   USAGE: pidigit position [filename, default="pi.dig"]

   This is intended as a simple tool that can be incorporated into
   bash scripts or any other script that can make external
   calls. Given the 1 million digits of PI file from bigprimes.bet
   means you can now write programs to investigate PI.

   Given access to a file containing digits of pi (see piconvert.c)
   this utility takes the number passed in and returns the value of
   the digit at the chosen position AS THE EXIT CODE. -1 => FAIL

   Therefore, if the exit code is > 9, something went wrong and you
   should not use the value in your investigation code but halt.

   I used the exit code so that the caller doesn't have to bother
   performing any kind of string to integer translations which, if
   present in a loop, would be inefficient. Yes, I know spawning a
   call to pidigit is bad but I try not to make it worse!

   BUILD: gcc pidigit.c -o pidigit

*/
int main(int argc, char* argv[])
{
  int   value  = -1;
  char* pifile = "pi.dig";

  if (argc < 2) {
    printf("Usage:- pidigit position [filename, default=\"pi.dig\"]\n");
    return -1;
  }

  if (argc == 3) {
    pifile = argv[2];
  }

  FILE* fh = fopen(pifile, "rb");

  if (fh) {

    long pos = atol(argv[1]);

    if (!fseek(fh, pos, 0)) {
      value = fgetc(fh);
    }
    fclose(fh);
  }

  return value;
}
