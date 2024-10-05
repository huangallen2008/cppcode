#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
#pragma GCC target("avx2,bmi,popcnt")
#define int long long
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define RREP1(i,n) for(int i=(n);i>=1;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)(x.size())
#define SQ(x) (x)*(x)
#define pii pair<int,int>
#define pipii pair<int,pii>
#define Graph vector<vector<int>>
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
#define md(x) (((x)%(mod)+(mod))%(mod))
#define MD(x,M) (((x)%(M)+(M))%(M))
#define ld long double
#define pdd pair<ld,ld>
#ifdef LOCAL
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) cout<<(#x)<<":";REP(allen,(x).size()) cout<<x[allen]<<" ";cout<<" size="<<(x).size()<<endl;
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
void tran(int n,vector<int> &a) {
    REP(i,n) a[i]=-a[i];
    reverse(ALL(a));
}
void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    REP(i,n) cin>>a[i];
    int cp=0,cn=0;
    REP(i,n) {
        if(a[i]>0) cp++;
        else if(a[i]<0)cn++;
    }
    int mxv=0,mi=0;
    bool rev=0;
    REP(i,n) {
        if(abs(a[i])>mxv) {
            mxv=abs(a[i]);
            mi=i;
        }
    }
    vector<pii> an;
    if(max(cp,cn)>12) {
        if(cn>cp) {
            tran(n,a);
            rev=1;
        }
        int val=0,id=0;
        REP(i,n) {
            if(a[i]>0) {
                val=a[i];
                id=i;
            }
        }
        REP(i,5) an.pb({id,id});
        REP(i,n) {
            if(a[i]<0) an.pb({i,id});
        }
    }
    else {
        if(a[mi]<0) {
            tran(n,a);
            rev=1;
            mi=n-1-mi;
        }
        REP(i,n) {
            if(a[i]<0) an.pb({i,mi});
        }
    }
    REP(i,n-1) an.pb({i+1,i});
    if(rev) {
        for(auto &[u,v]:an) {
            u=n-1-u,v=n-1-v;
        }
    }
    cout<<an.size()<<'\n';
    for(auto [x,y]:an) cout<<x+1<<' '<<y+1<<'\n';
}
signed main() {
    IOS();
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}