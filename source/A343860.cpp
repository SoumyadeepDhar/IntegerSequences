/*
 * A343860.cpp
 *
 *  Created on:  01-May-2021
 *  Modified on: 01-May-2021
 * 
 *  Author:  Soumyadeep Dhar
 * 
 *  A343860: Numbers k such that the two equations t^2-k*t+m = 0 and 
 *           t^2-m*t+k^2 = 0 have positive integer roots. m is the constant
 *           and k is the coefficient of t in first equation, which has roots p
 *           and q (i.e., {k, m, p, q} ∈ ℤ+, k=p+q and m=p*q). Also k^2 is the 
 *           constant and m is the coefficient of t in second equation, which 
 *           has roots u and v (i.e., {k, m, u, v} ∈ ℤ+, m=u+v and k^2=u*v).
 *
 *  Example: 8, 9, 10, 15, 18, 24, 35, 45, 90, 117, 136, 210, 235, 264, 306,
 *           435, 522, 585, 615, 792, 801, 1305, 1416, 1610, 1935, 2097, 2415,
 *           3042, 3608, 3978, 4215, 4616, 4690, 5490, 6090, 8730, 9015,   
 * 
 *  A343860: https://oeis.org/A343860/b343860.txt
 * 
 *  Sequence Author:  Soumyadeep Dhar, May 01 2021
 * 
 */

#include "largeint.h"
#include "processor.h"

using LargeInteger = ns::dn::li::LargeInt;
using LargeIntegerSequence = ns::dn::is::IntegerSequenceProcessor<ns::dn::is::A343860>;

// Process input data to generate next elements of the sequence
template <>
unsigned int LargeIntegerSequence::generate()
{
  long long int _count = 1;
  std::pair<unsigned int, std::string> _element;

  // Check all numbers upto 100000
  for (long long int k = 1; k < 100000; k++)
  {
    // For all possible roots of the equation
    // x^2 - kx + n (where x + y = k & xy = n)
    long long int _st = 1;
    long long int _en = (k >> 1) + 1;

    // Find possible (a, b) as root ofthe equaton
    // x^2 -nx + k^2 (where a + b = n and a * b = k^2)
    long long int kk = (k * k);

    // For all possible solutions
    for (long long int p = _st; p < _en; p++)
    {
      // Possible roots (x, y) such that 'x + y = k'
      long long int x = p;
      long long int y = k - p;

      // Find 'x * y' as expected 'n'
      long long int n = (x * y);

      // Find discriminant to check solution
      long long int d = (n * n) - (4 * kk);
      if (d >= 0)
      {
        // Get possible roots
        long long int a = (n + (powl(d, 0.5) + 0.5)) / 2;
        long long int b = n - a;

        // If valid roots found
        if ((a * b) == kk)
        {
          // Store result
          _element.first = _count;
          _element.second = std::to_string(k);

          // Write output data
          _ouWriter << _element;

          //Update element count
          _count++;
          std::cout << "[ " << k << " ]: "
                    << n
                    << " (" << a
                    << ", " << b
                    << ", " << x
                    << ", " << y << ") " << std::endl;

          // Keep only unique values
          break;
        }
      }
    }
  }

  return 0;
}

int main()
{
  // Initialize sequence
  LargeIntegerSequence seqA343860("../data/oeis/b000290.txt", "../data/oeis/b000290.txt", "../data/b343860.txt");

  // Generate sequence
  seqA343860.generate();

  return 0;
}