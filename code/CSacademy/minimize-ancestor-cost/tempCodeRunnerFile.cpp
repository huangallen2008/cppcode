#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops,fast-math")
#pragma GCC target("avx,avx2,sse4,sse4.1,sse4.2,bmi,bmi2,popcnt")
// #define int long long
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
const int mod=1e9+7;
const int maxn=1e5+5;
const int maxb=30;
const int inf=(1ll<<62); 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
#ifdef LOCAL
#define GC _getchar_nolock()
#define PC _putchar_nolock
#else 
#define GC getchar_unlocked()
#define PC putchar_unlocked
#endif
inline int read()
{
    int x=0;
    bool neg=0;
    char c=GC;
    while(c<'0'||c>'9'){if(c=='-') neg=1;c=GC;}
    while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=GC;
    if(neg) x=-x;
    return x;
}
inline void out(int x) {
    if(x<0) {
        PC('-');
        x=-x;
    }
    char str[18];
	auto it=str;
    do { 
        *it=x%10+'0',it++;
        x/=10;
    } while(x);
    for(it--;it>=str;it--) PC(*it);
    PC('\n');
}
Graph g;
Vi c,dep;
int n;
Vi stk(maxn);
Vi an;
int en=0;
inline void dfs(int u) {
    int tmp_en=en;
    for(int &v:g[u]) {
        dep[v]=dep[u]+1;
        // while(en>=2) {
        //     int la=stk[en-1],la2=stk[en-2];
        //     if((c[v]-c[la])*(long long)(dep[la]-dep[la2])>(c[la]-c[la2])*(long long)(dep[v]-dep[la])) break;
        //     en--;
        // }
        int lb=2,rb=en,mb; 
        while(lb<rb) {
            mb=lb+rb+1>>1;
            int la=stk[mb-1],la2=stk[mb-2];
            if((c[v]-c[la])*(long long)(dep[la]-dep[la2])<=(c[la]-c[la2])*(long long)(dep[v]-dep[la])) lb=mb;
            else rb=mb-1;
        }
        en=lb;
        an[v]=stk[en-1];
        int tmp=stk[en];
        stk[en++]=v;
        dfs(v);
        stk[--en]=tmp;
    }
    en=tmp_en;
}
signed main() {
    IOS(); 
    n=read();
    // cin>>n;
    g=Graph(n);
    c=an=dep=Vi(n);
    REP(i,n) c[i]=read();//cin>>c[i];
    REP1(i,n-1) {
        int u=read()-1;
        // cin>>u,u--;
        g[u].pb(i);
    }
    REP(i,n) {
        sort(ALL(g[i]),[&](int a,int b) {
            return c[a]>c[b];
        });
    }
    stk[en++]=0;
    dfs(0);
    // oparr(dep)
    REP1(i,n-1) {
        out(an[i]+1);
        // cout<<an[i]+1<<'\n';
    }
    return 0;
}