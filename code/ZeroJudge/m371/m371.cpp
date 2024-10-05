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
#define Graph vector<vector<int>>
#define IOS() cin.sync_with_stdio(0),cin.tie(0),cout.tie(0)
const int inf=(1ll<<62);
const int maxn=2e5+5;
const int mod=1e9+7;
signed main() {
    IOS();
    int n,m;
    cin>>n>>m;
    vector<vector<int>> a(n,vector<int>(m)),o(n,vector<int>(m));
    REP(i,n) REP(j,m) cin>>a[i][j];
    int an=0;
    while(1) {
        bool ok=1;
        int l,li,lj;
        REP(i,n) {
            l=-1,li=0,lj=0;
            REP(j,m) {
                if(o[i][j]) continue;
                if(a[i][j]==l) {
                    an+=l;
                    o[i][j]=1;
                    o[li][lj]=1;
                    ok=0;
                }
                else {
                    l=a[i][j];
                    li=i,lj=j;
                }
            }
        }
        REP(j,m) {
            l=-1,li=0,lj=0;
            REP(i,n) {
                if(o[i][j]) continue;
                if(a[i][j]==l) {
                    an+=l;
                    o[i][j]=1;
                    o[li][lj]=1;
                    ok=0;
                }
                else {
                    l=a[i][j];
                    li=i,lj=j;
                }
            }
        }
        if(ok) break;
    }
    cout<<an<<"\n";
    return 0;
}
