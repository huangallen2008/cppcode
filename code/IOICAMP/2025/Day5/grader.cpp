#include "lib0934.h"
#include <cstdio>
#include <vector>
#include <utility>
#include <string>
#include <set>
#include <cassert>

namespace {
    const int MAXQ = 20000;
    double limit;
    int qcnt, n;
    std::vector <int> c;
    void wrong_answer(const std::string &msg) {
        printf("Wrong Answer: %s\n", msg.c_str());
        exit(0);
    }
}

int query(std::vector<int> S) {
	if (S.empty())
		wrong_answer("S must be nonempty");
	std::set <int> vis;
	for (int i : S) {
		if (!(0 <= i && i < n))
			wrong_answer("elements in S must be between 0 and n-1");
		if (vis.count(i))
			wrong_answer("duplicate elements in S");
		vis.insert(i);
	}
	limit += 1 / (double) S.size();
	qcnt += 1;
	if (qcnt > MAXQ)
		wrong_answer("Too many queries");
	int sum = 0;
	for (int v : S) {
		if (c[v]) sum += 1;
	}
	return sum;
}

int main() {
	assert(scanf("%d", &n) == 1);
	c.resize(n);
	for (int i = 0; i < n; ++i) {
		int x; 
		assert(scanf("%d", &x) == 1);
		c[i] = x;
	}

	std::vector <int> pans = guessstone(n);
	if ((int)pans.size() != n)
		wrong_answer("invalid answer");
	for (int i = 0; i < n; ++i)
		if (pans[i] != 0 && pans[i] != 1)
			wrong_answer("invalid answer");

	printf("Accepted: %10f\n", limit);
	for (int i = 0; i < n; ++i) {
		if (pans[i])
			printf("1");
		else
			printf("0");
		if (i + 1 < n) {
			printf(" ");
		}
	}
	printf("\n");
}