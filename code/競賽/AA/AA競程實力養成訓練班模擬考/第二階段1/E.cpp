#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
// #pragma GCC target("avx2,sse4,bmi,popcnt")
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
#define oparr(x) cout<<(#x)<<":";for(auto &mken:(x)) cout<<mken<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=1e9+7;
const int maxn=21;
const int inf=(1ll<<50);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
signed main() {
    IOS();
    int n,m;
    cin>>n>>m;
    vector<bitset<maxn>> adj(n);
    REP(i,m) {
        int u,v;
        cin>>u>>v,u=n-u,v=n-v;
        adj[u][v]=1;
        adj[v][u]=1;
    }
    int an1=0,an2=-1;
    REP(i,1<<n) {
        bitset<maxn> t=i;
        bool ok=1;
        REP(j,n) {
            if((i>>j)&1) {
                if((t&adj[j])!=0) {
                    ok=0;
                    break;
                }
            }
        }
        if(!ok) continue;
        REP(j,n) {
            if(~(i>>j)&1) {
                if((adj[j]&t)!=t) {
                    ok=0;
                    break;
                }
            }
        }
        if(!ok) continue;
        an1++;
        if(an2==-1) an2=i;
    }
    cout<<an1<<'\n';
    if(an1==0) {
        REP(i,n) cout<<0;
        cout<<'\n';
    }
    else {
        RREP(i,n) cout<<((an2>>i)&1);
        cout<<'\n'; 
    }
    return 0;
}