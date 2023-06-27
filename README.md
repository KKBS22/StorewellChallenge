# StorwellChallenge

Consider that you have a rectangular piece of paper of arbitrary dimensions N by M (where N and M are positive integers). You also have a pair of scissors which can cut perfectly straight with no loss of paper. You wish to reduce the original piece of paper into a series of perfect squares of paper, making the largest possible squares, and using all of the paper provided. Write a function in C that takes the inputs N, and M, and returns the series of squares that can be made out of that piece of paper. No fractional squares, i.e. no square should be less than 1 in length and width.

Some examples:

Input: N =6 , M = 5
Output: 5x5, 1x1, 1x1, 1x1, 1x1, 1x1

Input: N = 1, M = 1
Output: 1x1

Input: N = 9, M = 9
Output: 9x9

# Usage 
```
1. Clone the repository
2. cd /StorewellChallenge
3. mkdir build
4. cd build
5. cmake ..
6. make
```
# Sample Output
```
> ./squareCompute 1000 100
100x100 100x100 100x100 100x100 100x100 100x100 100x100 100x100 100x100 100x100 
> ./squareCompute 5 5
5x5 
>./squareCompute 6 5
5x5 1x1 1x1 1x1 1x1 1x1 
```

# To run some unit tests
```
Comile with : gcc -I ./cmocka-1.1.5/include/ -L ./cmocka-1.1.5/build/src/ test_MakeSquare.c -l:libcmocka-static.a libMakeSquareLib.a -fsanitize=address

[==========] Running 2 test(s).
[ RUN      ] test_square_gen
[       OK ] test_square_gen
[ RUN      ] test_cut_square
[       OK ] test_cut_square
[==========] 2 test(s) run.
[  PASSED  ] 2 test(s).
```

