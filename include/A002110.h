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

    // Evalution of output based on given ground truth
    void evaluate(std::pair<unsigned int, std::string> &_result)
    {
      std::pair<unsigned int, std::string> _element;

      // Read ground truth data
      do
      { // Store in _element
        _gtReader >> _element;

        // Untill filedescribter is valid and matching elemnt not found
      } while (_gtDataStream.good() && _element.first < _result.first);

      // Check index postion for both data
      if (_element.first == _result.first)
      {
        if (_element.second == _result.second)
        {
          std::cout << "[    OK    ] ... " << _element.first << std::endl;
        }
        else
        {
          std::cout << "[  FAILED  ] ... " << _element.first << ": " << std::endl;
          std::cout << "[  FAILED  ] ... "
                    << "GT: " << _element.second << std::endl;
          std::cout << "[  FAILED  ] ... "
                    << "RE: " << _result.second << std::endl;
        }
      }
      else
      {
        std::cout << "[   NO GT  ] ... " << _result.first << std::endl;
      }
    }

    // Process input data to generate next elements of the sequence
    void generate()
    {
      static LargeInteger _value(1U);
      std::pair<unsigned int, std::string> _element;

      // Read input data
      _iReader >> _element;

      // Update result
      _value *= _element.second;
      _element.second = _value.getValue();

      // Evaluate result
      evaluate(_element);

      // Write output data
      _oWriter << _element;
    }
  };

} // namespace a002110
} // namespace is
} // namespace dn
} // namespace ns

#endif // A002110_H_