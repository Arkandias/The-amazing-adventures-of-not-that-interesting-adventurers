
#include <iostream>
#include "UIInterface.hpp"

int main()
{
  UIInterface test;

  std::cout << "test" << std::endl;
  test.Write("Type any character to see it in bold\n");
  test.Refresh();
  test.Getch();
  return 0;
}
