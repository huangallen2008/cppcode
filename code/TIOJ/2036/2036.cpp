#include<bits/stdc++.h>
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
const int inf=(1ll<<62);
const int maxn=1e5+5;
const int mod=1e9+7;
signed main()
{
    IOS();
    int n;
    cin>>n;
    vector<vector<int>> v(3,vector<int>(8));
    REP(i,n) {
        int c,a,r,d;
        cin>>c>>a>>r>>d;
        v[c-1][d+r*2+a*4]++;
    }
    int an=0;
    REP(i,8) REP(j,8) REP(k,8) if((i|j|k)==7) an+=v[0][i]*v[1][j]*v[2][k];
    cout<<an<<"\n";
    return 0;
}