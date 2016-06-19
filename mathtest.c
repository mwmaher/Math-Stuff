/* MathTest.C

   By Michael W. Maher

   Ver 1.0 10/13/92      for MCS 5.1
       2.0 6/30/93

   Description: mathtest.c was written to test the mathematical functions
		in mathstuf.c.

   Portability: ANSI C
*/
/******************************** defines **********************************/
#define FIB_TEST_MAX 12
#define MAX_FACT_TEST 9L

/*********************** ANSI C standard libraries *************************/
#include<stdio.h>
#include<string.h>

/********************* Headers By Michael W. Maher *************************/
#include"toolkit.h"
#include"mathstuf.h"

/********************* C source By Michael W. Maher ************************/
#include"mathstuf.c"

/*************************** Function Prototypes ***************************/
int  main(void);
char test1(FILE *output);
char test2(FILE *output);
char test3(FILE *output);
char test4(FILE *output);
char *testout(char passfail, char *out);

int main(void)
  {
  FILE *output = stdout;
  char buf[6];
  unsigned i = 1;

  fprintf(output, "\nmathtest.c By Michael W. Maher"
		  "\nversion 2.0 6/30/93"
		  "\nTesting the mathstuf.c C functions...\n\n");

  /* Test the Fibonacci number generator. */
  fprintf(output, "TEST #%d: %s\n", i++, testout(test1(output), buf));
  /* Test the factorial fucntion fact(). */
  fprintf(output, "TEST #%d: %s\n", i++, testout(test2(output), buf));
  /* Test the power function power(). */
  fprintf(output, "TEST #%d: %s\n", i++, testout(test3(output), buf));
  /* Test the ASCII to Binary conversion function. */
  fprintf(output, "TEST #%d: %s\n", i++, testout(test4(output), buf));
  return(0);
  }


/****************************************************************************
   function: test1()

 parameters: output - directs output to a device

    returns: PASS if the test was successful
	     FAIL if the test did not work properly

    purpose: The following program will test the Fibonacci number generator
	     function. The Fibonacci number can be found with the
	     following recursive function: FIB(n) = FIB(n - 1) + FIB(n - 2).
****************************************************************************/
char test1(FILE *output)
  {
  char          test = PASS;
  unsigned long i,
		result,
		test_data[12];

  /* initialize the correct answer table */
  test_data[0] = 0;
  test_data[1] = 1;
  test_data[2] = 1;
  test_data[3] = 2;
  test_data[4] = 3;
  test_data[5] = 5;
  test_data[6] = 8;
  test_data[7] = 13;
  test_data[8] = 21;
  test_data[9] = 34;
  test_data[10]= 55;
  test_data[11]= 89;
  for (i = 0; i < FIB_TEST_MAX; i++)
    {
    result = fibonacci_num(i);
    if (result != test_data[i])
      {
      fprintf(output, "Error: i = %lu, Fibonacci = %lu\n", result, test_data[i]);
      test = FAIL;
      break;
      }
    }
  return(test);
  }


/****************************************************************************
   function: test2()

 parameters: output - directs output to a device

    returns: PASS if the test was successful
	     FAIL if the test did not work properly

    purpose: Test the factorial fact() function.
****************************************************************************/
char test2(FILE *output)
  {
  char test = PASS;
  unsigned long i,
		result,
		sol[10];

  sol[0] = 1L;
  sol[1] = 1L;
  sol[2] = 2L;
  sol[3] = 6L;
  sol[4] = 24L;
  sol[5] = 120L;
  sol[6] = 720L;
  sol[7] = 5040L;
  sol[8] = 40320L;
  sol[9] = 362880L;
  for (i = 0; i < MAX_FACT_TEST; i++)
    {
    result = fact(i);
    if (result != sol[i])
      {
      test = FAIL;
      fprintf(output, "\nERROR: test 2 fact(%ld) returned %ld.\n", i, sol[i]);
      break;
      }
    }
  return(test);
  }


/****************************************************************************
   function: test3()

 parameters: output - directs output to a device

    returns: PASS if the test was successful
	     FAIL if the test did not work properly

    purpose: This function will test the power() function.
****************************************************************************/
char test3(FILE *output)
  {
  char test = PASS;

  /* x to the y power tests */

  if (power(0L, 0L) != 0L)
    test = FAIL;
  if (power(1L, 0L) != 1L)
    test = FAIL;
  if (power(0L, 1L) != 0L)
    test = FAIL;
  if (power(2L, 2L) != 4L)
    test = FAIL;
  if (power(3L, 9L) != 19683L)
    test = FAIL;
  if (test == FAIL)
    fprintf(output, "\nERROR: test 3 - power() function failure\n");
  return(test);
  }
  
  
/****************************************************************************
   function: test4()

 parameters: output - directs output to a device

    returns: PASS if the test was successful
	     FAIL if the test did not work properly

    purpose: This function will test the ascii2bin() function.
****************************************************************************/
char test4(FILE *output)
  {
  char 	test = PASS;
  char 	*binary,
  	*string;
  int	str_size;
  
  binary = "                ";
  string = "1111";
  str_size = 4;

  ascii2bin(binary, string, str_size);
  if (strcmp(binary, "  ") != 0)
    {
    printf("binary %s, string %s, str_size %i", binary, string, str_size);
    test = FAIL;
    }
  if (test == FAIL)
    fprintf(output, "\nERROR: test 4 - ascii2bin function failure\n");
  return(test);
  }


/****************************************************************************
   function: testout()

 parameters: passfail - boolean value (PASS or FAIL)
		  out - 5 character string

    returns: "PASS" is returned in the string (out) if passfail contains
	     a PASS char value.
	     "FAIL" is returned in the string (out) if passfail contains
	     a FAIL char value.

    purpose: This function converts a boolean value to a string value.
****************************************************************************/
char *testout(char passfail, char *out)
  {
  if (passfail == PASS)
    strcpy(out, "PASS");
  else
    strcpy(out, "FAIL");
  return(out);
  }


