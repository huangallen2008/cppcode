#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3,unroll-loops,fast-math")
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
const int mod=998244353;
const int maxn=1e7+5;
const int maxb=20;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
#define Vs vector<string>
vector<Vi> g;
bool same(Vi x) {
    for(int i=0;i<SZ(x)-1;i++) if(x[i]!=x[i+1]) return 0;
    return 1;
}
int check(Vi x) {
    REP(i,4) {
        REP(j,6) {
            if(j>=3&&x[i]>j&&x[i+1]>j-1&&x[i+2]>j-2&&x[i+3]>j-3) {
                bool ret=same({g[i][j],g[i+1][j-1],g[i+2][j-2],g[i+3][j-3]});
                if(ret) return g[i][j];
            }
            if(x[i]>j&&x[i+1]>j&&x[i+2]>j&&x[i+3]>j) {
                bool ret=same({g[i][j],g[i+1][j],g[i+2][j],g[i+3][j]});
                if(ret) return g[i][j];
            }
            if(j<=2&&x[i]>j&&x[i+1]>j+1&&x[i+2]>j+2&&x[i+3]>j+3) {
                bool ret=same({g[i][j],g[i+1][j+1],g[i+2][j+2],g[i+3][j+3]});
                if(ret) return g[i][j];
            }
        }
    }
    REP(i,7) {
        REP(j,3) {
            if(x[i]>j+3&&same({g[i][j],g[i][j+1],g[i][j+2],g[i][j+3]})) return g[i][j];
        }
    }
    return -1;
}
const int maxd=823543;
void solve(int C) {
    cout<<"Case #"<<C<<": ";
    g=vector<Vi>(7,Vi(6));
    RREP(i,6) {
        REP(j,7) {
            char c;
            cin>>c;
            if(c=='F') g[j][i]=1;
        }
    }
    // REP(i,7) {
    //     oparr(g[i])
    // }
    Vi dp(maxd);
    vector<int> pos(maxd,-1);
    pos[0]=0;
    bool posir[2];
    REP(i,maxd){//maxd) {
        if(pos[i]==-1) continue;
        Vi x;
        int t=i;
        REP(j,7) {
            x.pb(t%7),t/=7;
        }
        // op(i)oparr(x)
        int ret=check(x);
        if(ret==-1) {
            REP(j,7) {
                if(x[j]!=6&&g[j][x[j]]==pos[i]) {
                    x[j]++;
                    int id=0;
                    for(int k=6;k>=0;k--) id=id*7+x[k];
                    pos[id]=pos[i]^1;
                    // ope(id)
                    x[j]--;
                }
            }
        }
        else {
            // op(i)ope(ret)
            posir[ret]=1;
        }
    }
    if(posir[0]) {
        if(posir[1]) cout<<"?\n";
        else cout<<"C\n";
    }
    else {
        if(posir[1]) cout<<"F\n";
        else cout<<"0\n";
    }
}
signed main() {
    IOS(); 
    #ifdef LOCAL_
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int T;
    cin>>T;
    REP1(i,T) solve(i);
    return 0;
}
/*
1
FFFFFFF
CCCCCCC
FFFFFFF
CCCCCCC
FFFFFFF
CCCCCCC


FCFCFCF
CCFCFCF
CFCFCCF
CFFFCFC
FCCCCCC
CFFFFFF
*/