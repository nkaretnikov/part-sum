#include <iostream>
#include <vector>
#include "part_sum.hpp"

int main()
{
  std::vector<int> arr;
  const size_t sz = 5;

  for (int i = 0; i < sz; ++i) {
    const size_t sz = arr.size();
    std::cout << "sz: " << sz << std::endl;
    std::cout << "elems:" << std::endl;
    for (auto it = arr.begin(); it != arr.end(); ++it) {
      std::cout << *it << std::endl;
    }

    for (int j = 1; j <= sz; ++j) {
      std::cout << "chunks: " << j << std::endl;
      std::cout << part_sum(arr, j) << std::endl;
    }

    std::cout << "----" << std::endl;
    arr.push_back(i + 1);
  }

  std::cout << part_sum(arr, 0) << std::endl;  // should fail: division by zero
}
