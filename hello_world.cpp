#include <iostream>

int main(int argc, char** argv)
{
  std::string name;
  // запрашиваем имя пользователя
  std::cout << "Enter your name: ";
  std::cin >> name;
  // выводим приветствие
  std::cout << "Hello world from @" << name << std::endl;
  return 0;
}
