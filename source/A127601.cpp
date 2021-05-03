/*
 * A127601.cpp
 *
 *  Created on:  26-Apr-2021
 *  Modified on: 26-Apr-2021
 * 
 *  Author:  Soumyadeep Dhar
 * 
 *  A127601: Integer part of 4th root of product of first n primes 
 *           (n-th primorial) A002110(n).
 *
 *  Example: 1, 1, 2, 3, 6, 13, 26, 55, 122, 283, 669, 1650, 4176, 
 *           10694, 28002, 75555, 209402, 585212, 1674296, 4860120, 
 *           14206194, 42353033, 127836257,  
 * 
 *  A002110: https://oeis.org/A002110/a002110.txt
 *  A127601: https://oeis.org/A127601/b127601.txt
 * 
 *  Sequence Author: N. J. A. Sloane and J. H. Conway
 * 
 */

#include <math.h>
#include <float.h>
#include "largeint.h"
#include "processor.h"

using LargeInteger = ns::dn::li::LargeInt;
using LargeIntegerSequence = ns::dn::is::IntegerSequenceProcessor<ns::dn::is::A127601>;

// Evalution of output based on given ground truth
template <>
void LargeIntegerSequence::evaluate(std::pair<unsigned int, std::string> &_result)
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
    LargeInteger _t1(_result.second);
    LargeInteger _t2(_t1 + 1);
    _t1 = _t1.pow(4);
    _t2 = _t2.pow(4);
    if ((_t1 < _element.second) && (_t2 > _element.second))
    {
      std::cout << "\033[32m"
                << "[    OK    ]";
      std::cout << "\033[00m"
                << " ... " << _element.first << std::endl;
    }
    else
    {
      std::cout << "\033[31m"
                << "[  FAILED  ]";
      std::cout << "\033[00m"
                << " ... " << _element.first << ": " << std::endl;
      std::cout << "GT: " << _element.second << std::endl;
      std::cout << "RE: " << _result.second << std::endl;
    }
  }
  else
  {
    std::cout << "[   NO GT  ] ... " << _result.first << std::endl;
  }
}

// Process input data to generate next elements of the sequence
template <>
unsigned int LargeIntegerSequence::generate()
{
  static LargeInteger _value(0U);
  std::pair<unsigned int, std::string> _element;

  // Read input data
  _inReader >> _element;

  // Get input n
  _value = _element.second;

  // Calculate 4th root of nth primorial as result a(n)
  _value = _value.sqrt();
  _value = _value.sqrt();

  // Store result
  _element.second = _value.getValue();

  // Evaluate result
  evaluate(_element);

  // Write output data
  _ouWriter << _element;

  // Return number of digits in the element
  return _value.digits();
}

int main()
{
  // Initialize sequence
  LargeIntegerSequence seqA127601("../data/oeis/a002110.txt", "../data/oeis/a002110.txt", "../data/b127601.txt");

  // Create sequence with elements having maximum 1000 digits
  // while(seqA127601.generate() <= 1000);

  // Create 2000 elements or max 1000 digit element
  for (auto index = 0; index < 2000 && seqA127601.generate() < 1000; index++)
    ;

  return 0;
}
