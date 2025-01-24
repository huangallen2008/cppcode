#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#define ll long long
#define int ll
signed main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int n, q; cin >> n >> q;
	string s; cin >> s;
	s = '#' + s;
	set<int> up, down, all;
	for(int i = 1; i <= n; i++) {
		if(s[i] == '1' && s[n+1-i] == '1') all.insert(i*2+1);
		else if(s[i] == '1') {
			up.insert(i);
		} else if(s[n+1-i] == '1') {
			down.insert(i);
		}
	}
	for(int i = 1; i <= n; i++) {
		if(down.find(i) != down.end() && up.find(i+1) != up.end()) {
			all.insert(i*2+1);
		}
		if(up.find(i) != up.end() && down.find(i+1) != down.end()) {
			all.insert(i*2+1);
		}
	}
	vector<bool> now(n/2+1);
	vector<int> pre(n/2+1);
	for(int i = 1; i <= n/2; i++) {
		if(down.find(i) != down.end()) now[i] = 0;
		else if(up.find(i) != up.end()) now[i] = 1;
		else now[i] = now[i-1];
		pre[i] += pre[i-1] + (now[i] != now[i-1]);
	}
	auto turn = [&](int id) -> int {
		return id <= n/2 ? id : n+1-id;
	};
	auto cnt = [&](int l, int r) -> int {
		if(turn(l) > turn(r)) swap(l, r);
		if(all.lower_bound(turn(l)*2) != all.end() && (*all.lower_bound(turn(l)*2)) <= turn(r)*2) return -1;
		else if(turn(r) == turn(l)) return ((r > (n+1)/2) + (l > (n+1)/2) == 1);
		else {
			int ans = pre[turn(r)-1] - pre[turn(l)+1];
			ans += turn(r)-turn(l);
			int tmp = ((r > (1+n)/2) != now[turn(r)-1]) + ((l > (n+1)/2) != now[turn(l)+1]);
			ans += tmp;
			return ans;
		}
	};
	while(q--) {
		int l, r; cin >> l >> r;
		if((n&1) && ((l == n/2+1) || (r == n/2+1))) {
			if(l == n/2+1) swap(l, r);
            if(l==n/2+1) {cout<<"0\n";
            continue;}
			int a = INT_MAX;
			if(s[r-1] == '0') a = min(a, cnt(r-1, l)+1);
			if(s[r+1] == '0') a = min(a, cnt(r+1, l)+1);
			if(a == INT_MAX) a = -1;
			cout << a << '\n';
		} else {
			cout << cnt(l, r) << '\n';
		}
	}
}