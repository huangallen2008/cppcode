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
#define ld long double
const int inf=(1ll<<62);
const int maxn=1e5+5;
const int mod=1e9+7;
signed main() {
    IOS();
    int n,m;
    cin>>n>>m;
    vector<int> t(n),v(n);
    vector<pii> a(n);
    REP(i,n) cin>>t[i]>>v[i];
    REP(i,n) a[i]={t[i],v[i]};
    int mx=0;
    REP(i,n) mx=max(mx,v[i]);
    int mt=m/t[i];
    int cnt=0;
    REP(i,n) if(v[i]==mx) cnt++;
    REP(i,n) {
        if(mt==0)
        if(v[i]==mx) {
            cout<<'1';
            mt--;
        }
    }
//    ld mx=0;
//    REP(i,n) {
//        if(t[i]<=m)mx=max(mx,(ld)v[i]/t[i]);
//    }
//    if(mx==0) {
//        REP(i,n) cout<<'0';
//        cout<<'\n';
//        return 0;
//    }
//    REP(i,n) {
//        if((ld)((ld)v[i]/t[i])==mx) {
//            REP(j,n) {
//                if(j==i) cout<<'1';
//                else cout<<'0';
//            }
//            cout<<'\n';
//            return 0;
//        }
//    }
    return 0;
}
