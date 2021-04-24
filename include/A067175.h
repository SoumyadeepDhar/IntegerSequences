/*
 * A067175.h
 *
 *  Created on:  24-Apr-2021
 *  Modified on: 24-Apr-2021
 *  Author:      Soumyadeep Dhar
 * 
 *  A002110: Number of digits in the n-th primorial (A002110).
 *           Primorial numbers (first definition): product of first n primes. 
 *           Sometimes written prime(n)# (A002110).
 *
 *  Example: 1, 1, 1, 2, 3, 4, 5, 6, 7, 9, 10, 12, 13, 15, 17, 18, 20, 22, 24, 25, 
 *           27, 29, 31, 33, 35, 37, 39, 41, 43, 45, 47, 49, 51, 53, 56, 58, 60  
 * 
 *  A002110: https://oeis.org/A002110/a002110_1.txt
 *  A067175: https://oeis.org/A067175/b067175.txt
 * 
 */

#ifndef A067175_H_
#define A067175_H_

#include <string>
#include "processor.h"
#include "largeint.h"

// Number system
namespace ns
{
// Decimal Number
namespace dn
{
// Integer Sequence
namespace is
{

// Integer Sequence - A067175
namespace a067175
{
  // Use LargeInt operations
  using LargeInteger = ns::dn::li::LargeInt;

  class A067175 : public IntegerSequenceProcessor
  {
  public:
    // Constructor with parameter
    A067175(std::string _ipath, std::string _gtpath, std::string _opath)
        : IntegerSequenceProcessor(_ipath, _gtpath, _opath)
    {
    }

    // Default destructor
    ~A067175()
    {
    }

    // Process input data to generate next elements of the sequence
    unsigned int generate();

  };

} // namespace a067175
} // namespace is
} // namespace dn
} // namespace ns

#endif // A002110_H_