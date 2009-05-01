#include <iostream>
#include <string>

#include <boost/program_options.hpp>
namespace po = boost::program_options;

using namespace std;

int main(int argc, char** argv) {
  // Declare the supported options.

  po::options_description desc("Allowed options");
  desc.add_options()
    ("help,?", "produce help message")
    ("target,t", po::value<string>(), "target hash")
    ("charset,c", po::value<string>(), "charset")
  ;

  po::variables_map vm;
  po::store(po::parse_command_line(argc, argv, desc), vm);
  po::notify(vm);    

  if (vm.count("help")) {
      cout << desc << "\n";
      return 0;
  }

  if (!vm.count("target")) {
    cerr << "Target hash needed." << endl;
    return 1;
  }
  
  if (!vm.count("charset")) {
    cerr << "Character set needed." << endl;
    return 1;
  }
  
  //cout << "Target: " << vm["target"].as<string>() << endl;
  //cout << "Charset: " << vm["charset"].as<string>() << endl;
  
  return 0;
}
