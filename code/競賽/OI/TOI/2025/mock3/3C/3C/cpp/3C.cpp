#include <vector>

std::vector<std::vector<int>> minimum_stack(const std::vector<int> &W, const std::vector<int> &H, const std::vector<int> &R) {
    int N = W.size();
    int M = R.size();
    return std::vector<std::vector<int>>(N + M); 
}
