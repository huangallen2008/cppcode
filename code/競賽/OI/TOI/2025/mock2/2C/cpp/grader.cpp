#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <bitset>
#include <string>
#include "2C.cpp"
namespace {
    const int L = 50000;
    const int LIMIT = 10000;
    struct operation {
        int type;
        int X, Y;
    };
    std::vector<operation> gates;
    std::bitset<L> field;
    char buffer[L + 1];
    void read_bitset(std::bitset<L> &res, int length) {
        res.reset();
        assert(scanf("%s", buffer) == 1);
        assert(int(strlen(buffer)) == length);
        for (int i = 0; i < length; i++)
            if (buffer[i] == '1')
                res[length - 1 - i] = 1;
    }
    std::bitset<L> calculate(const std::bitset<L> &input) {
        std::vector<std::bitset<L>> outputs(gates.size(), input);
        for (int i = 1; i < int(gates.size()); i++) {
            if (gates[i].type == 0) {
                outputs[i] = ~outputs[gates[i].X];
            }
            else if (gates[i].type == 1) {
                outputs[i] = outputs[gates[i].X] & outputs[gates[i].Y];
            }
            else if (gates[i].type == 2) {
                outputs[i] = outputs[gates[i].X] | outputs[gates[i].Y];
            }
            else if (gates[i].type == 3) {
                outputs[i] = outputs[gates[i].X] ^ outputs[gates[i].Y];
            }
            else if (gates[i].type == 4) {
                outputs[i] = outputs[gates[i].X] << gates[i].Y;
            }
            else if (gates[i].type == 5) {
                outputs[i] = outputs[gates[i].X] >> gates[i].Y;
            }
            else {
                assert(0);
            }

            outputs[i] &= field;
        }
        return outputs.back();
    }
    void wrong_answer(const std::string &msg) {
        printf("Wrong Answer: %s\n", msg.c_str());
        exit(0);
    }
    void check_index(int X) {
        if (X < 0 || X >= int(gates.size()))
            wrong_answer("Invalid index");
    }
    void check_offset(int D) {
        if (D < 0)
            wrong_answer("Invalid offset");
    }
    void append(const operation &op) {
        if (int(gates.size()) >= LIMIT)
            wrong_answer("Too many gates");
        gates.push_back(op);
    }
} // global variables

void construct_logic(const std::string &S, int K);

int add_not(int X) {
    check_index(X);
    append(operation{0, X, -1}); 
    return gates.size() - 1;
}

int add_and(int X, int Y) {
    check_index(X);
    check_index(Y);
    append(operation{1, X, Y});
    return gates.size() - 1;
}

int add_or(int X, int Y) {
    check_index(X);
    check_index(Y);
    append(operation{2, X, Y});
    return gates.size() - 1;
}

int add_xor(int X, int Y) {
    check_index(X);
    check_index(Y);
    append(operation{3, X, Y});
    return gates.size() - 1;
}

int add_lshift(int X, int D) {
    check_index(X);
    check_offset(D);
    append(operation{4, X, D});
    return gates.size() - 1;
}

int add_rshift(int X, int D) {
    check_index(X);
    check_offset(D);
    append(operation{5, X, D});
    return gates.size() - 1;
}

int main() {
    int N, R, K;
    assert(scanf("%d %d %d", &N, &R, &K) == 3);
    for (int i = 0; i < N; i++) field[i] = 1;
    assert(scanf("%s", buffer) == 1);
    assert(int(strlen(buffer)) == R);
    std::string S(buffer);
    std::vector<std::bitset<L>> querys;
    int Q;
    assert(scanf("%d", &Q) == 1);
    querys.resize(Q);
    for (auto &input : querys) {
        read_bitset(input, N);
    }
    gates.push_back(operation{-1, -1, -1});
    construct_logic(S, K);
    printf("Accepted: %d gates\n", int(gates.size()) - 1);
    for (auto &input : querys) {
        auto output = calculate(input);
        for (int i = 0; i < N; i++)
            buffer[N - 1 - i] = output[i] + '0';
        buffer[N] = 0;
        printf("%s\n", buffer);
    }
}
