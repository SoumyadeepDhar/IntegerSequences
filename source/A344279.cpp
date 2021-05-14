/*
 * A344279.cpp
 *
 *  Created on:  14-May-2021
 * 
 *  Author:  Soumyadeep Dhar
 * 
 *  A344279: Numbers a(n)=m such that |m| is the smallest, k=n*m and r=(n^2+1)*m 
 *           for two quadratic equations of the form t^2+k*t+r = 0 and t^2+r*t+k^2 = 0 
 *           have non-zero integer roots, where k is the coefficient of t and r is the 
 *           constant in first equation, which has non-zero roots p and q 
 *           (i.e., {k, r, p, q} ∈ ℤ≠, k=p+q and r=p*q). Also r is the coefficient of t 
 *           and k^2 is the constant in second equation, which has non-zero roots u and v 
 *           (i.e., {r, k, u, v} ∈ ℤ≠, r=u+v and k^2=u*v).
 *
 *  Example: -1, -4, -1, -16, 9, -36, 5, -1, -81, -100, -121, -4, 9, -196, -225, 
 *           -256, 8, 5, -361, -400, -1, -484, -529, -576, -625, -676, -729, -784, 
 *           -841, -900, -961, -1024, -9, 9, -1225, -1296, -1369, -1444, -1521, 
 *           -1600, -1681, -1764, -1849, -1936, -2025, -2116, 5, -2304, -2401, -2500  
 * 
 *  A344279: https://oeis.org/A344279/b344279.txt
 * 
 *  Sequence Author:  Soumyadeep Dhar, May 14, 2021
 * 
 */

#include <map>
#include <tuple>
#include <iomanip>

#include "largeint.h"
#include "processor.h"

using LargeInteger = ns::dn::li::LargeInt;
using LargeIntegerSequence = ns::dn::is::IntegerSequenceProcessor<ns::dn::is::A344279>;

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
    , long long int
    , long long int
    , long long int
    , long long int>> _results;

  for (long long int n = 1; n <= 225; n++)
  {
    // Check all numbers upto 100
    for (long long int c = 1; c <= 250000; c++)
    {
      bool isFound = false;
      for (auto s : {1, -1})
      {
        // Find 'a * b' as initial expected 'm'
        long long int m = s*c*(n*n + 1);

        // Find 'a * b' as initial expected 'k'
        long long int k = s*c*n;

        // Get k^2 value
        long long int kk = (k * k);

        // Find possible (a, b) as root of the equation
        // x^2 -kx + m (where a + b = k and a * b = m)
        long long int a = (k + sqrt(kk - (4 * m))) / 2;
        long long int b = k - a;

        // Ignore non integer roots
        if(m != (a * b)) continue;

        // For all possible roots of the equation
        // x^2 - mx + k^2 (where x + y = m and x * y = k^2)
        long long int y = (m + sqrt((m * m) - (4 * kk))) / 2;
        long long int x = m - y;

        // If valid roots found
        if (kk != (x * y)) continue;
          
        // Store result
        _results[n] = std::make_tuple(c*s, k, m, kk, a, b, x, y);

        // Print output results
        std::cout <<  " " << std::setw(9) << n;
        std::cout <<  " " << std::setw(9) << c*s;      
        std::cout <<  " " << std::setw(9) << k;
        std::cout <<  " " << std::setw(9) << m;
        std::cout <<  " " << std::setw(9) << kk;
        std::cout <<  " " << std::setw(9) << a;
        std::cout <<  " " << std::setw(9) << b;
        std::cout <<  " " << std::setw(9) << x; 
        std::cout <<  " " << std::setw(9) << y << std::endl;

        // Mark solution found
        isFound = true;
        break;
      }

      // No need to search further as result already found 
      if(isFound) break;
    }
  }

  // Store shorted result  data
  _count = 1;
  for (auto _x : _results)
  {
    _element.first = _count;
    _element.second = std::to_string(std::get<0>(_x.second));

    // Write output data
    _ouWriter << _element;

    // Update element count
    _count++;
  }

  return 0;
}

int main()
{
  // Initialize sequence
  LargeIntegerSequence seqA344279("../data/oeis/b000290.txt", "../data/oeis/b000290.txt", "../data/A344279.txt");

  // Generate sequence
  seqA344279.generate();

  return 0;
}