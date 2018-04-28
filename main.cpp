#include <cmath>
#include <future>
#include <iostream>
#include <vector>
#include "part_sum.hpp"

int main()
{
  char c;
  std::cout << "type 'e' to interrupt" << std::endl;

  std::thread([]{
    std::vector<int> arr(1000000000, 1);
    std::cout << part_sum(arr, 2) << std::endl;
    exit(0);
  }).detach();

  while (std::cin >> c) {
    if (c == 'e') {
      std::cout << "got an abort command" << std::endl;
      exit(1);
    }
  }
}
