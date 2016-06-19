/* MathStuf.h

   By Michael W. Maher

   Ver 1.0 4/5/91     MCS 5.1

   This is the header file for MathStuf.C.

   The mathematical functions were developed to aid C programmers.  The
   code is complient with the ANSI standard C.  The programs were tested
   with Microsoft C V5.1.
*/

#ifndef MATHSTUFH
  #define MATHSTUFH

  /******************************* includes ********************************/


  /******************************** macros *********************************/

  /******************************** defines ********************************/
  #define SPACE 32	 	/* space bar character */
  #define HIDE 63		/* 00111111 */
  #define SHOW 192		/* 11000000 */

  /************************** structure types ******************************/

  /************************ function prototypes ****************************/
  /* mathematical functions */

  /* Calculates x to the power y.  Recursive function.
  unsigned long power(unsigned long x, unsigned long y);

  /* Calculates the factorial of x. Recursive function. */
  unsigned long fact(unsigned long x);

  /* Calculate the Fibonacci number of n */
  unsigned long fibonacci_num(unsigned long n);
  
  /* Present binary data in ASCII format using the three-to-four algorithm */
  void ascii2bin(char *bin, char *str, int size);
  
#endif
