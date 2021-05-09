/*
 * A057369.cpp
 *
 *  Created on:  01-May-2021
 *  Modified on: 26-May-2021
 * 
 *  Author:  Soumyadeep Dhar
 * 
 *  A057369: numbers m such that the two equations t^2-k*t+m = 0 and
 *           t^2-m*t+k^2 = 0 have positive integer roots. m is the 
 *           constant and k is the coefficient of t in first equation, 
 *           which has roots p and q (i.e., {k, m, p, q} ∈ ℤ+, k=p+q 
 *           and m=p*q). Also k^2 is the constant and m is the coefficient
 *           of t in second equation, which has roots u and v (i.e., 
 *           {k, m, u, v} ∈ ℤ+, m=u+v and k^2=u*v).
 *
 *  Example: 16, 18, 25, 45, 50, 80, 234, 250, 261, 425, 1025, 1040, 1530, 
 *           1625, 1746, 2320, 4250, 7605, 7794, 9650,  
 * 
 *  A057369: https://oeis.org/A057369/b057369.txt
 * 
 *  Sequence Author:  Naohiro Nomoto, Sep 23 2000
 * 
 */

#include <set>
#include "largeint.h"
#include "processor.h"

using LargeInteger = ns::dn::li::LargeInt;
using LargeIntegerSequence = ns::dn::is::IntegerSequenceProcessor<ns::dn::is::A057369>;

// Process input data to generate next elements of the sequence
template <>
unsigned int LargeIntegerSequence::generate()
{
  int _count = 1;
  std::pair<unsigned int, std::string> _element;

  // keep square values
  std::set<long long int> _results;

  // Check all numbers upto 100000
  for (long long int k = 8; k <= 5000000; k++)
  {
    // std::cout << "k: " << k <<  std::endl;
    // For all possible roots of the equation
    // x^2 - kx + m (where x + y = k & xy = m)
    long long int xMax = k / 2;

    // Find possible (a, b) as root of the equation
    // x^2 -mx + k^2 (where a + b = m and a * b = k^2)
    long long int kk = (k * k);

    // For all possible solutions
    long long int x = ceil((k - sqrt(kk - 8 * k)) / (double) 2);
    long long int y = (k - x);

    // Find 'x * y' as initial expected 'n'
    long long int m = (x * y);

    do
    {
      long long int s = sqrt((m * m) - (4 * kk));

      // Get possible roots
      long long int a = (m + s) / 2;
      long long int b = m - a;
      // std::cout << "k: " << k << " kk: " << kk << " (a*b): " << (a * b) << " a: " << a << " b: " << b << " s: " << s << " m: " << m << " x: " << x << " y: " << y << std::endl;

      // If valid roots found
      if ((a * b) == kk)
      {
        // Store result
        _results.insert(m);

        // Print result
        std::cout << "[ " << k << " ]: "
                  << m
                  << " (" << a
                  << ", " << b
                  << ", " << x
                  << ", " << y << ") " << std::endl;
      }

      // Adjust x to advance quickly
      a = kk / (b - 1);
      m = a + (b - 1);
      s = m / y;

      // Update values
      x = std::max(x + 1, s);
      y = k - x;
      m = x * y;

    } while (x <= xMax);
  }

  // Store shorted result  data
  _count = 1;
  for (auto _x : _results)
  {
    _element.first = _count;
    _element.second = std::to_string(_x);

    // Write output data
    _ouWriter << _element;

    //Update element count
    _count++;
  }
  return 0;
}

int main()
{
  // Initialize sequence
  LargeIntegerSequence seqA057369("../data/oeis/b000290.txt", "../data/oeis/b000290.txt", "../data/b057369.txt");

  // Generate sequence
  seqA057369.generate();

  return 0;
}