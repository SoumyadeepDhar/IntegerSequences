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

#include "A067175.h"

// Sequence
using LargeIntegerSequence = ns::dn::is::a067175::A067175;

// Process input data to generate next elements of the sequence
unsigned int LargeIntegerSequence::generate()
{
  static LargeInteger _value(0U);
  std::pair<unsigned int, std::string> _element;

  // Read input data
  _iReader >> _element;

  // Update result
  _value = _element.second;
  _element.second = std::to_string(_value.digits());

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
  LargeIntegerSequence seqA067175("../data/b002110.txt", "../data/oeis/b067175.txt", "../data/b067175.txt");

  // Create sequence with elements having maximum 1000 digits
  // while(seqA067175.generate() <= 1000);

  // Create 350 elements
  for (auto index = 0; index < 350 && seqA067175.generate(); index++);

  return 0;
}
