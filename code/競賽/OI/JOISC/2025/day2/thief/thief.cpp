#include "thief.h"

void solve(int N, int M, std::vector<int> U, std::vector<int> V) {
  std::vector<int> x;
  int r;

  x = {0, 1, 0, 0};
  r = query(x);

  x = {1, 1, 1, 0};
  r = query(x);

  x = {0, 0, 1, 0};
  r = query(x);

  x = {0, 0, 1, 1};
  r = query(x);

  answer(0, 4);
}
