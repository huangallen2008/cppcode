#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
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
#ifdef LOCAL
#define op(x) cout<<#x<<"="<<x<<", ";
#define ope(x) cout<<#x<<"="<<x<<endl;
#define oparr(x) cout<<#x<<":";REP(i,x.size()) cout<<x[i]<<" ";cout<<" size="<<x.size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=998244353;
const int maxn=2e6+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
//shuffle(a,a+n,rng)
bool so(pii a,pii b) {
    return abs(a.s)>abs(b.s);
}
void solve() {
    int n;
    cin>>n;
    vector<int> a(n+2),ps(n+2),gl(n+2),gr(n+2);
    REP1(i,n) {
        cin>>a[i];
        ps[i]=ps[i-1]+a[i];
    }
    ps[n+1]=inf;
    REP1(i,n) {
        if(a[i]==a[i-1]) gl[i]=gl[i-1];
        else gl[i]=i-1;
    }
    RREP1(i,n) {
        if(a[i]==a[i+1]) gr[i]=gr[i+1];
        else gr[i]=i+1;
    }
    REP1(i,n) {
        int r=inf;
        int id=upper_bound(ps.begin()+i+1,ps.end(),ps[i]+a[i])-ps.begin();
        if(id<n+1) {
            if(gr[i+1]<=n) r=min(r,max(id-i,a[i+1]>a[i]?0:gr[i+1]-i));
            else {
                if(a[i+1]>a[i]) r=1;
            }
//                op(i)op(1)ope(r)
        }
        id=lower_bound(ps.begin(),ps.begin()+i,ps[i-1]-a[i])-ps.begin();
        if(ps[i-1]>a[i]) {
            if(gl[i-1]>0) r=min(r,max(i-id,a[i-1]>a[i]?0:i-gl[i-1]));
            else {
                if(a[i-1]>a[i]) r=1;
            }
//                op(i)op(2)ope(r)
        }
        if(r==inf) cout<<"-1 ";
        else cout<<r<<' ';
//        entr
    }
    cout<<'\n';
}
signed main() {
    IOS();
    int T;
    cin>>T;
    while(T--) {
        solve();
    }
    return 0;
}
