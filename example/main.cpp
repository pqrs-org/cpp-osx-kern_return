#include <pqrs/osx/kern_return.hpp>

int main(void) {
  {
    pqrs::osx::kern_return r(KERN_SUCCESS);
    std::cout << r << std::endl;
  }

  {
    pqrs::osx::kern_return r(54321);
    std::cout << r << std::endl;
  }

  return 0;
}
