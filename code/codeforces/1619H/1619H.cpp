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
#define oparr(x) cout<<(#x)<<":";for(auto &allen:(x)) cout<<allen<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=1e9+7;
const int maxn=1e5+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int n,q,sn;
int nxt[maxn],pre[maxn],bs[maxn];
int gok(int u,int k) {
    while(k--) u=nxt[u];
    return u;
}
void upd(int u) {
    bs[u]=gok(u,sn);
    int v=bs[u];
    REP(i,sn) {
        u=pre[u];
        v=pre[v];
        bs[u]=v;
    }
}
int qu(int u,int k) {
    int r1=k/sn,r2=k%sn;
    REP(i,r1) u=bs[u];
    REP(i,r2) u=nxt[u];
    return u;
}
signed main() {
    IOS();
    cin>>n>>q;
    sn=sqrt(n);
    REP(i,n) cin>>nxt[i],nxt[i]--,pre[nxt[i]]=i;
    REP(i,n) bs[i]=gok(i,sn);
    REP(i,q) {
        int opt;
        cin>>opt;
        if(opt==1) {
            int x,y;
            cin>>x>>y,x--,y--;//x<->nxt[x],y->nxt[y]  ==> x<->nxt[y],y<->nxt[x]
            int nx=nxt[x],ny=nxt[y];
            nxt[x]=ny,nxt[y]=nx;
            pre[nx]=y,pre[ny]=x;
            upd(x),upd(y);
        }
        else {
            int x,k;
            cin>>x>>k,x--;
            cout<<qu(x,k)+1<<'\n';
        }
    }
    return 0;
}