#include <Arguments.hpp>

#include <iostream>

namespace Charger {
namespace CommandLineArgs {

Arguments::Arguments()
  : mDesc("Allowed options")
{}

void Arguments::parse(int argc, const char** argv)
{
  namespace po = boost::program_options;

  mDesc.add_options()("help", "produce help message");
  mDesc.add_options()
      ("input-file,I", po::value<std::string>(&m_inputFilePath)->composing(),  "set input file path")
      ("output-file",  po::value<std::string>(&m_outputFilePath)->composing(), "set output file path")
      ;
  po::store(po::parse_command_line(argc, argv, mDesc), mMap);  // парсим переданные аргументы
  po::notify(mMap); // записываем аргументы в переменные в программе
}

void Arguments::handle() const
{
  if (mMap.count("help"))
  {
    // То выводим описание меню
    std::cerr << mDesc << std::endl;
    return;
  }

  if (mMap.count("input-file") && mMap.count("output-file"))
    std::cerr << "Input: " << m_inputFilePath << "\nOutput: " << m_outputFilePath << std::endl;
  else
  {
    std::cerr << "Please, use --help option for information" << std::endl;
    return;
  }
}

} // namespace CommandLineArgs
} // namespace Charger
