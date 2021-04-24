/*
 * A143293.h
 *
 *  Created on:  24-Apr-2021
 *  Modified on: 24-Apr-2021
 *  Author:      Soumyadeep Dhar
 * 
 *  A002110: Partial sums of A002110, the primorial numbers.
 *
 *  Example: 1, 3, 9, 39, 249, 2559, 32589, 543099, 10242789, 
 *           233335659, 6703028889, 207263519019, 7628001653829, 
 *           311878265181039, 13394639596851069, 628284422185342479  
 * 
 *  prime(n)#:      https://oeis.org/A002110/b002110.txt
 *  sum(prime(n)#): https://oeis.org/A143293/b143293.txt
 * 
 */

#ifndef A143293_H_
#define A143293_H_

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

// Integer Sequence - A143293
namespace a143293
{
  // Use LargeInt operations
  using LargeInteger = ns::dn::li::LargeInt;

  class A143293 : public IntegerSequenceProcessor
  {
  public:
    // Constructor with parameter
    A143293(std::string _ipath, std::string _gtpath, std::string _opath)
        : IntegerSequenceProcessor(_ipath, _gtpath, _opath)
    {
    }

    // Default destructor
    ~A143293()
    {
    }

    // Process input data to generate next elements of the sequence
    unsigned int generate();

  };

} // namespace a143293
} // namespace is
} // namespace dn
} // namespace ns

#endif // A143293_H_