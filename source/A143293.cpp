/*
 * A143293.cpp
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

#include "A143293.h"

// Sequence
using LargeIntegerSequence = ns::dn::is::a143293::A143293;

// Process input data to generate next elements of the sequence
unsigned int LargeIntegerSequence::generate()
{
  static LargeInteger _value(0U);
  std::pair<unsigned int, std::string> _element;

  // Read input data
  _iReader >> _element;

  // Update result
  _value += _element.second;
  _element.second = _value.getValue();

  // Evaluate result
  evaluate(_element);

  // Write output data
  _oWriter << _element;

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
