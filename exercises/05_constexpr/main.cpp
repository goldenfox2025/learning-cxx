#include "../exercise.h"

constexpr unsigned long long fibonacci(int i) {
  if (i == 0) return 0;
  if (i == 1) return 1;
  unsigned long long a = 0, b = 1;
  for (int n = 2; n <= i; ++n) {
    unsigned long long temp = a + b;
    a = b;
    b = temp;
  }
  return b;
}

int main(int argc, char **argv) {
  constexpr auto FIB20 = fibonacci(20);
  ASSERT(FIB20 == 6765, "fibonacci(20) should be 6765");
  std::cout << "fibonacci(20) = " << FIB20 << std::endl;

  const auto ANS_N = 90;
  const auto ANS = fibonacci(ANS_N);
  std::cout << "fibonacci(" << ANS_N << ") = " << ANS << std::endl;

  return 0;
}
