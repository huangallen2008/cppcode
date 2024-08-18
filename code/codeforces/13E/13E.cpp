#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
#pragma GCC target("avx2,sse4,bmi,popcnt")
// #define int long long
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
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int n,m;
pii ga(int t,vector<int>&a,vector<int>&s,vector<pii>&r) {
    // op(t)
    // int cnt=0;
    if(t+a[t]>=n||s[t+a[t]]>s[t]) {
        // op(cnt)ope(t)
        return {t,1};
    }
    else return {r[t+a[t]].f,r[t+a[t]].s+1};
}
signed main() {
    IOS();
    cin>>n>>m;
    vector<int> a(n);
    REP(i,n) cin>>a[i];
    int sn=sqrt(n);
    vector<int> s(n);
    REP(i,n) s[i]=i/sn;
    vector<pii> r(n);
    RREP(i,n) {
        r[i]=ga(i,a,s,r);
    }
    // oparr(s)
    // REP(i,n) cout<<r[i].s<<' ';entr
    REP(i,m) {
        int opt;
        cin>>opt;
        if(opt==0) {
            int u,v;
            cin>>u>>v,u--;
            a[u]=v;
            int li=u/sn*sn;
            for(int j=min(li+sn,n)-1;j>=li;j--) r[j]=ga(j,a,s,r);
        }
        else {
            int u;
            cin>>u,u--;
            int cnt=0,t=u,la;
            while(1) {
                if(t>=n) {
                    break;
                }
                cnt+=r[t].s;
                la=r[t].f;
                t=r[t].f;
                t+=a[t];
            }
            cout<<la+1<<' '<<cnt<<'\n';
            // op(cnt)ope(la)
        }
    }
    return 0;
}