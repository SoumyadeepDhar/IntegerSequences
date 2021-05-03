/*
 * A060797.cpp
 *
 *  Created on:  25-Apr-2021
 *  Modified on: 25-Apr-2021
 * 
 *  Author:  Soumyadeep Dhar
 * 
 *  A060797: Integer part of square root of n-th primorial, A002110(n).
 *
 *  Example: 1, 1, 2, 5, 14, 48, 173, 714, 3114, 14936, 80434, 447839, 
 *           2724103, 17442771, 114379899, 784149081, 5708691485, 
 *           43849291330, 342473913399,  
 * 
 *  A002110: https://oeis.org/A002110/a002110.txt
 *  A060797: https://oeis.org/A060797/b060797.txt
 * 
 *  Sequence Author: Labos Elemer, Apr 27 2001
 * 
 */

#include <math.h>
#include <float.h>
#include "largeint.h"
#include "processor.h"

using LargeInteger = ns::dn::li::LargeInt;
using LargeIntegerSequence = ns::dn::is::IntegerSequenceProcessor<ns::dn::is::A060797>;

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
    _t1 = _t1.pow(2);
    _t2 = _t2.pow(2);
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

  // Calculate sqrt result a(n)
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
  LargeIntegerSequence seqA060797("../data/oeis/a002110.txt", "../data/oeis/a002110.txt", "../data/b060797.txt");

  // Create sequence with elements having maximum 1000 digits
  // while(seqA060797.generate() <= 1000);

  // Create 1000 elements or max 1000 digit element
  for (auto index = 0; index < 1000 && seqA060797.generate() < 1000; index++)
    ;

  return 0;
}
