#include<bits/stdc++.h>
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
const int mod=998244353;
const int maxn=5;
const int maxb=64;
const int inf=1ll<<60;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
signed main() {
    IOS();
    int _1,_2,m,n;
    cin>>_1>>_2>>n;
    m=__gcd(_1,_2);
    Vpii a(n);
    REP(i,n) cin>>a[i].f;
    REP(i,n) cin>>a[i].s;
    int s,t;
    cin>>s>>t;
    int st=s%m;
    Graphw g(m+1),gb(m+1);
    struct S {
        int v1,v2,v3;
    };
    vector<vector<S>> g2(m+1);
    auto addedge=[&](int u,int v,int w,int x) {
        g[u].pb({v,w});
        g2[u].pb({v,w,x});
        gb[v].pb({u,w});
    };
    REP(u,m) {
        for(auto v0:a) {
            int v=(u*10+v0.f)%m;
            addedge(u,v,v0.s,v0.f);
            if(v==0&&v0.f==t) addedge(u,m,v0.s,v0.f);
        }
    }
    //st->m
    Vi diss(m+1,inf),dism(m+1,inf);
    auto dijk=[&](Graphw &g,Vi &dis,int s) {
        dis=Vi(m+1,inf);
        dis[s]=0;
        Vi vis(m+1);
        priority_queue<pii,Vpii,greater<pii>> pq;
        pq.push({0,s});
        while(pq.size()) {
            int u=pq.top().s;
            pq.pop();
            if(vis[u]) continue;
            vis[u]=1;
            for(auto [v,w]:g[u]) {
                if(dis[v]>dis[u]+w) {
                    dis[v]=dis[u]+w;
                    pq.push({dis[v],v});
                }
            }
        }
    };
    dijk(g,diss,st);
    dijk(gb,dism,m);
    // oparr(diss)
    // oparr(dism)
    if(diss[m]==inf) {
        cout<<"-1\n";
        return 0;
    }
    int now=st;
    cout<<s;
    // int ttt=0;
    while(now!=m) {
        // if(ttt++>10) break;
        pii mn={inf,inf};
        for(auto [v1,v2,v3]:g2[now]) {
            if(diss[now]+v2==diss[v1]&&diss[v1]+dism[v1]==diss[m]) {
                pii p=pii{v1,v3};
                if(v3<mn.s) mn=p;
                else if(v3==mn.s&&v1==m) mn=p;
            }
        }
        now=mn.f;
        cout<<mn.s;
    }
    cout<<'\n';
    return 0;
}