#include<bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3")
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) for(int i=0;i<n;i++)
//#define REP(i,n) FOR(i,0,n)
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
#define md(x) (x%mod+mod)%mod
#define op(x) cout<<#x<<"="<<x<<", ";
#define ope(x) cout<<#x<<"="<<x<<endl;
#define oparr(x) cout<<#x<<":";REP(i,x.size()) cout<<x[i]<<" ";cout<<" size="<<x.size()<<endl;
#define entr cout<<endl;
const int inf=(1ll<<62);
const int maxn=2e5+5;
const int maxk=(int)1e18;
const int mod=1e9+7;
void solve() {
    int n,q;
    cin>>n>>q;
//    op(n)ope(q)
    vector<int> a(n);
    REP(i,n) cin>>a[i];
    int mxi=60;
    vector<int> cost(mxi);
    vector<bool> ok(mxi,1);
    RREP(i,mxi) {
        REP(j,n) {
            if(!((a[j]>>i)&1)) {
                if(cost[i]<=maxk) cost[i]+=(1ll<<i)-(a[j]&((1ll<<i)-1));
                else ok[i]=0;
            }
        }
    }
//    oparr(cost)
    REP(rd,q) {
        int k;
        cin>>k;
        vector<int> b=a;
        bool h1=0;
        int an=0;
        RREP(i,mxi) {
//            op(rd)ope(i)
            if(!ok[i]) continue;
            if(h1) {
                int ct=0;
                REP(j,n) if(!((b[j]>>i)&1)) ct+=(1ll<<i)-(b[j]&((1ll<<i)-1));
//                op(k)op(i)ope(ct)
                if(ct<=k) {
                    k-=ct;
                    an=an|(1ll<<i);
                    REP(j,n) if(!((b[j]>>i)&1)) b[j]=b[j]&~((1ll<<i)-1);
                }
            }
            else {
                if(cost[i]<=k) {
                    k-=cost[i];
                    an=an|(1ll<<i);
                    h1=1;
                    REP(j,n) if(!((b[j]>>i)&1))b[j]=b[j]&~((1ll<<i)-1);
                }
            }
        }
        cout<<an<<'\n';
//        ope(1)
    }
}
signed main() {
    IOS();
//    int T;
//    cin>>T;
//    while(T--) {
        solve();
//    }
    return 0;
}
/*
1 1
10
5
*/
