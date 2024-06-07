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
#define oparr(x) cout<<#x<<":";REP(i,x.size()) cout<<x[i]<<" ";cout<<" size="<<x.size()<<endl;
#define entr cout<<endl;
const int inf=(1ll<<62);
const int maxn=1e5+5;
const int mod=1e9+7;
vector<int> a;
int n,k;
int mx;
bool ok(int m) {
    if(mx>=m) return 1;
    REP1(i,n) {
        vector<int> t=a;
        if(t[i]>=m) return 1;
        int u=m-t[i];
        t[i]=m;
        for(int j=i+1;j<=n+1;j++) {
            if(t[j]+1<t[j-1]) {
                u+=t[j-1]-1-t[j];
                t[j]=t[j-1]-1;
            }
            else break;
        }
        if(u<=k) return 1;
    }
    return 0;
}
void solve() {
    cin>>n>>k;
    a=vector<int>(n+2);
    a[n+1]=-inf;
    REP1(i,n) cin>>a[i];
    mx=0;
    REP1(i,n) mx=max(mx,a[i]);
    int l=mx,r=3e8+1,m;
    while(l<r) {
        m=l+(r-l+1)/2;
        if(ok(m)) l=m;
        else r=m-1;
    }
    cout<<l<<'\n';
}
signed main() {
    IOS();
    int T;
    cin>>T;
    while(T--) {
        solve();
    }
    return 0;
}
