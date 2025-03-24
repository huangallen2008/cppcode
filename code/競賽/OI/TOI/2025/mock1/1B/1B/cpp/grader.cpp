#include <cassert>
#include <cstdio>
#include <vector>

std::vector<long long> compute_defense(
  int N,
  const std::vector<int> &C,
  const std::vector<int> &U,
  const std::vector<int> &V,
  const std::vector<int> &W);

int main() {
  int n, m;
  assert(scanf("%d%d", &n, &m) == 2);
  std::vector<int> C(n);
  for (int i = 0; i < n; i++) {
    assert(scanf("%d", &C[i]) == 1);
  }
  std::vector<int> U(m), V(m), W(m);
  for (int i = 0; i < m; i++) {
    assert(scanf("%d%d%d", &U[i], &V[i], &W[i]) == 3);
  }
  std::vector<long long> D = compute_defense(n, C, U, V, W);
  printf("%lld", D[0]);
  for (int i = 1; i < n; i++) {
    printf(" %lld", D[i]);
  }
  printf("\n");
  return 0;
}

