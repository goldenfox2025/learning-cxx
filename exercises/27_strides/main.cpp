#include <vector>

#include "../exercise.h"

using udim = unsigned int;

std::vector<udim> strides(std::vector<udim> const &shape) {
  std::vector<udim> strides(shape.size());
  if (shape.empty()) return strides;
  // 最后一维步长为1
  strides.back() = 1;
  // 从倒数第二维开始计算，每一维的步长等于后一维的步长乘以后一维的尺寸
  for (int i = static_cast<int>(shape.size()) - 2; i >= 0; --i) {
    strides[i] = strides[i + 1] * shape[i + 1];
  }
  return strides;
}

// ---- 不要修改以下代码 ----
int main(int argc, char **argv) {
  ASSERT((strides({2, 3, 4}) == std::vector<udim>{12, 4, 1}),
         "Make this assertion pass.");
  ASSERT((strides({3, 4, 5}) == std::vector<udim>{20, 5, 1}),
         "Make this assertion pass.");
  ASSERT(
      (strides({1, 3, 224, 224}) == std::vector<udim>{150528, 50176, 224, 1}),
      "Make this assertion pass.");
  ASSERT((strides({7, 1, 1, 1, 5}) == std::vector<udim>{5, 5, 5, 5, 1}),
         "Make this assertion pass.");
  return 0;
}
