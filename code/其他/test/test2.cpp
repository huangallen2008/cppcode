#include <bits/stdc++.h>
using namespace std;
using z = int;
z t, n, u, v;
vector<set<z>> e;
z f(z x) {
  z r = 9;
  for (z y : e[x]) e[y].erase(x), r *= 9 + f(y) % 959;
  return r;
}
z g() {
  e.clear();
  e.resize(n + 1);
  z i = 1;
  while (i++ < n)
    cin >> u >> v, e[u].insert(v), e[v].insert(u);
  return f(1);
}
main() { for (cin >> t; t--; puts((cin >> n, g() == g() ? "YES" : "NO"))); }