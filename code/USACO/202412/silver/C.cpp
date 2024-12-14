#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3,unroll-loops,fast-math")
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
#define oparr(x) cout<<(#x)<<":";for(auto allen:(x)) cout<<allen<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
template<typename T1,typename T2>
ostream& operator<<(ostream& os,pair<T1,T2> p) { return os<<'{'<<p.f<<','<<p.s<<'}'; }
const int mod=1e9+7;
const int maxn=5;
const int maxb=20;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int n,q;
int outs;
    int N;
int hsh(pii x) {
    return x.f*n+x.s;
}
pii uhsh(int x) {
    return {x/n,x%n};
}
Vpii dir={{0,1},{1,0},{0,-1},{-1,0}};
bool inm(pii x) { 
    if(x.f<0||x.f>=n||x.s<0||x.s>=n) return 0;
    return 1;
}
int go(int x,int di) {
    pii x0=uhsh(x);
    x0.f+=dir[di].f;
    x0.s+=dir[di].s;
    if(!inm(x0)) return outs;
    return hsh(x0);
}
struct qur {
    int x,y,di;
};
int tod(char c) {
    if(c=='R') return 0;
    if(c=='D') return 1;
    if(c=='L') return 2;
    return 3;//'U'
}
// struct DSU {
//     struct S {
//         int x
//     };  
//     int n;
//     Vi p,sz,ty;
//     void init(int _n) {
//         n=_n;
//         p=ty=Vi(n);
//         sz=Vi(n,1);
//         REP(i,n) p[i]=i;
//     }
//     int find(int u) {
//         return p[u]==u?u:find(p[u]);
//     }
//     bool merge(int a,int b) {
//         int x=find(a),y=find(b);
//         if(x==y) {
//             //change type
//             return 0;
//         }
//         if(sz[x]>sz[y]) swap(x,y);
//         stk.pb({x,y,ty[y]});
//         p[x]=y;
//         sz[y]+=sz[x];

//     }
// };

signed main() {
    IOS();
    cin>>n>>q;
    outs=n*n;
    N=n*n+1;
    vector<qur> qu(q);
    vector<int> d0(N,-1);
    REP(i,q) {
        int x,y;
        char ch;
        cin>>x>>y>>ch,x--,y--;
        int u=hsh({x,y});
        d0[u]=tod(ch);
        qu[i]={x,y,tod(ch)};
    }
    Graph g(N);
    REP(i,N) {
        if(d0[i]==-1) {
            REP(di,4) g[go(i,di)].pb(i);
        }else g[go(i,d0[i])].pb(i);
    }
    Vi vis(N);
    int cnt1=0;
    RREP(rr,q) {
        queue<int> qe;
        qe.push(outs);
        if(!vis[outs]) {
            vis[outs]=1;
            cnt1++;
        }
        while(qe.size()) {
            int u=qe.front();
            qe.pop();
            while(g[u].size()) {
                int v=g[u].back();
                g[u].pop_back();
                if(!vis[v]) {
                    vis[v]=1;
                    cnt1++;
                    qe.push(v);
                }
            }
        }
        ope(cnt1)oparr(vis)
        cout<<N-cnt1<<'\n';
        auto [x,y,di]=qu[rr];
        int u=hsh({x,y});
        d0[u]=-1;
        REP(di,4) g[go(u,di)].pb(u);
    }
    return 0;
}