#include "json.hpp"

#include <iterator>
#include <iostream>
#include <string>
#include <fstream>


int main(int argc, char* argv[])
{
    std::ifstream jsonFile("cpp.json");
    std::string word;
    while (jsonFile >> word)
    {
      std::cout << word;
    }


  return 0;
}
