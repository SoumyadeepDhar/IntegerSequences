/*
 * processor.h
 *
 *  Created on: 23-Apr-2019
 *  Author: soumyadeep dhar
 */

#ifndef PROCESSOR_H_
#define PROCESSOR_H_

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

// Number system
namespace ns
{
// Decimal Number
namespace dn
{
// Integer Sequence
namespace is
{

// The On-Line Encyclopedia of Integer Sequences
enum  OEIS 
{
  A002110 = 2110,
  A067175 = 67175,
  A143293 = 143293
};
template <OEIS S>
class IntegerSequenceProcessor
{
public:
  // Internal reader structure
  typedef struct _reader_
  {
    // Input file stream
    std::ifstream &_ids;

    // Initialize reader
    _reader_(std::ifstream &ids) : _ids(ids)
    {
    }

    // Read input data
    std::ifstream &operator>>(std::pair<unsigned int, std::string> &_element)
    {
      if (_ids.good())
      {
        // Read data from stream
        _ids >> _element.first;
        _ids >> _element.second;
      }
      return _ids;
    }
  } Reader;

  // Internal writer structure
  typedef struct _writer_
  {
    // Output file stream
    std::ofstream &_ods;

    // Initialize reader
    _writer_(std::ofstream &ods) : _ods(ods)
    {
    }

    // Write output data
    std::ofstream &operator<<(std::pair<unsigned int, std::string> &_element)
    {
      if (_ods.good())
      {
        // Write output data to stream
        _ods << _element.first;
        _ods << " ";
        _ods << _element.second;
        _ods << std::endl;
      }
      return _ods;
    }
  } Writer;

  // Constructor with parameter
  IntegerSequenceProcessor(std::string _ipath, std::string _gtpath, std::string _opath);

  // Default destructor
  ~IntegerSequenceProcessor();

  // Evalution of output based on given ground truth
  virtual void evaluate(std::pair<unsigned int, std::string> &_result);

  // Process input data to generate next elements of the sequence
  virtual unsigned int generate();

protected:
  // Input file stream
  std::ifstream _iDataStream; //("test.txt", std::ifstream::in);

  // Ground truth file stream
  std::ifstream _gtDataStream;

  // Output file stream
  std::ofstream _oDataStream;

  // Input data reader
  Reader _iReader;

  // Ground truth data reader
  Reader _gtReader;

  // Output data writer
  Writer _oWriter;
};

// Explisit instanciation for all sequences
template class IntegerSequenceProcessor<SEQUENCE>;

} // namespace is
} // namespace dn
} // namespace ns

#endif // PROCESSOR_H_