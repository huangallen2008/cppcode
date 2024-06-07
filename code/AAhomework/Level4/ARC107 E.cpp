#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define int long long
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
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
#define md(x) (((x)%(mod)+(mod))%(mod))
#define op(x) cout<<#x<<"="<<x<<", ";
#define ope(x) cout<<#x<<"="<<x<<endl;
#define oparr(x) cout<<#x<<":";REP(i,x.size()) cout<<x[i]<<" ";cout<<endl;
#define entr cout<<endl;
const int inf=(1ll<<62);
const int maxn=1e5+5;
const int mod=1e9+7;
int mex(int a,int b) {
    if(a!=0&&b!=0) return 0;
    if(a!=1&&b!=1) return 1;
    return 2;
}
signed main() {
    IOS();
    int n;
    cin>>n;
    vector<vector<int>> r(4,vector<int>(n)),c(n,vector<int>(4));
    vector<int> cnt(3);
    if(n<=4) {
        REP(i,n) cin>>r[0][i];
        REP1(i,n-1) cin>>r[i][0];
        REP1(i,n-1) REP1(j,n-1) r[i][j]=mex(r[i-1][j],r[i][j-1]);
        REP(i,n) REP(j,n) cnt[r[i][j]]++;
        cout<<cnt[0]<<' '<<cnt[1]<<' '<<cnt[2]<<'\n';
        return 0;
    }
    REP(i,n) cin>>r[0][i];
    REP1(i,n-1) cin>>c[i][0];
    c[0][0]=r[0][0];
    REP1(i,3) r[i][0]=c[i][0];
    REP1(i,3) c[0][i]=r[0][i];
    REP1(i,3) REP1(j,n-1) r[i][j]=mex(r[i-1][j],r[i][j-1]);
    REP1(i,n-1) REP1(j,3) c[i][j]=mex(c[i-1][j],c[i][j-1]);
    REP(i,4)REP(j,n) cnt[r[i][j]]++;
    for(int i=4;i<n;i++) REP(j,4) cnt[c[i][j]]++;
    cnt[r[3][3]]+=(n-4);
    for(int i=4;i<n;i++) cnt[r[3][i]]+=n-i-1;
    for(int i=4;i<n;i++) cnt[c[i][3]]+=n-i-1;
    cout<<cnt[0]<<' '<<cnt[1]<<' '<<cnt[2]<<'\n';
    return 0;
}
