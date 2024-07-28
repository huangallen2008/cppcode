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
const int mod=1e9+7;
const int maxn=1e4+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
// vector<int> v;
bool ok(int a,int b,int c) {
    return a+b>c&&a+c>b&&c+b>a;
}
struct DS {
    set<pii> s;
    void push(int x) {
        auto it=s.lower_bound({x,0}),itl=it;
        vector<set<pii>::iterator> nxt,las;
        if(it!=s.end()) {
            nxt.pb(it);
            it=next(it);
            if(it!=s.end()) nxt.pb(it);
        }
        if(itl!=s.begin()) {
            itl=prev(itl);
            las.pb(itl);
            if(itl!=s.begin()) {
                itl=prev(itl);
                las.pb(itl);
            }
        }
        if(las.size()==2) {
            bool oo=ok((*las[0]).f,(*las[1]).f,x);
            if(oo) { 
                if((*las[1]).s==0) push_1((*las[1]).f);
                *(las->s)=1;
            }
        }
    }
};
void solve() {
    int n,q;
    cin>>n>>q;
    vector<int> a(n+1);
    REP1(i,n) cin>>a[i];
    vector<int> c(n);
    REP1(i,n) c[i]+=c[i-1];
    REP(i,q) {
        int l,r;
        cin>>l>>r;
        if(c[r-5]!=c[l-1]) cout<<"YES\n";
        else cout<<"NO\n";
    }
}
signed main() {
    IOS();
    // int T;
    // cin>>T;
    // while(T--) 
        solve();
    return 0;
}