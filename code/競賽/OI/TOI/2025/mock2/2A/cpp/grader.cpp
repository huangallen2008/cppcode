#include <cassert>
#include <cstdio>
#include <vector>
#include "2A.cpp"
std::vector<long long> maximum_profit(const std::vector<int> &A,
                                      const std::vector<int> &Q);

int main() {
  int N, M;
  assert(scanf("%d %d", &N, &M) == 2);
  std::vector<int> A(N), Q(M);
  for (int i = 0; i < N; ++i) {
    assert(scanf("%d", &A[i]) == 1);
  }
  for (int i = 0; i < M; ++i) {
    assert(scanf("%d", &Q[i]) == 1);
  }
  auto ans = maximum_profit(A, Q);
  for (int i = 0; i < M; ++i) {
    printf("%lld%c", ans[i], " \n"[i + 1 == M]);
  }
  return 0;
}
