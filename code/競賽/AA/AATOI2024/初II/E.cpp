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
const int maxn=7e5+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
struct P {
    int sum,fix,cntr,cnta,ls;
};
struct pq_P {
    const bool operator()(const P &a,const P &b) const {
        return a.sum>b.sum;
    }
};
bool so(int a,int b) { return a>b; }
signed main() {
    IOS();
    int n,k,l,r;
    cin>>n>>k>>l>>r;
    vector<int> a(n+1),p(n+1);
    REP1(i,n) cin>>a[i];
    sort(a.begin()+1,a.end(),so);
    REP1(i,n) p[i]=p[i-1]+a[i];
    // priority_queue<P,vector<P>,pq_P> pq;
    multiset<P,pq_P> pq;
    for(int cnta=l;cnta<=r;cnta++)pq.insert({p[cnta],0,cnta,cnta,0});
    int an=0;
    REP1(rd,k) {
        for(auto [ss,ttt,ttt2,ttt3,ttt4]:pq) cout<<ss<<' ';entr
        auto [sum,fix,cntr,cnta,ls]=*pq.begin();
        pq.erase(pq.begin());
        an+=sum;
        op(fix)op(ls)ope(sum)
        if(fix+cntr<n) pq.insert({sum+a[fix+cntr+1]-a[fix+cntr],fix+cntr,1,cnta,fix});
        for(;fix>ls;) {
            sum+=a[fix]-a[fix-1],cntr++,fix--;
            pq.insert({sum,fix,cntr,cnta,ls});
            // if(pq.size()+rd>k) pq.erase(prev(pq.end()));
        }
    }
    cout<<an<<'\n';
    return 0;
}