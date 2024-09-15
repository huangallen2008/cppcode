#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
#pragma GCC target("avx2,bmi,popcnt")
// #define int long long
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define RREP1(i,n) for(int i=(n);i>=1;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)(x.size())
#define SQ(x) (x)*(x)
#define pii pair<int,int>
#define pipii pair<int,pii>
#define Graph vector<vector<int>>
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
#define md(x) (((x)%(mod)+(mod))%(mod))
#define MD(x,M) (((x)%(M)+(M))%(M))
#define ld long double
#define pdd pair<ld,ld>
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
#define addmod(x,y) x=((x+(y))%mod)
#ifdef LOCAL
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) cout<<(#x)<<":";REP(allen,(x).size()) cout<<x[allen]<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=1e9+7;
const int maxn=1e3+5;
const int inf=(1ll<<62);
inline char RC(){
	const int S = 1<<16;
	static char buf[S], *p = buf, *q = buf;
	return p == q and (q = (p = buf) + fread(buf, 1, S, stdin)) == buf ? EOF : *p++;
}
int16_t n,m;
int16_t cal(bitset<maxn> &b) {
    int16_t an=0,c=0;
    for(int i=0;i<=m;i++) {
        if(b[i]) c++;
        else an=max(an,c),c=0;
    }
    return an;
}
bitset<maxn> b[maxn];
signed main() {
    IOS();
    cin>>n>>m;
    REP(i,n) {
        REP(j,m) if(RC()=='.') b[i].set(j);
        RC();
    }
    int an=0;
    REP(i,n) {
        bitset<maxn> r;r.set();
        RREP(j,i+1) {
            r=r&b[j];
            chmax(an,(i-j+1)*cal(r));
        }
    }
    cout<<an<<'\n';
    return 0;
}