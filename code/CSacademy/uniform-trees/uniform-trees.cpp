#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("Ofast,unroll-loops,fast-math")
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
const int mod=1e9+7;
const int maxn=3e6+5;
const int maxc=26;
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
Vi c,p,sz,sum;
vector<unordered_map<int,int>> dp;
int an=0;

void AD(int &x,int y) {
    x+=y;
    if(x>=mod) x-=mod;
}
void MI(int &x,int y) {
    x-=y;
    if(x<0) x+=mod;
}
void dfs(int u) {
    int mxs=0,id=-1;
    for(int v:g[u]) {
        dfs(v);
        sz[u]+=sz[v];
        if(sz[v]>mxs) {
            mxs=sz[v];
            id=v;
        }
    }
    if(id==-1) {
        dp[u][c[u]]=1;
        sum[u]=1;
        an++;
    }
    else {
        for(int v:g[u]) {
            if(v==id) continue;
            for(auto [x,y]:dp[v]) Mi(sum[id],dp[id][x]),dp[id][x]=((dp[id][x]+1)*(dp[v][x]+1)-1)%mod,AD(sum[id],dp[id][x]);
        }
        AD(an,sum[id]+1);
        AD(dp[id][c[u]],sum[id]+1);
        AD(sum[id],sum[id]+1);
        swap(dp[u],dp[id]);
        swap(sum[u],sum[id]);
        // op(u)for(auto [x,y]:dp[u]) cout<<"{"<<x<<' '<<y<<"} ";entr
    }
}
signed main() {
    IOS();
    int n=read();
    // cin>>n;
    c=p=sum=Vi(n);
    sz=Vi(n,1);
    g=Graph(n);
    dp=vector<unordered_map<int,int>>(n);
    REP(i,n) {
        p[i]=read()-1,c[i]=read()-1;
        // cin>>p[i]>>c[i],c[i]--,p[i]--;
        if(i) g[p[i]].pb(i);
    }
    dfs(0);
    an=(an+mod)%mod;
    cout<<an<<'\n';
    return 0;
}