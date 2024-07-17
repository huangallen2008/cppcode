#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
#pragma GCC target("avx2,bmi,popcnt")
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
bool so(int x,int y) { return x>y; }
signed main() {
    IOS();
    int h,w,n;
    cin>>h>>w>>n;
    vector<pii> a(n);
    REP(i,n) cin>>a[i].f>>a[i].s;
    REP(i,n) if(a[i].f<a[i].s) swap(a[i].f,a[i].s);
    vector<int> v1;
    REP(i,n) {
        if(a[i].s>h) v1.pb(a[i].f);
        else if(a[i].f>h) {
            v1.pb(a[i].s);
        }
    }
    sort(ALL(v1),so);
    int an=inf;
    int s1=0;
    REP(i,v1.size()) {
        s1+=v1[i];
        if(s1>=w) {
            chmin(an,i+1);
            break;
        }
    }
    vector<int> v2;
    REP(i,n) {
        if(a[i].s>w) v2.pb(a[i].f);
        else if(a[i].f>w) v2.pb(a[i].s);
    }
    sort(ALL(v2),so);
    int s2=0;
    REP(i,v2.size()) {
        s2+=v2[i];
        if(s2>=h) {
            chmin(an,i+1);
            break;
        }
    }
    if(an==inf) cout<<"-1\n";
    else cout<<an<<'\n';
    return 0;
}
/*
5 7 3
8 2
8 3
8 4

*/