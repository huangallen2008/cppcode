#include <cstdio>
#include <cassert>
#include <vector>
#include <cstring>

void initialize(const std::vector<std::vector<int>> &S, int H, int L, int K);

double minimum_route(const std::vector<int> &T);


int main() {
    int N, H, L, K;
    assert(scanf("%d %d %d %d", &N, &H, &L, &K) == 4);
    std::vector<std::vector<int>> S(N);
    for (auto &region : S) {
        int a;
        assert(scanf("%d", &a) == 1);
        region.resize(a);
        for (int &x : region) {
            assert(scanf("%d", &x) == 1);
        }
    }
    int Q;
    assert(scanf("%d", &Q) == 1);
    std::vector<std::vector<int>> querys(Q);
    for (auto &query : querys) {
        int b;
        assert(scanf("%d", &b) == 1);
        query.resize(b);
        for (int &index : query) {
            assert(scanf("%d", &index) == 1);
        }
    }
    initialize(S, H, L, K);
    for (int i = 0; i < Q; i++) {
        double res = minimum_route(querys[i]);
        printf("%.15lf\n", res);
    }
}
