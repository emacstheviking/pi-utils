/**
    Copyright 2013 Sean Charles

    piconverter.c is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License,
    or (at your option) any later version.

    piconverter.c is distributed in the hope that it will be useful, but
    WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
    General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with piconverter.c. If not, see http://www.gnu.org/licenses/.
*/

#include <stdio.h>


/**

   PICONVERTER.C

   USAGE: piconverter ascii-filename raw-filename

   This utility uses the file obtained from bigprimes.net and after a
   manual process to remove the leading "3." in the file, it will
   create an output file consisting of a single byte representing each
   ASCII digit in the source. This means the output file can be used
   as a lookup table using "pidigit".

   BUILD: gcc piconverter.c -o piconverter

 */
int main(int argc, char* argv[])
{
  char* pifrom;
  char* pidest;
  FILE* fh;
  FILE* fo;

  if (argc != 3) {
    printf("Usage:- piconverter ascii-filename raw-filename\n");
    return -1;
  }

  fh = fopen(argv[1], "r");

  if (!fh) {
    printf("Failed to open source: %s\n", argv[1]);
    return -1;
  }

  fo = fopen(argv[2], "wb");

  if (!fo) {
    fclose(fh);
    printf("Failed to open output: %s\n", argv[2]);
    return -1;
  }

  while(!feof(fh)) {

    int ascii = fgetc(fh);
    int byte  = ascii - '0';

    if (byte >= 0 && byte <= 9) {
      fputc(byte, fo);
    }
  }

  fclose(fh);
  fclose(fo);
  return 0;
}
