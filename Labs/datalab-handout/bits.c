/*
 * CS:APP Data Lab
 *
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 */

#include "btest.h"
#include <limits.h>
//#include <stdio.h>

/*
 * Instructions to Students:
 *
 * STEP 1: Fill in the following struct with your identifying info.
 */
team_struct team =
{
   /* Team name: Replace with either:
      Your login ID if working as a one person team
      or, ID1+ID2 where ID1 is the login ID of the first team member
      and ID2 is the login ID of the second team member */
   "chwo6694+jale6295",
   /* Student name 1: Replace with the full name of first team member */
   "Chris Womack",
   /* Login ID 1: Replace with the login ID of first team member */
   "chwo6694",

   /* The following should only be changed if there are two team members */
   /* Student name 2: Full name of the second team member */
   "Jacob C. Levine",
   /* Login ID 2: Login ID of the second team member */
   "jale6295",
};

#if 0
/*
 * STEP 2: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

CODING RULES:

  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code
  must conform to the following style:

  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>

  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.

  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function.
     The max operator count is checked by dlc. Note that '=' is not
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.
#endif

/*
 * STEP 3: Modify the following functions according the coding rules.
 *
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the btest test harness to check that your solutions produce
 *      the correct answers. Watch out for corner cases around Tmin and Tmax.
 */
//
// 15 problems, 40 points
// 2 - rating 1
// 5 - rating 2
// 4 - rating 3
// 4 - rating 4

/* #1
 * tmin - return minimum two's complement integer
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
    // shifts 1 to MSB giving -2147483648 in two's complement
	return 0x1 << 31;
}

/* #2
 * minusOne - return a value of -1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int minusOne(void) {
    // bitwise negation fo all bits will give 0xffffffff or -1 in 2's comp
	return ~0x0;
}

/* #3
 * evenBits - return word with all even-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 2
 */
int evenBits(void) {
    // 0x55 => 0101 so shift by 8 and or to let ones pass through
	return ((((0x55 | (0x55 << 8)) << 16) | 0x55) | 0x55 << 8);
}

/* #4
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {
    //
    return ((x + ((x >> 31) & ((1 << n) + ~0))) >> n);
}

/* #5
 * isEqual - return 1 if x == y, and 0 otherwise
 *   Examples: isEqual(5,5) = 1, isEqual(4,5) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int isEqual(int x, int y) {
    // x^x = 0 so if x = x then !x^x will return 1
    //      otherwise it returns a zero
	return !(x^y);
}

/* #6
 * negate - return -x
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
    // ~x+1 = -x in 2's comp
	return ~x + 1;
}

/* #7
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
    // shift x >> by 8 (1<<3), 16 (2<<3), 24 (3<<3) to put byte in
    //      last byte then and with ff to extract last byte
	return (x >> (n << 3)) & 0xff;
}

/* #8
 * isPositive - return 1 if x > 0, return 0 otherwise
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 */
int isPositive(int x) {
    // for x<0 : !x>>31 will be 0 & 1 = 0
    // for x=0 : !x>>31 will be 1 & 0 = 0
    // for x>0 : !x>>31 will be 1 & 1 = 1
	return !(x >> 31) & !!(x);
}

/* #9
 * addOK - Determine if can compute x+y without overflow
 *   Example: addOK(0x80000000,0x80000000) = 0,
 *            addOK(0x80000000,0x70000000) = 1,
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int addOK(int x, int y) {
    // pos+pos = neg => overflow
    // neg+neg = pos => overflow
    // NXOR sign bits (x>>31,y>>31) to return 1 if signs match
    // x+y>>31 gives sign bit of sum
    // sum ^ x>>31 will only return 1 if sum and sign of x are diff
    // & XOR result and NXOR result to return 1 if there is overflow
    // ! not this result to get 0 for overflow and 1 for good to go
	return !((!((x>>31) ^ (y>>31))) & (((x+y)>>31) ^ (x>>31)));
}

/* #10
 * isLessOrEqual - if x <= y  then return 1, else return 0
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
    int signx = !!(x >> 31);
    int signy = !!(y >> 31);
    return ((!(signx ^ signy) & !!(((x + ~y) >> 31) & 1)) | (!!(signx & ~signy)));
}

/* #11
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 1 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int logicalShift(int x, int n) {
    // x>>n shift as normal right by n
    // shift 1 << 31 to MSB then shift >> by n-1 = ~(~n+1) to create mask
    // & will let 1's pass through and zero out any leading 1's
	return (x >> n) & (~((1<<31)>>(~(~n+1))));
}

/* #12
 * leastBitPos - return a mask that marks the position of the
 *               least significant 1 bit. If x == 0, return 0
 *   Example: leastBitPos(96) = 0x20
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 4
 */
int leastBitPos(int x) {
    // 2's complement x and -x hold the same LS1
    // Utilizing this and that x & ~x = 0 lets the ~x+1 mark the LS1 with
    //      a 1 so ~x+1 & x has 1's in the LS1
    return (~x+1)&x;
}

/* #13
 * bitParity - returns 1 if x contains an odd number of 0's
 *   Examples: bitParity(5) = 0, bitParity(7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int bitParity(int x) {
    // Using a folding method to return a 16 bit number with the parity of
    // the previous 32 bit, then XOR again to get the parity down to 8 bits.
    // This process is repeated until the LSB contains the parity of the
    // original 4 byte number. Then and the result with 1 to allow the last
    // digit to pass through or not.
    x ^= (x>>16);
    x ^= (x>>8);
    x ^= (x>>4);
    x ^= (x>>2);
    x ^= (x>>1);
    return (x &= 1);
}

/* #14
 * isPower2 - returns 1 if x is a power of 2, and 0 otherwise
 *   Examples: isPower2(5) = 0, isPower2(8) = 1, isPower2(0) = 0
 *   Note that no negative number is a power of 2.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 60
 *   Rating: 4
 */
int isPower2(int x) {
    // x>>31 gets sign bit to check if neg as neg is not power of 2
    // ~x+1 flips x and adds 1. if x is a power of 2 then result will be
    //      0xffffffff, so ~(~x+1) should return 0 if it is a power of 2.
    // then !! bangs out a 0 and nor these together so 00 = 2^pow.
    return !(!!(x>>31) | !!(~(~x+1)));
}

/* #15
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */
int bang(int x) {
    // for x=0 : x|(~x+1) will return 0 so (x|(~x+1))+1 = 1
    // for x!=0 : x|~x will place a 1 in MSB then shifting MSB >> 31 will
    //      give a -1 so (x|~x)>>31 + 1 = 0
    return ((x | (~x + 1)) >> 31) + 1;
}
