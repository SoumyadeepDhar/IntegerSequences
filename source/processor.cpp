/*
 * processor.cpp
 *
 *  Created on: 23-Apr-2019
 *  Author: soumyadeep dhar
 */

#include <stdlib.h>
#include "processor.h"

// Number system
namespace ns
{
// Decimal Number
namespace dn
{
// Integer Sequence
namespace is
{

template <OEIS S>
IntegerSequenceProcessor<S>::IntegerSequenceProcessor
  ( std::string _inpath
  , std::string _gtpath
  , std::string _oupath)
    : _inDataStream(_inpath.c_str(), std::ifstream::in)
    , _inReader(_inDataStream)
    , _gtDataStream(_gtpath.c_str(), std::ifstream::in)
    , _gtReader(_gtDataStream)
    , _ouDataStream(_oupath.c_str(), std::ifstream::out | std::ifstream::trunc)
    , _ouWriter(_ouDataStream)
{
}

template <OEIS S>
IntegerSequenceProcessor<S>::~IntegerSequenceProcessor()
{
  _inDataStream.close();
  _gtDataStream.close();
  _ouDataStream.close();
}

// Evalution of output based on given ground truth
template <OEIS S>
void IntegerSequenceProcessor<S>::evaluate(std::pair<unsigned int, std::string> &_result)
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

// Evalution of output based on given ground truth
template <OEIS S>
unsigned int IntegerSequenceProcessor<S>::generate()
{
  return 0U;
}

} // namespace is
} // namespace dn
} // namespace ns