/*
 * A002110.h
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

#ifndef A002110_H_
#define A002110_H_

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

// Integer Sequence - A002110
namespace a002110
{
  // Use LargeInt operations
  using LargeInteger = ns::dn::li::LargeInt;

  class A002110 : public IntegerSequenceProcessor
  {
  public:
    // Constructor with parameter
    A002110(std::string _ipath, std::string _gtpath, std::string _opath)
        : IntegerSequenceProcessor(_ipath, _gtpath, _opath)
    {
    }

    // Default destructor
    ~A002110()
    {
    }

    // Process input data to generate next elements of the sequence
    unsigned int generate();

  };

} // namespace a002110
} // namespace is
} // namespace dn
} // namespace ns

#endif // A002110_H_