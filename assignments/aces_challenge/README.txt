Three Card Monte
================

Files
-----
dealer.cpp              -- generates dealer moves
linux_threecardmonte.o  -- compiled solution for linux
mac_threecardmonte.o    -- compiled solution for Mac
threecardmonte.cpp      -- your code goes here
time_threecardmonte.cpp -- a wrapper to call your code



The Game
--------
Ace begins between two other cards:

cAc

The dealer may perform the following moves, 
each represented by a single character:
L - swap left and center cards
R - swap right and center cards
E - swap edge cards

In a file named "threecardmonte.cpp" write a function with this signature:

char threecardmonte(long count, const char* moves);
  count -  number of moves to be performed
  moves - an array of <count> characters, each one of [LRE]

After executing the specified card moves, return one of:
'L' ace is left card
'C' ace is center card
'R' ace is right card


Various make commands
---------------------
make (or make all):
  Builds your solution, executable named 'short_con'
  Builds an executable named 'dealer' (see below)

There are two object files of the instructor's solution for both Mac and Linux:

make mac_short_con
  Builds instructor's solution that runs on Mac OS X
  Executable named mac_short_con

make linux_short_con
  Builds instructor's solution that runs on Linux
  Executable named linux_short_con

make dealer
  Also built with 'make' or 'make all'. This builds the dealer executable
  for generating the dealer's moves.


The Makefile will create two executables:
dealer - provide two command-line parameters. The first is a seed, the second
         is the number of moves to generate

short_con - program with your function. Accepts input in format provided by
            dealer.

Usage:
------
bash$ ./dealer 123 10000000 | ./short_con

The first parameter for 'dealer' is a random seed (to maintain control of the
random sequence of generated moves). The second parameter is the number of moves
the dealer generates.
