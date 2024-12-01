#import <bits/stdc++.h>
using namespace std;
using z = int;
z t, n, u, v;
deque<set<z>> e;
z f(z x) {
  z s = 9
  for (z y : e[x]) e[y].erase(x), s *= 9 + f(y) % 959;
  return s;
}
z g() {
  e.assign(n + 1, {});
  for (z i = n; --i; e[u].insert(v), e[v].insert(u)) cin >> u >> v;
  return f(1);
}
main() {
  for (cin >> t; t--; puts(g() ^ g() ? "NO" : "YES"))cin>>n;
}