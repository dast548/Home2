#include <iostream>

int
main(int argc, char** argv)
{
  std::string name;
  // ask for user name.
  std::cout << "Enter your name: ";
  std::cin >> name;
  // выводим приветствие
  std::cout << "Hello world from @" << name << std::endl;
  return 0;
}
