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
signed main() {
    IOS();
    string s;
    cin>>s;
    s+='$';
    int n=s.size();
    vector<int> c(n);
    {
        vector<pair<char,int>> v;
        REP(i,n) v.pb({s[i],i});
        sort(ALL(v));
        c[v[0].s]=0;
        REP1(i,n-1) {
            if(v[i].f==v[i-1].f) c[v[i].s]=c[v[i-1].s];
            else c[v[i].s]=c[v[i-1].s]+1;
        }
    }
    int k=0;
    vector<pair<pii,int>> v;
    while((1<<k)<n) {
        v.clear();
        REP(i,n) v.pb({{c[i],c[(i+(1<<k))%n]},i});
        sort(ALL(v));
        c[v[0].s]=0;
        REP1(i,n-1) {
            if(v[i].f==v[i-1].f) c[v[i].s]=c[v[i-1].s];
            else c[v[i].s]=c[v[i-1].s]+1;
        }
        k++;
    }
    REP(i,n) cout<<v[i].s<<' ';
    cout<<'\n';
    return 0;
}