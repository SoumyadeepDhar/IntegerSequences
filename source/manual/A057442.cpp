/*
 * A057442.cpp
 *
 *  Created on:  11-May-2021
 * 
 *  Author:  Soumyadeep Dhar
 * 
 *  A057442: Numbers w such that w=k^2 and the two equations t^2-k*t+m = 0 and 
 *           t^2-m*t+k^2 = 0 have positive integer roots. m is the constant 
 *           and k is the coefficient of t in first equation, which has roots 
 *           p and q (i.e., {k, m, p, q} ∈ ℤ+, k=p+q and m=p*q). Also k^2 is 
 *           the constant and m is the coefficient of t in second equation, 
 *           which has roots u and v (i.e., {k, m, u, v} ∈ ℤ+, m=u+v and k^2=u*v).
 *
 *  Example: 16, 18, 25, 45, 50, 80, 234, 250, 261, 425, 1025, 1040, 1530, 
 *           1625, 1746, 2320, 4250, 7605, 7794, 9650,  
 * 
 *  A057442: https://oeis.org/A057442/b057442.txt
 * 
 *  Sequence Author:  Naohiro Nomoto, Sep 24, 2000
 * 
 */

#include <map>
#include <tuple>
#include <iomanip>

#include "largeint.h"
#include "processor.h"

using LargeInteger = ns::dn::li::LargeInt;
using LargeIntegerSequence = ns::dn::is::IntegerSequenceProcessor<ns::dn::is::A057442>;

// Process input data to generate next elements of the sequence
template <>
unsigned int LargeIntegerSequence::generate()
{
  int _count = 1;
  std::pair<unsigned int, std::string> _element;

  // keep result values
  std::map<long long int, std::tuple
    < long long int
    , long long int
    , long long int
    , long long int
    , long long int>> _results;

  // Check all numbers upto 5000000
  for (long long int k = 8; k <= 5000000; k++)
  {
    // std::cout << std::endl << "k: " << k << " <> ";

    // Get k^2 value
    long long int kk = (k * k);
    std::vector <unsigned long long int> factors = LargeInteger::Factor(kk);

    auto bp = factors.begin();
    auto ep = factors.end() - 1;
    // Check all possible values of expected 'm'
    while(bp < ep)
    {
      // Move to next factor
      ++bp; --ep;

      // Find possible (a, b) as root of the equation
      // x^2 -mx + k^2 (where a + b = m and a * b = k^2)
      long long int a = *bp;
      long long int b = *ep;

      // Find 'x * y' as initial expected 'm' as a + b
      long long int m = a + b;

      // Ignore negative discriminant
      if(kk < (4 * m)) continue;

      // Get discriminant value
      long long int s = sqrt((k * k) - (4 * m));

      // For all possible roots of the equation
      // x^2 - kx + m (where x + y = k & xy = m)
      long long int y = (k + s) / 2;
      long long int x = k - y;
      // std::cout << "k: " << k << " kk: " << kk << " (a*b): " << (a * b) << " a: " << a << " b: " << b << " s: " << s << " m: " << m << " x: " << x << " y: " << y << std::endl;

      // If valid roots found
      if ((x * y) == m)
      {
        // Store result
        _results[m] = std::make_tuple(a, b, x, y, kk);

        // Print output results
        std::cout <<  " " << std::setw(14) << k;
        std::cout <<  " " << std::setw(14) << m;
        std::cout <<  " " << std::setw(14) << a;
        std::cout <<  " " << std::setw(14) << b;
        std::cout <<  " " << std::setw(14) << x; 
        std::cout <<  " " << std::setw(14) << y << std::endl;
      }
    }
  }

  // Store shorted result  data
  _count = 1;
  for (auto _x : _results)
  {
    _element.first = _count;
    _element.second = std::to_string(std::get<4>(_x.second));

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
  LargeIntegerSequence seqA057442("../data/oeis/b000290.txt", "../data/oeis/b000290.txt", "../data/b057442.txt");

  // Generate sequence
  seqA057442.generate();

  return 0;
}