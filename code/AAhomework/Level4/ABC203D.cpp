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
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) cout<<(#x)<<":";REP(idd,(x).size()) cout<<x[idd]<<" ";cout<<endl;
#define entr cout<<endl;
#define double long double
const int inf=(1ll<<62);
const int maxn=100+5;
const int maxV=1e9+5;
const int mod=1e9+7;
int n,k;
int get_an(vector<vector<int>> &t) {
    vector<vector<int>> p(n+1,vector<int>(n+1));
    REP1(i,n) {
        REP1(j,n) p[i][j]=p[i-1][j]+p[i][j-1]-p[i-1][j-1]+t[i][j];
    }
    int r=-inf;
    for(int i=k;i<=n;i++) {
        for(int j=k;j<=n;j++) {
            int t=p[i][j]-p[i][j-k]-p[i-k][j]+p[i-k][j-k];
            r=max(r,t);
        }
    }
    return r;
}
signed main() {
    IOS();
    cin>>n>>k;
    vector<vector<int>> a(n+1,vector<int>(n+1));
    REP1(i,n) {
        REP1(j,n) cin>>a[i][j];
    }
    int l=0,r=maxV,m;
    while(l<r) {
        m=(l+r)/2;
        vector<vector<int>> t(n+1,vector<int>(n+1));
        REP1(i,n) {
            REP1(j,n) {
                t[i][j]=(a[i][j]<=m?1:-1);
            }
        }
        int res=get_an(t);
//        op(l)op(r)op(m)ope(res)
        if(res>=0) r=m;
        else l=m+1;
    }
    cout<<l<<'\n';
    return 0;
}
