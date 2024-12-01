#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3,unroll-loops,fast-math")
// #pragma GCC target("avx2,sse4,bmi,popcnt")
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
#define oparr(x) cout<<(#x)<<":";for(auto &mken:(x)) cout<<mken<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=1e9+7;
const int maxn=5e5+5;
const int maxb=20;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
struct S {
    int l,r,id;
};
signed main() {
    IOS(); 
    int n;
    cin>>n;
    Vi p(n),l(n),r(n);
    REP(i,n) cin>>p[i],p[i]--;
    REP(i,n) cin>>l[i];
    REP(i,n) cin>>r[i];
    vector<S> hor;
    vector<pii> a(n,{-inf,inf});
    REP(i,n) {
        if(p[i]==-1) hor.pb({l[i],r[i],i});
        else a[p[i]]={l[i],r[i]};
    }
    sort(ALL(hor),[&](S a,S b) {
        return a.l<b.l;
    });
    Vi smnr(n);smnr[n-1]=a[n-1].s;
    RREP(i,n-1) smnr[i]=min(smnr[i+1],a[i].s);
    int it=0;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    int lim=0;
    REP(i,n) {
        if(a[i].f==-inf) {
            while(it<n&&hor[it].l<=smnr[i]) pq.push({hor[it].r,hor[it].id});
            if(pq.size()==0) {
                cout<<"No\n";
                return 0;
            }
            auto [val,id]=pq.top();
            pq.pop();
            if(val<lim) {
                cout<<"No\n";
                return 0;
            }
            a[i]={l[id],val};
            p[id]=i;
        }
        if(a[i].f>smnr[i]||a[i].s<lim) {
            cout<<"No\n";
            return 0;
        } 
        chmax(lim,a[i].f);
    }
    cout<<"Yes\n";
    oparr(p)
    return 0;
}