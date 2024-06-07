#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,(n)+1)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
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
#define md(x) ((x%(mod)+(mod))%(mod))
#ifdef local
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
const int inf=(1ll<<62);
const int maxn=1e5+5;
const int mod=1e9+7;
signed main() {
    IOS();
    int n,q;
    cin>>n>>q;
    vector<int> a(n+1),p(n+1),p1(n+1),p0(n+1);
    REP1(i,n) cin>>a[i];
    sort(a.begin()+1,a.end());
    REP1(i,n) {
        p[i]=p[i-1]^a[i];
        p1[i]=p1[i-1],p0[i]=p0[i-1];
        if(a[i]&1) p1[i]^=a[i];
        else p0[i]^=a[i];
    }
    REP(i,q) {
        int l,r,t;
        cin>>l>>r>>t;
        if(t==1) cout<<(p[r]^p[l-1])<<'\n';
        if(t==2) cout<<(p0[r]^p0[l-1])<<'\n';
        if(t==3) cout<<(p1[r]^p1[l-1])<<'\n';
    }
    return 0;
}
