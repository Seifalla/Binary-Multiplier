# Binary-Multiplier

# Running Instructions:

-	This program runs on Linux 4.4.0-34-generic x86_64 (DMB 005)

-	Use g++ to compile

-	Run as: ./a.out testFile.txt (where testFile contains the two operands seperated by an empty space)

-	The two operands should be entered in reversed order (i.e. they should start with the least significant bit).

-	The output number starts with the most significant bit


# Implementation:

The two inputs are read from a text file and stored in two vectors of integers.

Note: The two operands can be of any length.

  # Algorithm:

  Inputs: two vectors of integers x, y

  Output: A vector z, initially set to 0

  .	multiply z by 2

  .	If the y digit is odd, add x to z

  .	If it’s even, skip it and move on to the next digit

  To add two numbers x and y:

    . The operand with fewer digits is padded with 0’s

    .	Every two elements in the vectors are added

    .	If both operands are 1’s, the sum will be set to 1 and the carry will be set to 0
  
    .	If both operands are 1’s and the carry-in is also a 1, the sum will be set to 1 and the carry will be set to 1
  
