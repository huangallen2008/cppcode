#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <string>

namespace {
    const int MAXM = 2000;
    char buffer[MAXM + 5];
    int N, M, current_case, current_reveal_count;
    bool queried_flag;
    std::vector<std::string> hidden_strings;
    void case_wrong_answer(const std::string &msg) {
        printf("Case %d Wrong Answer: %s\n", current_case, msg.c_str());
        exit(0);
    }
    void wrong_answer(const std::string &msg) {
        printf("Wrong Answer: %s\n", msg.c_str());
    }
    void accepted(const std::string &msg) {
        printf("Accepted: %s\n", msg.c_str());
    }
    std::string read_string() {
        assert(scanf("%s", buffer) == 1);
        return std::string(buffer);
    }
    bool verify_string_format(const std::string &s) {
        if (int(s.size()) != M) return false;
        for (char c : s)
            if (c != '0' && c != '1')
                return false;
        return true;
    }
    bool same_string(const std::string &a, const std::string &b) {
        for (int i = 0; i < int(a.size()); i++) {
            if (a[i] != b[i]) return false;
        }
        return true;
    }
} // global variables

std::string missing_string(int N, int M);

std::vector<std::string> reveal(const std::vector<std::string> &P) {
    if (queried_flag) case_wrong_answer("Second call of reveal");
    if (int(P.size()) != N) case_wrong_answer("Incorrect number of strings");
    for (const auto &s : P)
        if (!verify_string_format(s)) 
            case_wrong_answer("Incorrect string format");
    queried_flag = true;
    current_reveal_count = 0;
    std::vector<std::string> res(N, std::string(M, '*'));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (P[i][j] == '1')
                current_reveal_count += 1;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (P[i][j] == '1')
                res[i][j] = hidden_strings[i][j];
    return res;
}

int main() {
    int T;
    assert(scanf("%d", &T) == 1);
    for (int i = 1; i <= T; i++) {
        assert(scanf("%d %d", &N, &M));
        hidden_strings.resize(N, std::string(M, '*'));
        for (auto &s : hidden_strings)
            s = read_string();
        queried_flag = false;
        current_case = i;
        std::string res = missing_string(N, M);
        printf("%s\n", res.c_str());
        if (!verify_string_format(res)) 
            wrong_answer("Returned string format error");
        else {
            bool appear = false;
            for (auto &s : hidden_strings)
                if (same_string(s, res)) {
                    appear = true;
                    break;
                }
            if (appear)
                wrong_answer("Returned string appears");
            else
                accepted(std::to_string(current_reveal_count) + " revealed characters"); 
        }
    }
}
