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
const int maxn=2e5+5;
const ll mod=1e9+7;
vector<vector<bool>> m(8,vector<bool>(8)),an(8,vector<bool>(8));
vector<bool> c(8),r(8),m1(15),m2(15);
int f(int i) {
    if(i==8) return 1;
    int r=0;
    REP(j,8) {
        if(c[j]||m1[i+j]||m2[i-j+7]||m[i][j]) continue;
        c[j]=1,m1[i+j]=1,m2[i-j+7]=1;
        r+=f(i+1);
        c[j]=0,m1[i+j]=0,m2[i-j+7]=0;
    }
    return r;
}
void solve() {
    REP(i,8) {
        REP(j,8) {
            char c;
            cin>>c;
            if(c=='*') m[i][j]=1;
        }
    }
    cout<<f(0)<<"\n";
}
signed main() {
    IOS();
    solve();
    return 0;
}
/*
........
........
........
........
........
........
........
........
*/
