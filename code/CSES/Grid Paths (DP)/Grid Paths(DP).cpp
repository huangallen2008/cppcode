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
void solve() {
    int n;
    cin>>n;
    vector<vector<int>> m(n+1,vector<int>(n+1)),an(n+1,vector<int>(n+1));
    an[0][1]=1;
    REP1(i,n) {
        REP1(j,n) {
            char c;
            cin>>c;
            if(c=='.') an[i][j]=(an[i-1][j]+an[i][j-1])%mod;
        }
    }
    cout<<an[n][n]<<"\n";
}
signed main() {
    IOS();
    solve();
    return 0;
}
