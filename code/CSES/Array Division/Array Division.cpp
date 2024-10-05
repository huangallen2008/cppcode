#include<bits/stdc++.h>
using namespace std;
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
const int maxn=2e5+5;
const int mod=1e9+7;
bool ok(vector<int> a,int m,int k) {
    int n=a.size();
    int c=1;
    int p=0;
    REP(i,n) {
        if(a[i]>m) return 0;
        if(p+a[i]>m) {
            c++;
            p=a[i];
        }
        else p+=a[i];
    }
    return c<=k;
}
void solve() {
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    REP(i,n) cin>>a[i];
    int l=1,r=1e15,m;
    while(l<r) {
        m=(l+r)/2;
        if(ok(a,m,k)) r=m;
        else l=m+1;
    }
    cout<<l<<"\n";
}
signed main() {
    IOS();
    solve();
    return 0;
}
