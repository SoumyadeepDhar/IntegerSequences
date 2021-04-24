/*
 * A002110.cpp
 *
 *  Created on:  23-Apr-2021
 *  Modified on: 23-Apr-2021
 *  Author:      Soumyadeep Dhar
 * 
 *  A002110: Primorial numbers (first definition): product of first n primes. 
 *           Sometimes written prime(n)#.
 *
 *  Example: 1, 2, 6, 30, 210, 2310, 30030, 510510, 9699690, 223092870, 
 *           6469693230, 200560490130, 7420738134810, 304250263527210, 
 *           13082761331670030, 614889782588491410, 32589158477190044730, 
 *           1922760350154212639070, 117288381359406970983270, 
 *           7858321551080267055879090  
 * 
 *  Prime:     https://oeis.org/A000040/a000040.txt
 *  prime(n)#: https://oeis.org/A002110/a002110.txt
 * 
 */

#include "A002110.h"

using LargeIntegerSequence = ns::dn::is::a002110::A002110;

int main()
{
  // Initialize sequence
  LargeIntegerSequence seqA002110("../data/oeis/a000040.txt", "../data/oeis/a002110.txt", "../data/a002110.txt");

  // Createsequence upto 5000 elements
  for (int x = 0; x < 5000; x++)
  {
    // Generate next element
    seqA002110.generate();
  }

  return 0;
}
