#include <string>
#include <vector>

std::vector<std::string> reveal(const std::vector<std::string> &P);

std::string missing_string(int N, int M) {
    std::vector<std::string> P(N, std::string(M, '1'));
    std::vector<std::string> S = reveal(P);
    return std::string(M, '0');
}
