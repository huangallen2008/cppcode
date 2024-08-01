#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
// #pragma GCC target("avx2,bmi,popcnt")
#define int long long
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,n) for(int i=1;i<=(n);i++)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define RREP1(i,n) for(int i=(n);i>=1;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
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
#ifdef LOCAL
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) cout<<(#x)<<":";for(auto &allen:(x)) cout<<allen<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=998244353;
const int maxn=2e5+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
signed main() {
    IOS();
    int n,m;
    cin>>n>>m;
    vector<pii> e(m);
    vector<int> two(m+1);
    two[0]=1;
    REP1(i,m) two[i]=(two[i-1]<<1)%mod;
    REP(i,m) {
        int u,v;
        cin>>u>>v;
        u--,v--;
        e[i]={u,v};
    }
    vector<int> cnt(1<<n);
    REP(i,1<<n) {
        for(auto [u,v]:e) {
            if(((i>>u)&1)&&((i>>v)&1)) cnt[i]++;
        }
    }
    vector<int> d(1<<n);
    d[1]=1;
    for(int i=2;i<1<<n;i++) {
        if(~i&1) continue;
        d[i]=two[cnt[i]];
        for(int s=i;s>0;s=(s-1)&i) {
            if(~s&1) continue;
            if(s==i) continue;
            addmod(d[i],-d[s]*two[cnt[i^s]]);
        }
    }
    int all=(1<<n)-1;
    vector<int> an(n);
    REP(i,1<<n) {
        REP1(j,n-1) {
            if((i>>j)&1) addmod(an[j],d[i]*two[cnt[i^all]]); 
        }
    }
    REP1(i,n-1) cout<<md(an[i])<<'\n';
    return 0;
}