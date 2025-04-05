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
typedef long long lolong;
// typedef std::complex<double> complex;
#define complex complex<double>
const int maxn = 400005, maxk = 20;
const complex I(0, 1);
int R[maxn];
complex Wn[maxn];

void FFT(complex *A, int n, int t) {
	if(t == -1)
		for(int i = 1; i < n; i ++)
			if(i < (n - i))
				std::swap(A[i], A[n - i]);
	for(int i = 0; i < n; i ++)
		if(i < R[i])
			std::swap(A[i], A[R[i]]);

	for(int m = 1, l = 0; m < n; m <<= 1, l ++) {
		/* complex Wn(cos(M_PI / m), sin(M_PI / m) * t); */
		for(int i = 0; i < n; i += m << 1) {
			/* complex W = 1; */
			for(int k = i; k < i + m; k ++) {
				/* complex W(cos(M_PI / m * (k - i)), sin(M_PI / m * (k - i)) * t); */
				complex W = Wn[1ll * (k - i) * n / m];
				/* if(t == -1) W = std::conj(W); */
				complex a0 = A[k], a1 = A[k + m] * W;
				A[k] = a0 + a1;
				A[k + m] = a0 - a1;
				/* W *= Wn; */
			}
		}
	}

	if(t == -1)
		for(int i = 0; i < n; i ++)
			A[i] /= n;
}

// int mod;
inline lolong num(complex x) {
	double d = x.real();
	return d < 0 ? lolong(d - 0.5) % mod : lolong(d + 0.5) % mod;
}

inline void FFTFFT(complex *a, complex *b, int len, int t) {
	for(int i = 0; i < len; i ++)
		a[i] = a[i] + I * b[i];
	FFT(a, len, t);
	for(int i = 0; i < len; i ++)
		b[i] = std::conj(a[i ? len - i : 0]);
	for(int i = 0; i < len; i ++) {
		complex p = a[i], q = b[i];
		a[i] = (p + q) * 0.5;
		b[i] = (q - p) * 0.5 * I;
	}
}

complex a0[maxn], a1[maxn], b0[maxn], b1[maxn];
/* complex a0b0[maxn], a1b0[maxn], a0b1[maxn], a1b1[maxn]; */
complex p[maxn], q[maxn];

Vi MTT(Vi a,Vi b) {
	int n = SZ(a), m = SZ(b);
	int M = (int)(sqrt(mod) + 1);

	for(int i = 0; i <= n; i ++) {
		int x = a[i] % mod;
		a0[i] = x / M;
		a1[i] = x % M;
	}
	for(int i = 0; i <= m; i ++) {
		int x = b[i] % mod;
		b0[i] = x / M;
		b1[i] = x % M;
	}

	int len = 1;
	while(len < n + m + 1)
		len <<= 1;

	for(int i = 1; i < len; i ++)
		R[i] = R[i >> 1] >> 1 | ((i & 1) * (len >> 1));

	for(int i = 0; i < len; i ++)
		Wn[i] = complex(cos(M_PI / len * i), sin(M_PI / len * i));

	FFTFFT(a0, a1, len, 1);
	FFTFFT(b0, b1, len, 1);

	for(int i = 0; i < len; i ++) {
		p[i] = a0[i] * b0[i] + I * a1[i] * b0[i];
		q[i] = a0[i] * b1[i] + I * a1[i] * b1[i];
	}

	FFT(p, len, -1);
	FFT(q, len, -1);
    Vi an(n+m);
	for(int i = 0; i <= n + m; i ++)
		an[i]=(M * M * num(p[i].real()) % mod +
				M * (num(p[i].imag()) + num(q[i].real())) % mod +
				num(q[i].imag())) % mod;
                return an;
}
void solve() {
    Vi a={1};
}
signed main() {
    IOS();
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}
