#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define int long long
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define RREP1(i,n) for(int i=(n);i>=1;i--)
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
#define oparr(x) cout<<#x<<":";REP(i,x.size()) cout<<x[i]<<" ";cout<<" size="<<x.size()<<endl;
#define entr cout<<endl;
const int mod=1e9+7;
const int maxn=21;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
//shuffle(a,a+n,rng)
int merge(vector<int> &a,vector<int> &b,int t) {
    int r=0;
    map<int,int> mp;
    for(int &x:a) mp[x]++;
    for(int &x:b) {
        r+=mp[t^x];
    }
    return r;
}
vector<int> A[maxn][maxn],B[maxn][maxn];
signed main() {
    IOS();
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int>> g(n,vector<int>(m));
    REP(i,n) REP(j,m) cin>>g[i][j];
    int mid=(n+m-2)/2;
    A[0][0].pb(g[0][0]);
    REP(i,n) {
        REP(j,m) {
            if(i+j<=mid) {
                if(j>0) {
                    for(int x:A[i][j-1]) A[i][j].pb(x^g[i][j]);
                }
                if(i>0) {
                    for(int x:A[i-1][j]) A[i][j].pb(x^g[i][j]);
                }
            }
        }
    }
    B[n-1][m-1].pb(g[n-1][m-1]);
    RREP(i,n) {
        RREP(j,m) {
            if(i+j>=mid) {
                if(j<m-1) {
                    for(int x:B[i][j+1]) B[i][j].pb(x^g[i][j]);
                }
                if(i<n-1) {
                    for(int x:B[i+1][j]) B[i][j].pb(x^g[i][j]);
                }
            }
        }
    }
    int an=0;
    REP(i,mid+1) {
        int j=mid-i;
        if(i>=n||j>=m) continue;
//        op(i)op(j)oparr(A[i][j])oparr(B[i][j])
        an+=merge(A[i][j],B[i][j],k^g[i][j]);
    }
    cout<<an<<'\n';
    return 0;
}
