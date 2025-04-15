#include <string>
#include <vector>

std::string bicoloring(int N,
                       const std::vector<int> &U,
                       const std::vector<int> &V) {
  size_t M = U.size();
  return std::string(M, 'R');
}
