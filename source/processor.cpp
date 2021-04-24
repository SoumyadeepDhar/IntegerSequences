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

IntegerSequenceProcessor::IntegerSequenceProcessor
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

IntegerSequenceProcessor::~IntegerSequenceProcessor()
{
  _iDataStream.close();
  _gtDataStream.close();
  _oDataStream.close();
}

} // namespace is
} // namespace dn
} // namespace ns