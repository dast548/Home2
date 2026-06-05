#include <iostream>

int main(int argc, char** argv)
{
  std::string name;
  std::cout << "Enter your name: ";
  std::cin >> name;
  std::cout << "Hello world from @" << name << std::endl;
  return 0;
}
