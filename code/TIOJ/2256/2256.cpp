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
const int maxn=3e3+5;
const int mod=1e9+7;
int c,T;
vector<int> p,s,n,pp,pn;
vector<vector<int>> r,pr;
pii f(int a,int b) {
//    if(b==c+1) return {,0};
    return {(pn[b]-pn[a])*(pp[b]+s[b]),pr[b][b]-pr[b][a]};
}
int d() {
    vector<vector<int>> dp(c+1,vector<int>(T+1,-inf));
    REP(i,T+1) dp[0][i]=0;
    REP1(i,c) {
        REP(j,T+1) {
            REP(k,i) {
                if(i==c&&j-pp[c]*(pn[i]-pn[k])>=0) {
                    dp[i][j]=max(dp[i][j],dp[k][j-pp[c]*(pn[i]-pn[k])]);
                }
                pii t=f(k,i);
                if(t.f>j) continue;
//                cout<<i<<" "<<j<<"="<<k<<","<<j-t.f<<"+"<<t.s<<"\n";
                dp[i][j]=max(dp[i][j],dp[k][j-t.f]+t.s);
            }
//            cout<<dp[i][j]<<" ";
        }
//        cout<<endl;
    }
    if(dp[c][T]<0) return -1;
    return dp[c][T];
}
main() {
    IOS();
    cin>>c>>T;
    p=vector<int>(c+1);
    s=vector<int>(c+1);
    n=vector<int>(c+1);
    pp=vector<int>(c+1);
    pn=vector<int>(c+1);
    REP1(i,c) cin>>p[i];
    REP1(i,c) cin>>s[i];
    REP1(i,c) cin>>n[i];
    REP1(i,c) pp[i]=pp[i-1]+p[i];
    REP1(i,c) pn[i]=pn[i-1]+n[i];
    r=vector<vector<int>>(c+1,vector<int>(c+1));
    pr=vector<vector<int>>(c+1,vector<int>(c+1));
    REP1(i,c) REP1(j,i) cin>>r[i][j];
    REP1(i,c) REP1(j,i) pr[i][j]=pr[i][j-1]+r[i][j];
    cout<<d()<<"\n";
    return 0;
}
/*
2 18
1 2
3 3
3 3
3
2 3

2 29
1 2
3 3
3 3
3
2 3

*/
