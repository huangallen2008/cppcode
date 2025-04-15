#include <string>

int add_not(int X);
int add_and(int X, int Y);
int add_or(int X, int Y);
int add_xor(int X, int Y);
int add_lshift(int X, int D);
int add_rshift(int X, int D);

void construct_logic(const std::string &S, int K) {
    add_not(0);
}
