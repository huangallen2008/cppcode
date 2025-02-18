//#pragma GCC optimize(1)
//#pragma GCC optimize(2)
//#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
namespace Initial {
	#define ll long long
	#define ull unsigned long long
	#define fi first
	#define se second
	#define mkp make_pair
	#define pir pair <ll, ll>
	#define pb emplace_back
	#define i128 __int128
	using namespace std;
	template <class T>
	void rd(T &x) {
		char ch; bool f = 0;
		while(!isdigit(ch = getchar()))
			if(ch == '-') f = 1;
		x = ch - '0';
		while(isdigit(ch = getchar()))
			x = (x << 1) + (x << 3) + ch - '0';
		if(f) x = -x;
	}
	void write(const ll x, const char str[] = "") {
		if(x > 9) write(x / 10);
		putchar(x % 10 + '0'), printf("%s", str);
	}
	const ll maxn = 310, inf = 1e18; ll mod;
	ll power(ll a, ll b = mod - 2) {
		ll s = 1;
		while(b) {
			if(b & 1) s = 1ll * s * a %mod;
			a = 1ll * a * a %mod, b >>= 1;
		} return s;
	}
	template <class T>
	const ll pls(const T x, const T y) { return x + y >= mod? x + y - mod : x + y; }
	template <class T>
	void add(T &x, const T y) { x = x + y >= mod? x + y - mod : x + y; }
	template <class T>
	void chkmax(T &x, const T y) { x = x < y? y : x; }
	template <class T>
	void chkmin(T &x, const T y) { x = x > y? y : x; }
} using namespace Initial;

ll n, ans, C[maxn][maxn], f[maxn], g[maxn][maxn];
ll pw[maxn * maxn];
int main() {
	rd(n), rd(mod), C[0][0] = f[0] = g[0][0] = 1;
	pw[0] = 1;
	for(ll i = 1; i <= n * n; i++) pw[i] = pw[i - 1] * 2 %mod;
	for(ll i = 1; i <= n; i++) {
		f[i] = pw[i * (i + 1) / 2] %mod;
		for(ll j = 1; j <= i; j++) {
			for(ll k = j - 1; k < i; k++)
				add(g[i][j], g[k][j - 1] * pw[(i - k - 1) * (i - k - 2) / 2] %mod);
			if(j < i)
				add(f[i], mod - g[i][j] * f[j] %mod);
		}
	} write(f[n], "\n");
	return 0;
}