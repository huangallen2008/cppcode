#include <cstdio>
#include <cassert>
#include <vector>
#include <cstring>
#include <algorithm>

std::vector<int> coloring(int N, const std::vector<int> &U, const std::vector<int> &V);


int main() {
    int N, M;
    assert(scanf("%d %d", &N, &M) == 2);
    std::vector<int> U(M), V(M);
    for (int i = 0; i < M; i++) {
        assert(scanf("%d %d", &U[i], &V[i]) == 2);
    }
    auto color = coloring(N, U, V);
    for (int i = 0; i < N; i++)
        printf("%d%c", color[i], " \n"[i + 1 == N]);
}
