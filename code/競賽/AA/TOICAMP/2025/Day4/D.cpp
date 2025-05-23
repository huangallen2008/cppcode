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
#ifdef LOCAL_
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
int n,s;
Vi solve(int n,Vi a,Vi a0) {
    Vi ans;
    Vi vis(n);
    Vi r;
    REP(i,n) {
        if(vis[i]||a[i]==i) continue;
        int t=a[i];
        Vi rr;
        if(i)rr.pb(i);
        vis[i]=1;
        while(t!=i) {
            vis[t]=1;
            rr.pb(t);
            t=a[t];
        }
        if(i) rr.pb(i);
        reverse(ALL(rr));
        for(int v:rr) r.pb(v);
    }
    oparr(a0)
    auto go=[&](int v) {
        int id=0;
        REP(i,n-1) if(a0[i]==v) id=i;
        ans.pb(id+1);
        // cout<<id+1<<'\n';
        Vi na;
        for(int i=id+1;i<n-1;i++) na.pb(a0[i]);
        na.pb(v);
        for(int i=0;i<id;i++) na.pb(a0[i]);
        a0=na;
        op(v)op(id)oparr(a0)
    };
    bool magic=0;
    oparr(a)oparr(r)
    if(r.size()&1?s==2:s==1) {
        // if(n&1) magic=1;
        // else {
            return {-inf};
            // }
    }
    // cout<<"Yes\n";
    // cout<<r.size()+magic*n<<'\n';
    for(int v:r) go(v);
    return ans;
}
signed main() {
    IOS();
    cin>>n>>s;
    Vi a(n+1);
    REP1(i,n) cin>>a[i];
    Vi a0=a;
    a0.erase(a0.begin());
    Vi ans={-inf};
    REP(i,n) {
        op(i)oparr(a)
        Vi an=solve(n+1,a,a0);
        a.pb(a[0]);
        a.erase(a.begin());
        oparr(an)
        if(an==Vi{-inf}) continue;
        if(SZ(an)<SZ(ans)||ans==Vi{-inf}) ans=an;
    }
    if(ans==Vi{-inf}) {
        cout<<"No\n";
        return 0;
    }
    cout<<"Yes\n";
    cout<<SZ(ans)<<'\n';
    for(int x:ans) cout<<x<<'\n';
    return 0;
}