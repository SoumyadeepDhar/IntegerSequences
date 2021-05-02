/*
 * A057369.cpp
 *
 *  Created on:  01-May-2021
 *  Modified on: 26-May-2021
 *  Author:      Soumyadeep Dhar
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
 *           1625, 1746, 2320, 4250, 7605, 7794, 9650  
 * 
 *  A057369: https://oeis.org/A057369/b057369.txt
 * 
 *  Author:  Naohiro Nomoto, Sep 23 2000
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
  long long int _count = 1;
  std::pair<unsigned int, std::string> _element;

  // keep square vaues
  std::set<long long int> _results;
  std::vector<long long int> _squares;
  for (int a = 0; a < 100000; a++)
  {
    _squares.push_back(a * a);
  }

  // Check all numbers upto 100000
  for (long long int a = 1; a < 100000; a++)
  {
    // Valid last found square root
    long long int k = a;

    // For all previous values
    do
    {
      // Find (a, b) as root of the equaton
      // x^2 -nx + k^2 (where a + b = n and a * b = k^2)
      long long int &kk = _squares[k];

      // Start from current value
      long long int b = kk / a;

      // Find 'a + b' as expected 'n'
      long long int n = (a + b);

      // Find possible (x, y) as root ofthe equaton
      // p^2 -kp + n (where x + y = k and x * y = n)
      long long int d = (kk - (4 * n));
      if (d >= 0)
      {
        // Find solution
        long long int x = (k + sqrt(d) + 0.5) / 2;
        long long int y = k - x;

        // Find 'x * y' as expected 'n'
        if (n == (x * y))
        {
          // Store result
          _results.insert(n);

          // Display results
          std::cout << "[ " << k << " ]: "
                    << n
                    << " (" << a
                    << ", " << b
                    << ", " << x
                    << ", " << y << ") " << std::endl;
        }
      }

      //Skip all values of k where k^2 is not divisible by 'a'
      while (k > 0 && _squares[--k] % a)
        ;
    } while (k > 0);
  }

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