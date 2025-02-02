#include <string>
#include <type_traits>

#include "../exercise.h"

int main(int argc, char **argv) {
  using namespace std::string_literals;
  auto hello = "Hello"s;
  auto world = "world";
  ASSERT((std::is_same_v<decltype(hello), std::string>),
         "Fill in the missing type.");
  ASSERT((std::is_same_v<decltype(world), const char *>),
         "Fill in the missing type.");
  ASSERT(hello + ", " + world + '!' == "Hello, world!",
         "Fill in the missing string.");
  return 0;
}
