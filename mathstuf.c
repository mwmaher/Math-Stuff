/* MathStuf.C

   By Michael W. Maher

   Ver 1.0 4/5/91       for MCS 5.1

   Miscellaneous mathematical programming tools written in C.  All of
   the following functions conform to ANSI C standards for maximum
   portability and reusability.
*/


/****************************** math routines ******************************/
/****************************************************************************
   function: power()

 parameters: x - base
	     y - coefficient

    returns: x raised to the power of y

    purpose: This function calculates x raised to the power of y.  This is
	     an efficient recursive function.
****************************************************************************/
unsigned long power(unsigned long x, unsigned long y)
  {
  if (y > 1L)
    return(x * power(x, y - 1L));
  else
    return(x);
  }


/****************************************************************************
   function: fact()

 parameters: x - The number that the factorial function will be applied to.

    returns: (X!) - The factorial of x (X * (X-1) * (X-2)...*(1))

    purpose: This function will return the factorial of a unsigned long
	     integer x.  It is a clasic example of very efficient
	     recursive function.  Be wary of stack overflow with large
	     values of x.
****************************************************************************/
unsigned long fact(unsigned long x)
  {
  if ((x == 1L) || (x == 0L))
    return(1L);
  else
    return(x * fact(x - 1L));
  }


/****************************************************************************
   function: fibonacci_num()

 parameters: n - sequence number

    returns: the Fibonacci number of the sequence number n

    purpose: The following function is a representation of a recursive
	     algorithm of Leonardo Fibonacci's sequence (1202).  It is
	     generated with the following: FIB(N) = FIB(N-1) + FIB(N-2).
****************************************************************************/
unsigned long fibonacci_num(unsigned long n)
  {
  if (n > 1L)
    n = fibonacci_num(n - 1L) + fibonacci_num(n - 2L);
  return(n);
  }


/****************************************************************************
   function: primes()

 parameters: low  - lower bound
	     high - upper bound

    returns: TRUE  - if successful
	     FALSE - if failed to find any primes or encountered an error

    purpose: Finds all the prime numbers between the lower and upper bounds.
****************************************************************************/
int primes(unsigned long low, unsigned long high)
  {
  int status = TRUE;

  if (low == high)
    status = FAIL;
  return(status);
  }


/****************************************************************************
   function: ascii2bin()

 parameters: bin
 	     str
 	     size

    returns: void

    purpose: This is an implementation of the three-to-four algorithm.  For
             each byte out of a three-byte group of original binary data, 
             strip two bits and put them in the fourth (reserve) byte.  This
             gives us a group of four bytes with siz bits filled out.  Then
             shift them with the space bar character, and they become
             printable ASCII symbols.  Obviously, the expansion factor for
             this algorithm is 33%.  
             
             This algorithm is used in the uuencode and uudecode UNIX 
             utilities.
             
             Sometimes it's necessary to present binary data in ASCII format.
             The easiest way is to write it as a string of hexadecimal 
             symbols; that is, two characters for each byte of original data.
             However, this solution gives very unpleasant 100% expansion.
             The following solution is more efficient.
             
             This function was taken from SOFTWARE DEVELOPMENT MAY 1994 in
             an article by Ivan Kiselev.
****************************************************************************/
void ascii2bin(char *bin, char *str, int size)
  {
  int 		t = size/3,
      		r = size%3;
  register char f;
  register int	i, 
  		j;
  
  for (i = 0; i < t; i++, str++)
    for (j = 2, f = *(str+3) - SPACE; j < 7; j+=2, bin++, str++)
        *bin = (*str - SPACE) | ((f & SHOW >> j) << j);
  if (r)
    {
    for (j = 2, f = *(str+3) - SPACE; j < 2*r+1; j+=2, bin++, str++)
        *bin = (*str - SPACE) | ((f & SHOW>>j) << j);
    }
  }    
