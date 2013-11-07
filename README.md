# PI UTILITIES

I have recently become more interested in PI and its nature and to
that end I decided that I needed some utilities to get me started on
my own personal investigations.

Firstly a big thanks to bigprimes.net who also happen to have for
download a file containing the ASCII representation of the first one
million digits of PI which I have included for completeness.

## OSX

These were written quickly and simply using Emacs and OSX... it ought
to run on anything else that has the same setup but as always,
YMMV. The most likeley breakage will be names of header files. Good
luck with that.


## piconverter

I manually removed the leading "3." from the file and then wrote
"piconverter" to traverse the file and create an output file
containing all of the digits butt-up against each other as single byte
values in the range 0-9. This can then be used as the input to
"pidigit"


## pidigit

Using the output from the piconverter program this utility allows the
fast access of any digit position within the one million sequence. For
speed it uses the application exit code to avoid having the calling
process have to waste more time converting an ASCII digit.

    EXIT: 0-9     good
    EXIT: >9      failed for some reason


## TODO: piserver!

This program is the natural and logical extension of "pidigit";
instead of having to spawn a new process each time just to get a
digit, this sets up a simple socket server and then accepts an ASCII
STRING and a newline character, at which point it converts that into
an index into the pidigit file it was started with. The return value
is a single byte in the range 0-9.

The intention of "piserver" is to allow you to write whatever fun
little investigative utilties you might be able to dream up without
being hung up on how you get the Nth digit of PI.


# Limitations

All of the utilities are of course limited by the size of the input
file... I have a file from bigprimes.net that gives me one million
digits... if you have a bigger file then convert it with "piconverter"
and off you go.


# Planned extensions...

I have also obtained the 15.12GB file containing the first 1.4 BILLION
PRIME NUMBERS and I will create some utilities to make using them also
as fast and as convenient as possible.


**This may well be the excuse to dive back into Assembler I've been looking for!**

Hope they prove useful, if you want anything it doesn't do let me know
because I would probably be up for adding it in just because!

