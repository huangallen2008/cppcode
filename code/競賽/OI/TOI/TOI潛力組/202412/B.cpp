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
const int mod=1e9+7;
const int maxn=5;
const int maxb=20;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int toi(char c) {
    if(isdigit(c)) return c-'0'; // 10
    if(isupper(c)) return c-'A'+10; //10+26=36
    if(islower(c)) return c-'a'+36; //36+26=62
    if(c=='+') return 62;
    return 63;
}
char iot(int x) {
    if(x==63) return '/';
    if(x==62) return '+';
    if(x>=36) return 'a'+x-36;
    if(x>=10) return 'A'+x-10;
    return '0'+x;
}
signed main() {
    IOS();
    int n;
    cin>>n;
    string s1;
    cin>>s1;
    Graph g(64);
    Vi ind(64);
    REP(i,n-1) {
        string s2;
        cin>>s2;
        REP(j,min(s1.size(),s2.size())) {
            if(s1[j]!=s2[j]) {
                int u=toi(s1[j]),v=toi(s2[j]);
                g[u].pb(v);
                ind[v]++;
                break;
            }
        }
        s1=s2;
    }
    Vi tps;
    queue<int> q;
    REP(i,64) if(ind[i]==0) q.push(i);
    while(q.size()) {
        int u=q.front();
        tps.pb(u);
        q.pop();
        for(int v:g[u]) {
            if(--ind[v]==0) q.push(v);
        }
    }
    oparr(tps)
    for(int x:tps) cout<<iot(x);
    cout<<'\n';
    return 0;
}