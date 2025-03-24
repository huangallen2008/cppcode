#include <cstdio>
#include <cassert>
#include <vector>

int maximum_length(const std::vector<int> &UX, const std::vector<int> &UY, 
                   const std::vector<int> &DX, const std::vector<int> &DY);

int main() {
    int n;
    assert(scanf("%d", &n) == 1);
    std::vector<int> UX(2 * n), UY(2 * n);
    for (int i = 0; i < 2 * n; i++)
        assert(scanf("%d %d", &UX[i], &UY[i]) == 2);
    int m;
    assert(scanf("%d", &m) == 1);
    std::vector<int> DX(2 * m), DY(2 * m);
    for (int i = 0; i < 2 * m; i++)
        assert(scanf("%d %d", &DX[i], &DY[i]) == 2);
    int ans = maximum_length(UX, UY, DX, DY);
    printf("%d\n", ans);
}
