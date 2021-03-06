/*
 * A143293.cpp
 *
 *  Created on:  24-Apr-2021
 *  Modified on: 24-Apr-2021
 * 
 *  Author:  Soumyadeep Dhar
 * 
 *  A143293: Partial sums of A002110, the primorial numbers.
 *
 *  Example: 1, 3, 9, 39, 249, 2559, 32589, 543099, 10242789, 
 *           233335659, 6703028889, 207263519019, 7628001653829, 
 *           311878265181039, 13394639596851069, 628284422185342479,  
 * 
 *  A002110: https://oeis.org/A002110/b002110.txt
 *  A143293: https://oeis.org/A143293/b143293.txt
 * 
 *  Sequence Author: Gary W. Adamson, Aug 05, 2008
 * 
 */

#include "largeint.h"
#include "processor.h"

using LargeInteger = ns::dn::li::LargeInt;
using LargeIntegerSequence = ns::dn::is::IntegerSequenceProcessor<ns::dn::is::A143293>;

// Process input data to generate next elements of the sequence
template <>
unsigned int LargeIntegerSequence::generate()
{
  static LargeInteger _value(0U);
  std::pair<unsigned int, std::string> _element;

  // Read input data
  _inReader >> _element;

  // Update result
  _value += _element.second;
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
  LargeIntegerSequence seqA143293("../data/oeis/a002110.txt", "../data/oeis/b143293.txt", "../data/b143293.txt");

  // Create sequence with elements having maximum 1000 digits
  while(seqA143293.generate() <= 1000);

  return 0;
}
