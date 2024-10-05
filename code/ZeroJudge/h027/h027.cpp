#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
const int inf=(1ll<<62)-1;
const int maxn=2e5+5;
const int mod=1e9+7;
main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    int s,t,n,m,r,an1=0,an2=inf,c=0;
    cin>>s>>t>>n>>m>>r;
    vector<vector<int>> a(s,vector<int>(t)),b(n,vector<int>(m));
    REP(i,s) REP(j,t) cin>>a[i][j];
    REP(i,n) REP(j,m) cin>>b[i][j];
    REP(i,s) REP(j,t) c+=a[i][j];
    for(int i=0;i+s<=n;i++) {
        for(int j=0;j+t<=m;j++) {
            int c1=0,c2=0;
            REP(ni,s) {
                REP(nj,t) {
                    c1+=(a[ni][nj]!=b[i+ni][j+nj]);
                    c2+=b[i+ni][j+nj];
                }
            }
            if(c1<=r) {
                an1++;
                an2=min(an2,abs(c-c2));
            }
        }
    }
    if(an1==0) cout<<"0\n-1\n";
    else cout<<an1<<"\n"<<an2<<"\n";
    return 0;
}
