/*----------------------------------------------------------
 *				HTBLA-Leonding / Class 2AHIF
 * ---------------------------------------------------------
 * Exercise Number: 0
 * Title:			deletable_primes.c
 * Author:			Panturu Gloria Sara
 * Due Date:		February 2, 2018
 * ----------------------------------------------------------
 * Description:
 * Implementation of deletable_primes.h.
 * ----------------------------------------------------------
 */
#include "deletable_primes.h"
#include <stdio.h>
 #include <math.h>


unsigned long remove_digit(int index, unsigned long n)
{
  int divisor = pow(10,index+1);
   int modulo = pow(10,index);
   long number = n/divisor;
   number *= modulo;
   number += n % modulo;
   return number;
}


int get_ways(unsigned long p)
{
  long number = p;
  int ways = 0;

  if (p < 10) {
    if (check_if_prime_number(p) == true) {
      return 1;
    }
    else
    {
      return 0;
    }
  }
  int index_count = 0;
  int number_length = count_digits(p);

  while (index_count < number_length) {
    long deletable_prime = remove_digit(index_count, p);

    if (check_if_prime_number(deletable_prime) == true) {
      int ways_number = get_ways(deletable_prime);
      ways += ways_number;
    }
    index_count++;
  }

  return ways;
}



int count_digits(unsigned long number)
{
  int count = 0;
  while (number != 0) {
    number /=10;
    count++;
  }
  return count;
}


bool check_if_prime_number (unsigned long number)
{
  long divisor = 2;
  while (number % divisor != 0) {
    divisor++;
  }

  if (number == divisor) {
    return true;
  }
  else
  {
    return false;
  }
}
