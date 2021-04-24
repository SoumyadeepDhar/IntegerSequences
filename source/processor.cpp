/*
 * processor.cpp
 *
 *  Created on: 23-Apr-2019
 *  Author: soumyadeep dhar
 */

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
  ( std::string _ipath
  , std::string _gtpath
  , std::string _opath)
    : _iDataStream(_ipath.c_str(), std::ifstream::in)
    , _iReader(_iDataStream)
    , _gtDataStream(_gtpath.c_str(), std::ifstream::in)
    , _gtReader(_gtDataStream)
    , _oDataStream(_opath.c_str(), std::ifstream::out | std::ifstream::trunc)
    , _oWriter(_oDataStream)
{
}

template <OEIS S>
IntegerSequenceProcessor<S>::~IntegerSequenceProcessor()
{
  _iDataStream.close();
  _gtDataStream.close();
  _oDataStream.close();
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

// Evalution of output based on given ground truth
template <OEIS S>
unsigned int  IntegerSequenceProcessor<S>::generate()
{
  return 0U;
}

// Explisit instanciation for all sequences
template class IntegerSequenceProcessor<A002110>;
template class IntegerSequenceProcessor<A143293>;
template class IntegerSequenceProcessor<A067175>;

} // namespace is
} // namespace dn
} // namespace ns