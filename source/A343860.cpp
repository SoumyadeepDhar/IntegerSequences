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

#include <map>
#include <tuple>
#include <iomanip>

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
    std::vector <unsigned long long int> factors = LargeInteger::factor(kk);

    // Check all possible values of expected 'm'
    for(auto f = factors.begin() + 1; f != factors.end(); ++f)
    {
      // Find possible (a, b) as root of the equation
      // x^2 -mx + k^2 (where a + b = m and a * b = k^2)
      long long int a = *f;
      long long int b = kk / a;

      // Ignore repeated operands
      if(a > b) break;
      
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
        _results[m] = std::make_tuple(a, b, x, y, k);

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

    if(_count < 11)
    {
      // Print output results
      std::cout <<  " " << std::setw(4) << _count;
      std::cout <<  " " << std::setw(4) << std::get<4>(_x.second);
      std::cout <<  " " << std::setw(4) << _x.first;
      std::cout <<  " " << std::setw(4) << (std::get<4>(_x.second) * std::get<4>(_x.second));
      std::cout <<  " " << std::setw(4) << std::get<0>(_x.second);
      std::cout <<  " " << std::setw(4) << std::get<1>(_x.second);
      std::cout <<  " " << std::setw(4) << std::get<2>(_x.second);
      std::cout <<  " " << std::setw(4) << std::get<3>(_x.second) << std::endl;
    }

    //Update element count
    _count++;
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