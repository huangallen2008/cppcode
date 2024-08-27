#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,n+1)
#define RREP(i,n) for(int i=n-1;i>=0;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)(x.size())
#define SQ(x) (x)*(x)
#define pii pair<int,int>
#define Graph vector<vector<int>>
#define IOS() cin.sync_with_stdio(0),cin.tie(0),cout.tie(0)
const ll inf=(1ll<<63)-1;
const int maxn=1e4+5;
const ll mod=1e9+7;
signed main()
{
    IOS();
    int m,n,p;
    cin>>m>>n>>p;
    vector<int> a(m+1);
    vector<vector<pii>> v(n,vector<pii>(p));
    REP(i,n) {
        REP(j,p) cin>>v[i][j].f>>v[i][j].s;
        for(int j=m;j>0;j--) {
            REP(k,p) {
                if(j>=v[i][k].f) a[j]=max(a[j-v[i][k].f]+v[i][k].s,a[j]);
            }
        }
    }
    cout<<a[m]<<endl;
    return 0;
}
