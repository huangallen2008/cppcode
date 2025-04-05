#include<bits/stdc++.h>
#include<complex>
using namespace std;
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,sse4,bmi2,popcnt")
#define int long long
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,n) for(int i=1;i<=(n);i++)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define RREP1(i,n) for(int i=(n);i>=1;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)((x).size()))
#define SQ(x) ((x)*(x))
#define pii pair<int,int>
#define pipii pair<int,pii>
#define ppi pair<pii,int>
#define Graph vector<vector<int>>
#define Graphw vector<vector<pii>>
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
#define md(x) (((x)%(mod)+(mod))%(mod))
#define MD(x,M) (((x)%(M)+(M))%(M))
#define ld long double
#define pdd pair<ld,ld>
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
#define addmod(x,y) x=((x+(y))%mod)
#define Vi vector<int>
#define Vpii vector<pii>
#ifdef LOCAL
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) {cout<<(#x)<<":";for(auto allen:(x)) cout<<allen<<" ";cout<<" size="<<(x).size()<<endl;}
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
template<typename T1,typename T2>
ostream& operator<<(ostream& os,pair<T1,T2> p) { return os<<'{'<<p.f<<','<<p.s<<'}'; }
template<typename T1,typename T2>
istream& operator>>(istream& os,pair<T1,T2> &p) { return os>>p.f>>p.s; }
template<typename S>
ostream& operator<<(ostream& os,vector<S> p) { for(auto allen:p) os<<allen<<' ';return os<<'\n'; }
template<typename S>
istream& operator>>(istream& os,vector<S> &p) { for(auto &allen:p) os>>allen;return os; }
template<typename T1,typename T2>
pair<T1,T2> operator+(pair<T1,T2> p1,pair<T1,T2> p2) { return pair<T1,T2>(p1.f+p2.f,p1.s+p2.s); }
const int mod=1e9+7;
// const int maxn=2e5+5;
const int maxv=1300;
const int inf=1ll<<60;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
namespace Math {
	inline int pw(int base, int p, const int mod) {
		static int res;
		for (res = 1; p; p >>= 1, base = static_cast<long long> (base) * base % mod) if (p & 1) res = static_cast<long long> (res) * base % mod;
		return res;
	}
	inline int inv(int x, const int mod) { return pw(x, mod - 2, mod); }
}

const int mod1 = 998244353, mod2 = 1004535809, mod3 = 469762049, G = 3;
const long long mod_1_2 = static_cast<long long> (mod1) * mod2;
const int inv_1 = Math::inv(mod1, mod2), inv_2 = Math::inv(mod_1_2 % mod3, mod3);
struct Int {
	int A, B, C;
	explicit inline Int() { }
	explicit inline Int(int __num) : A(__num), B(__num), C(__num) { }
	explicit inline Int(int __A, int __B, int __C) : A(__A), B(__B), C(__C) { }
	static inline Int reduce(const Int &x) {
		return Int(x.A + (x.A >> 31 & mod1), x.B + (x.B >> 31 & mod2), x.C + (x.C >> 31 & mod3));
	}
	inline friend Int operator + (const Int &lhs, const Int &rhs) {
		return reduce(Int(lhs.A + rhs.A - mod1, lhs.B + rhs.B - mod2, lhs.C + rhs.C - mod3));
	}
	inline friend Int operator - (const Int &lhs, const Int &rhs) {
		return reduce(Int(lhs.A - rhs.A, lhs.B - rhs.B, lhs.C - rhs.C));
	}
	inline friend Int operator * (const Int &lhs, const Int &rhs) {
		return Int(static_cast<long long> (lhs.A) * rhs.A % mod1, static_cast<long long> (lhs.B) * rhs.B % mod2, static_cast<long long> (lhs.C) * rhs.C % mod3);
	}
	inline int get() {
		long long x = static_cast<long long> (B - A + mod2) % mod2 * inv_1 % mod2 * mod1 + A;
		return (static_cast<long long> (C - x % mod3 + mod3) % mod3 * inv_2 % mod3 * (mod_1_2 % mod) % mod + x) % mod;
	}
} ;

#define maxn 131072

namespace Poly {
#define N (maxn << 1)
	int lim, s, rev[N];
	Int Wn[N | 1];
	inline void init(int n) {
		s = -1, lim = 1; while (lim < n) lim <<= 1, ++s;
		for (register int i = 1; i < lim; ++i) rev[i] = rev[i >> 1] >> 1 | (i & 1) << s;
		const Int t(Math::pw(G, (mod1 - 1) / lim, mod1), Math::pw(G, (mod2 - 1) / lim, mod2), Math::pw(G, (mod3 - 1) / lim, mod3));
		*Wn = Int(1); for (register Int *i = Wn; i != Wn + lim; ++i) *(i + 1) = *i * t;
	}
	inline void NTT(Int *A, const int op = 1) {
		for (register int i = 1; i < lim; ++i) if (i < rev[i]) std::swap(A[i], A[rev[i]]);
		for (register int mid = 1; mid < lim; mid <<= 1) {
			const int t = lim / mid >> 1;
			for (register int i = 0; i < lim; i += mid << 1) {
				for (register int j = 0; j < mid; ++j) {
					const Int W = op ? Wn[t * j] : Wn[lim - t * j];
					const Int X = A[i + j], Y = A[i + j + mid] * W;
					A[i + j] = X + Y, A[i + j + mid] = X - Y;
				}
			}
		}
		if (!op) {
			const Int ilim(Math::inv(lim, mod1), Math::inv(lim, mod2), Math::inv(lim, mod3));
			for (register Int *i = A; i != A + lim; ++i) *i = (*i) * ilim;
		}
	}
#undef N
}

int n, m;
Int A[maxn << 1], B[maxn << 1];
// vector<_Int> A(maxn<<1),B(maxn<<1);
Vi MTT(Vi _A,Vi _B) {
    n=SZ(_A),m=SZ(_B);
	// scanf("%d%d%d", &n, &m, &mod); ++n, ++m;
	for (int i = 0, x; i < n; ++i) A[i] = Int(_A[i] % mod);
	for (int i = 0, x; i < m; ++i) B[i] = Int(_B[i] % mod);
	Poly::init(n + m);
	Poly::NTT(A), Poly::NTT(B);
	for (int i = 0; i < Poly::lim; ++i) A[i] = A[i] * B[i];
	Poly::NTT(A, 0);
    Vi an(n+m-1);
	for (int i = 0; i < n + m - 1; ++i) {
		an[i]=A[i].get();
	}
	return an;
}
void solve() {
    Vi a={1,1},b={1,2};
    oparr(MTT(a,b))
}
signed main() {
    IOS();
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}
