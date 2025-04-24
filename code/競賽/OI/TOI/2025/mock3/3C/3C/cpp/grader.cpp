#include <cstdio>
#include <cassert>
#include <vector>
#include <cstring>

std::vector<std::vector<int>> minimum_stack(const std::vector<int> &W, const std::vector<int> &H, const std::vector<int> &R);


int main() {
    int N, M;
    assert(scanf("%d %d", &N, &M) == 2);
    std::vector<int> W(N), H(N), R(M);
    for (int &i : W) {
        assert(scanf("%d", &i) == 1);
    }
    for (int &i : H) {
        assert(scanf("%d", &i) == 1);
    }
    for (int &i : R) {
        assert(scanf("%d", &i) == 1);
    }

    auto ans = minimum_stack(W, H, R);
    printf("%d\n", int(ans.size()));
    for (int i = 0; i < int(ans.size()); i++)
        for (int j = 0; j < int(ans[i].size()); j++)
            printf("%d%c", ans[i][j], " \n"[j + 1 == int(ans[i].size())]);
}
