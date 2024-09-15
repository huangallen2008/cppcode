#include<bits/stdc++.h>
using namespace std;
//#define ll long long
//#define int ll
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
string s;
int v[8][8];
bool ok(int i,int j,int u) {
    if(i<0||i>=7||j<0||j>=7||v[i][j]) return 0;
    return 1;
}
int f(int i,int j,int u) {
    if(ok(i+1,j,u+1)&&ok(i-1,j,u+1)&&!ok(i,j+1,u+1)&&!ok(i,j-1,u+1)) return 0;
    if(!ok(i+1,j,u+1)&&!ok(i-1,j,u+1)&&ok(i,j+1,u+1)&&ok(i,j-1,u+1)) return 0;
    if(i==6&&j==0) {
        if(u>=48) return 1;
        return 0;
    }
    int r=0;
    v[i][j]=1;
    if((s[u]=='U'||s[u]=='?')&&ok(i-1,j,u+1)) r+=f(i-1,j,u+1);
    if((s[u]=='D'||s[u]=='?')&&ok(i+1,j,u+1)) r+=f(i+1,j,u+1);
    if((s[u]=='L'||s[u]=='?')&&ok(i,j-1,u+1)) r+=f(i,j-1,u+1);
    if((s[u]=='R'||s[u]=='?')&&ok(i,j+1,u+1)) r+=f(i,j+1,u+1);
    v[i][j]=0;
    return r;
}
void solve() {
    cin>>s;
    int an=f(0,0,0);
    cout<<an<<"\n";
}
signed main() {
    IOS();
    solve();
    return 0;
}
/*
??????R??????U??????????????????????????LD????D?
????????????????????????????????????????????????
*/
