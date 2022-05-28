#include <IOKit/IOKitLib.h>
#include <boost/ut.hpp>
#include <pqrs/osx/kern_return.hpp>

int main(void) {
  using namespace boost::ut;
  using namespace boost::ut::literals;

  "kern_return"_test = [] {
    {
      pqrs::osx::kern_return r(KERN_SUCCESS);
      expect(r.to_string() == "KERN_SUCCESS");
      expect(r == true);
      expect(r.success() == true);
    }
    {
      pqrs::osx::kern_return r(KERN_INVALID_ADDRESS);
      expect(r.to_string() == "KERN_INVALID_ADDRESS");
      expect(r == false);
      expect(r.success() == false);
    }
    {
      pqrs::osx::kern_return r(KERN_PROTECTION_FAILURE);
      expect(r.to_string() == "KERN_PROTECTION_FAILURE");
      expect(r == false);
      expect(r.success() == false);
    }
    {
      pqrs::osx::kern_return r(123456);
      expect(r.to_string() == "Unknown kern_return_t (123456)");
      expect(r == false);
      expect(r.success() == false);
    }

    {
      io_name_t name;
      pqrs::osx::kern_return r = IOObjectGetClass(IO_OBJECT_NULL, name);
      expect(r.to_string() == "KERN_NO_SPACE");
      expect(r == false);
      expect(r.success() == false);
    }
  };

  return 0;
}
