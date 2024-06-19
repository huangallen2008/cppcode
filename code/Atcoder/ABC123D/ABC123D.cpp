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
const int maxn=7e5+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
bool so(int a,int b) {return a>b;}
struct E {
    int v,id,now;
};
struct so_E {
    bool operator()(E &a,E &b) {
        return a.v<b.v;
    }
};
signed main() {
    IOS();
    int x,y,z,k;
    cin>>x>>y>>z>>k;
    vector<int> a(x),b(y),c(z);
    REP(i,x) cin>>a[i];sort(ALL(a),so);
    REP(i,y) cin>>b[i];sort(ALL(b),so);
    REP(i,z) cin>>c[i];sort(ALL(c),so);
    priority_queue<E,vector<E>,so_E> pq;
    pq.push({a[0]+b[0]+c[0],0,0});
    REP(rd,k) {
        auto [v,id,now]=pq.top();
        cout<<v<<'\n';
        pq.pop();
        if(now==0){
            if(id<x-1)pq.push({v-a[id]+a[id+1],id+1,0});
            pq.push({v-b[0]+b[1],1,1});
            pq.push({v-c[0]+c[1],1,2});
        }
        if(now==1) {
            if(id<y-1)pq.push({v-b[id]+b[id+1],id+1,1});
            pq.push({v-c[0]+c[1],1,2});
        }
        if(now==2&&id<z-1)pq.push({v-c[id]+c[id+1],id+1,2});
    }
    return 0;
}