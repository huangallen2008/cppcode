#include <cassert>
#include <cstdio>
#include <vector>

int minimum_garbage(const std::vector<int> &L, const std::vector<int> &R,
                    const std::vector<int> &J, const std::vector<int> &G);


int main() {
  int N;
    assert(scanf("%d", &N) == 1);
  std::vector<int> L(N), R(N);
  for (int i = 0; i < N; ++i) {
      assert(scanf("%d%d", &L[i], &R[i]) == 2);
  }
  int M;
    assert(scanf("%d", &M) == 1);
  std::vector<int> J(M);
  for (int i = 0; i < M; ++i) {
      assert(scanf("%d", &J[i]) == 1);
  }
  int K;
    assert(scanf("%d", &K) == 1);
  std::vector<int> G(K);
  for (int i = 0; i < K; ++i) {
      assert(scanf("%d", &G[i]) == 1);
  }
  printf("%d\n", minimum_garbage(L, R, J, G));
  return 0;
}

#include ""