/*
 * A002110.cpp
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

#include "A002110.h"

// Sequence
using LargeIntegerSequence = ns::dn::is::a002110::A002110;

// Process input data to generate next elements of the sequence
unsigned int LargeIntegerSequence::generate()
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

  // Return number of digits in the element
  return _value.digits(); 
}

int main()
{
  // Initialize sequence
  LargeIntegerSequence seqA002110("../data/oeis/a000040.txt", "../data/oeis/a002110.txt", "../data/b002110.txt");

  // Create sequence with elements having maximum 1000 digits
  // while(seqA002110.generate() <= 1000);

  // Create 350 elements
  for (auto index = 0; index < 350 && seqA002110.generate(); index++);

  return 0;
}
