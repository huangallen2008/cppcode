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
#define op(x) cout<<#x<<"="<<x<<", ";
#define ope(x) cout<<#x<<"="<<x<<endl;
#define oparr(x) cout<<#x<<":";REP(i,x.size()) cout<<x[i]<<" ";cout<<" size="<<x.size()<<endl;
#define entr cout<<endl;
const int mod=1e9+7;
const int maxn=2e5+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
//shuffle(a,a+n,rng)
signed main() {
    IOS();
    int n,t;
    cin>>n>>t;
    int n1=n/2,n2=n-n1,N1=1ll<<n1,N2=1ll<<n2;
    vector<int> a(n1),b(n2),va(N1),vb(N2);
    REP(i,n1) cin>>a[i];
    REP(i,n2) cin>>b[i];
    REP(i,N1) {
        if(i>0) {
            int t=i&-i,r=__lg(t);
            va[i]=va[i&~(1ll<<r)]+a[r];
        }
    }
    REP(i,N2) {
        if(i>0) {
            int t=i&-i,r=__lg(t);
            vb[i]=vb[i&~(1ll<<r)]+b[r];
        }
    }
    int mx=0;
    sort(ALL(vb));
    REP(i,N1) {
        if(va[i]<=t) mx=max(mx,va[i]+*prev(upper_bound(ALL(vb),t-va[i])));
    }
    cout<<mx<<'\n';
    return 0;
}
