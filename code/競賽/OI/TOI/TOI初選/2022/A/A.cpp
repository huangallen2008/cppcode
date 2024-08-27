#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
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
const ll inf=(1ll<<63)-1;
const int maxn=1e5+5;
const ll mod=1e9+7;
int n,r;
int x,y;
int an=0;
vector<pii> u;
unordered_map<int,unordered_map<int,int>> mp;
void d() {
    for(int i=-r;i<=r;i++) {
        for(int j=-r;j<=r;j++) {
            if(SQ(abs(i))+SQ(abs(j))<=SQ(r)) u.pb({i,j});
        }
    }
}
signed main()
{
    IOS();
    cin>>n>>r;
    d();
    REP(i,n) {
        cin>>x>>y;
        REP(j,SZ(u)) {
            mp[x+u[j].f][y+u[j].s]++;
            if(mp[x+u[j].f][y+u[j].s]%2) an++;
            else an--;
        }
    }
    cout<<an<<"\n";
    return 0;
}
