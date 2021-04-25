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
  A060797 = 60797,
  A067175 = 67175,
  A143293 = 143293
  
};
template <OEIS S>
class IntegerSequenceProcessor
{
public:
  // Internal reader structure
  class Reader
  {
  private:
    // Input file stream
    std::ifstream &_ids;

  public:
    // Initialize reader
    Reader(std::ifstream &ids) : _ids(ids)
    {
    }

    // Destructor Reader
    ~Reader()
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
  };

  // Internal writer structure
  class Writer
  {
  private:
    // Output file stream
    std::ofstream &_ods;

  public:
    // Initialize reader
    Writer(std::ofstream &ods) : _ods(ods)
    {
    }

    // Destrctor Writer
    ~Writer()
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
  };

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
  std::ifstream _inDataStream; //("test.txt", std::ifstream::in);

  // Ground truth file stream
  std::ifstream _gtDataStream;

  // Output file stream
  std::ofstream _ouDataStream;

  // Input data reader
  Reader _inReader;

  // Ground truth data reader
  Reader _gtReader;

  // Output data writer
  Writer _ouWriter;
};

// Explisit instanciation for all sequences
template class IntegerSequenceProcessor<SEQUENCE>;

} // namespace is
} // namespace dn
} // namespace ns

#endif // PROCESSOR_H_