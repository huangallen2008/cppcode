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
const int mod=1e9+9;
signed main()
{
    IOS();
    int n,m;
    cin>>n>>m;
    vector<vector<int>> a(n,vector<int>(m));
    vector<pair<pii,int>> an;
    REP(i,n) {
        REP(j,m) {
            cin>>a[i][j];
            if(a[i][j]>0) an.pb({{i+1,j+1},a[i][j]});
        }
    }
    bool ok=1;
    REP(i,n-1) {
        REP(j,n) {
            if(a[i][j]<a[i+1][j]-1||a[i+1][j]<a[i][j]-1) {
                ok=0;
                break;
            }
        }
    }
    REP(i,n) {
        REP(j,n-1) {
            if(a[i][j]<a[i][j+1]-1||a[i][j+1]<a[i][j]-1) {
                ok=0;
                break;
            }
        }
    }
    if(ok) {
        cout<<an.size()<<"\n";
        REP(i,an.size()) {
            cout<<an[i].f.f<<" "<<an[i].f.s<<" "<<an[i].s<<"\n";
        }
    }
    else cout<<"-1\n";
    return 0;
}
