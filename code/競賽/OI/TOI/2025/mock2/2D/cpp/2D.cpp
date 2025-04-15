#include <cstdio>
#include <cassert>
#include <vector>

namespace {
    int N;
    std::vector<std::vector<int>> regions;
} // 這裡可以儲存全域變數

void initialize(const std::vector<std::vector<int>> &S, int H, int L, int K) {
    N = S.size();
    regions = S;
}

double minimum_route(const std::vector<int> &T) {
    return 0;
}
