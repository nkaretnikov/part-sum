#include <future>
#include <numeric>
#include <vector>

// Partition 'arr' into 'n' pieces, calculate the sum of each piece in a
// separate thread, and return the total sum.
// XXX: Assumes the result fits into an 'int'.
int part_sum(const std::vector<int>& arr, size_t n)
{
  if (n == 0) {
    // XXX: Probably not a good idea to hardcode the function name here,
    // but '__FUNCTION__' is not standard.
    throw std::invalid_argument {"part_sum: n must be greater than 0"};
  }

  const size_t sz = arr.size() / n;

  // XXX: Change this if the return type changes.
  std::vector<std::future<int>> fsums;
  for (auto it = arr.begin(); it != arr.end(); it += sz) {
    // XXX: It's important to copy the iterator here.
    // Otherwise, it may get used after it gets destroyed.
    fsums.emplace_back(std::async(std::launch::async, [it, sz]{
      // XXX: The constant determines the result type.
      return std::accumulate(it, it + sz, 0);
    }));
  }

  // XXX: Change this if the return type changes.
  int sum = 0;
  for (auto it = fsums.begin(); it != fsums.end(); ++it) {
    sum += it->get();
  }

  return sum;
}
