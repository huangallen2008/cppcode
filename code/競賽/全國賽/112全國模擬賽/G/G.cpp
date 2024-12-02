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
int n;
Vi a,b;
vector<pii> v;
vector<pipii> vb;
bool check(int m) {
    REP(i,n) if(v[i].f+v[i].s>m) return 0;
    priority_queue<pii> pq;
    int it=0;
    Vi used(n);
    ope(m)
    REP(i,n) {
        if(used[i]) continue;
        while(it<n&&vb[it].s.s<=m-v[i].f) pq.push({vb[it].s.f,vb[it].f}),it++;
        while(pq.size()&&pq.top().s<=i) pq.pop();
        if(pq.size()==0) return 0;
        auto [x,y]=pq.top();
        pq.pop();
        used[y]=1;
        op(v[i].f)ope(v[i].f+v[y].s)
    }
    entr
    return 1;
}
signed main() {
    IOS();
    cin>>n;
    a=b=Vi(n);
    v=vector<pii>(n);
    REP(i,n) cin>>a[i];
    REP(i,n) cin>>b[i];
    REP(i,n) v[i]={a[i],b[i]};
    sort(ALL(v),greater<pii>());
    vb=vector<pipii>(n);
    REP(i,n) vb[i]={i,v[i]};
    sort(ALL(vb),[&](pipii a,pipii b) {
        return a.s.s<b.s.s;
    });
    int lb=0,rb=1e9,mb;
    while(lb<rb) {
        mb=lb+rb>>1;//fir mb : check(mb)=1
        if(check(mb)) rb=mb;
        else lb=mb+1;
    }
    cout<<lb<<'\n';
    return 0;
}