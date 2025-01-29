#include <bits/stdc++.h>

using namespace std;

const int N = 6010;

int min_end[N];
int if_add[N];
int a[N], b[N];
pair <int, int> e[N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &e[i].first, &e[i].second);
  }
  sort(e, e + n);
  for (int i = 0; i < n; i++) {
    a[i] = e[i].first;
    b[i] = e[i].second;
  }
  min_end[n - 1] = b[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    min_end[i] = min(min_end[i + 1], b[i]);
  }
  for (int i = 0; i < n - 1; i++) {
    if_add[i] = max(min_end[i + 1], b[i]) - a[i];
  }
  sort(if_add, if_add + n - 1);
  reverse(if_add, if_add + n - 1);
  long long ans = min_end[0] - a[n - 1];
  for (int i = 0; i < k - 1; i++) {
    ans += if_add[i];
  }
  {
    vector <int> lengths;
    for (int i = 0; i < n; i++) {
      lengths.push_back(b[i] - a[i]);
    }
    sort(lengths.rbegin(), lengths.rend());
    long long other = 0;
    for (int i = 0; i < k - 1; i++) {
      other += lengths[i];
    }
    ans = max(ans, other);
  }
  cout << ans << endl;
  return 0;
}
