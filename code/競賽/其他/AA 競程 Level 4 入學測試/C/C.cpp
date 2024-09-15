#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define int long long
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,(n)+1)
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
#define md(x) ((x%(mod)+(mod))%(mod))
#define op(x) cout<<#x<<"="<<x<<", ";
#define ope(x) cout<<#x<<"="<<x<<endl;
#define oparr(x) cout<<#x<<":";REP(i,x.size()) cout<<x[i]<<" ";cout<<" size="<<x.size()<<endl;
#define entr cout<<endl;
const int inf=(1ll<<62);
const int maxn=1e5+5;
const int mod=1e9+7;
int a[3][3],t[3][3],rc[3],cc[3];
void solve() {
    REP(i,3) REP(j,3) cin>>a[i][j];
    int ans=0;
    REP(r,27) {
        REP(c,27) {
            REP(i,3) REP(j,3) t[i][j]=a[i][j];
            rc[0]=r/9;
            rc[1]=(r/3)%3;
            rc[2]=r%3;
            cc[0]=c/9;
            cc[1]=(c/3)%3;
            cc[2]=c%3;
            bool ok=1;
            REP(i,3) {
                REP(j,3) {
                    t[i][j]-=(rc[i]+cc[j]);
                    if(t[i][j]<0) {
                        ok=0;
                        break;
                    }
                }
                if(!ok) break;
            }
            if(!ok) continue;
            int an=0;
            REP(i,3) an+=rc[i];
            REP(i,3) an+=cc[i];
            REP(i,3) REP(j,3) an+=(t[i][j]/3);
            ans=max(ans,an);
        }
    }
    cout<<ans<<'\n';
}
signed main() {
    IOS();
    int T;
    cin>>T;
    assert(T<=10000);
    while(T--) {
        solve();
    }
    return 0;
}
