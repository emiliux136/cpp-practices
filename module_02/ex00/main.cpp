#include "Fixed.hpp"

int main(void) {
  Fixed a;
  Fixed b(a);
  Fixed c;
  c = b;
  std::cout << a.getRawBits() << std::endl;
  std::cout << b.getRawBits() << std::endl;
  std::cout << c.getRawBits() << std::endl;
  c.setRawBits((int const)2);
  std::cout << c.getRawBits() << std::endl;
  c.setRawBits((int const)45);
  std::cout << c.getRawBits() << std::endl;
  
  return 0;
}