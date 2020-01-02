#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <IOKit/IOKitLib.h>
#include <pqrs/osx/kern_return.hpp>

TEST_CASE("kern_return") {
  {
    pqrs::osx::kern_return r(KERN_SUCCESS);
    REQUIRE(r.to_string() == "KERN_SUCCESS");
    REQUIRE(r == true);
    REQUIRE(r.success() == true);
  }
  {
    pqrs::osx::kern_return r(KERN_INVALID_ADDRESS);
    REQUIRE(r.to_string() == "KERN_INVALID_ADDRESS");
    REQUIRE(r == false);
    REQUIRE(r.success() == false);
  }
  {
    pqrs::osx::kern_return r(KERN_PROTECTION_FAILURE);
    REQUIRE(r.to_string() == "KERN_PROTECTION_FAILURE");
    REQUIRE(r == false);
    REQUIRE(r.success() == false);
  }
  {
    pqrs::osx::kern_return r(123456);
    REQUIRE(r.to_string() == "Unknown kern_return_t (123456)");
    REQUIRE(r == false);
    REQUIRE(r.success() == false);
  }

  {
    io_name_t name;
    pqrs::osx::kern_return r = IOObjectGetClass(IO_OBJECT_NULL, name);
    REQUIRE(r.to_string() == "KERN_NO_SPACE");
    REQUIRE(r == false);
    REQUIRE(r.success() == false);
  }
}
