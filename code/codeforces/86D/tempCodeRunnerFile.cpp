#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
// #pragma GCC target("avx2,sse4,bmi,popcnt")
// #define int long long
#define ll long long
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
const int maxn=2e5+5;
const int sn=500;
const int maxv=1e6+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
struct qur {
    int l,r,id;
};
int cnt[maxv];
ll an=0;
void insert(int x) {
    an+=(ll)x*(cnt[x]++<<1|1);
}
void erase(int x) {
    an-=x*(--cnt[x]<<1|1);
}
signed main() {
    IOS();
    int n,t;
    cin>>n>>t;
    vector<int> a(n);
    REP(i,n) cin>>a[i];
    vector<qur> q(t);
    REP(i,t) {
        int l,r;
        cin>>l>>r,l--,r--;
        q[i]={l,r,i};
    }
    vector<int> s(n);
    REP(i,n) s[i]=i/sn;
    sort(ALL(q),[&](qur a,qur b) { if(s[a.l]!=s[b.l]) return s[a.l]<s[b.l]; if(s[a.l]&1) return a.r>b.r;return a.r<b.r; });
    REP(i,t) {
        cout<<q[i].l<<' '<<q[i].r<<endl;
    }
    int il=0,ir=-1;
    vector<int> ans(t);
    for(auto [l,r,id]:q) {
        while(il>l) insert(a[--il]);
        while(ir<r) insert(a[++ir]);
        while(il<l) erase(a[il++]);
        while(ir>r) erase(a[ir--]);
        ans[id]=an;
    }
    for(int &x:ans) cout<<x<<'\n';
    return 0;
}