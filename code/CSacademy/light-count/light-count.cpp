#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("Ofast,unroll-loops,fast-math")
// #pragma GCC target("avx2,sse4,bmi,popcnt")
// #define int long long
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,n) for(int i=1;i<=(n);i++)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define RREP1(i,n) for(int i=(n);i>=1;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define ALL1(x) (x).begin()+1,(x).end()
#define SZ(x) (int)((x).size())
#define SQ(x) (x)*(x)
#define pii pair<int,int>
#define pipii pair<int,pii>
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
#ifdef LOCAL
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) cout<<(#x)<<":";for(auto &mken:(x)) cout<<mken<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
// const int mod=30011;
const int maxn=5e7+5;
const int maxb=6;
const int maxnb=maxn>>maxb;
// const int maxc=26;
// const int inf=(1ll<<62); 
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// int rd(int l,int r) {
//     return uniform_int_distribution<int>(l,r)(rng);
// }
struct RandGen {
    int x, y, z;

    int nextInt() {
        int t = x ^ (x << 11);
        x = y;
        y = z;
        z ^= (z >> 19) ^ t ^ (t >> 8);
        return z;
    }

    int random(int N) {
        return nextInt() % N;
    }
};
#define int8 int8_t
int8 b[maxnb];
bitset<maxn> a;
void init(int N, int M) {

}
int lowbit(int x) {
    int lg=__lg(x&-x);
    return 1<<(lg/maxb*maxb);
}
void flipPosition(int u) {
    a[u]^=1;
    if(a[u]) {
        u>>=maxb;
        for(;u<=maxnb;u+=lowbit(u)) {
            b[u]++;
        }
    }
    else {
        u>>=maxb;
        for(;u<=maxnb;u+=lowbit(u)) {
            b[u]--;
        }
    }
}
int pre(int u) {
    int u1=(u>>maxb)<<maxb;
    int r=0;
    for(int i=u1+1;i<=u;i++) r+=a[u];
    u1>>=maxb;
    for(;u1>0;u1-=lowbit(u1)) r+=b[u1];
    return r;
}
int getCount(int st, int fn) {
    return pre(fn)-pre(st);
}

int main() {
    IOS();
    int N, M;
    RandGen rng;
    cin >> N >> M >> rng.x >> rng.y >> rng.z;

    init(N, M);

    long long hashSol = 0;

    for (long long i = 0; i < M; i++) {
        if (rng.random(2) == 0) {
            const int poz = rng.random(N);
            flipPosition(poz);
        }
        else {
            int st = rng.random(N), fn = rng.random(N);
            if (st > fn) {
                swap(st, fn);
            }

            hashSol ^= i * getCount(st, fn);
        }
    }

    cout << hashSol << "\n";
}
