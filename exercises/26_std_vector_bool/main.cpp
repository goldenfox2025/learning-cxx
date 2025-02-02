#include <vector>

#include "../exercise.h"

int main(int argc, char **argv) {
  std::vector<bool> vec(100, true);  // 100 elements, each initialized to true
  ASSERT(vec[0], "Make this assertion pass.");
  ASSERT(vec[99], "Make this assertion pass.");
  ASSERT(vec.size() == 100, "Make this assertion pass.");
  // NOTICE: 平台相关！注意 CI:Ubuntu 上的值。
  std::cout << "sizeof(std::vector<bool>) = " << sizeof(std::vector<bool>)
            << std::endl;
  ASSERT(sizeof(vec) == 40, "Fill in the correct value.");
  {
    vec[20] = false;
    ASSERT(!vec[20], "Fill in `vec[20]` or `!vec[20]`.");
  }
  {
    vec.push_back(false);
    ASSERT(vec.size() == 101, "Fill in the correct value.");
    ASSERT(!vec[100], "Fill in `vec[100]` or `!vec[100]`.");
  }
  {
    auto ref = vec[30];
    ASSERT(ref, "Fill in `ref` or `!ref`");  // initially true
    ref = false;
    ASSERT(!ref, "Fill in `ref` or `!ref`");  // now false
    // 因为 ref 是 vector<bool>::reference，赋值后会更新 vec[30]
    ASSERT(!vec[30], "Fill in `vec[30]` or `!vec[30]`.");
  }
  return 0;
}
