#include <cassert>
#include <cstdio>
#include <vector>
#include <string>

std::string bicoloring(int N,
                       const std::vector<int> &U,
                       const std::vector<int> &V);

int main() {
  int n, m;
  assert(scanf("%d%d", &n, &m) == 2);
  std::vector<int> U(m), V(m);
  for (int i = 0; i < m; i++) {
    assert(scanf("%d%d", &U[i], &V[i]));
  }
  std::string C = bicoloring(n, U, V);
  printf("%s\n", C.c_str());
  return 0;
}

#include "2B.cpp"