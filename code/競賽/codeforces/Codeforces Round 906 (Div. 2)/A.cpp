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
#define pipii pair<int,pii>
#define Graph vector<vector<int>>
#define IOS() cin.sync_with_stdio(0),cin.tie(0),cout.tie(0)
const int inf=(1ll<<62);
const int maxn=1e6+5;
const int mod=1e9+7;
void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    REP(i,n) cin>>a[i];
    vector<int> c(1e5+5);
    REP(i,n) {
        c[a[i]]++;
    }
    pii an={0,0};
    REP(i,1e5+1) {
        if(c[i]==n) {
            an={1,1};
            break;
        }
        if(!an.f&&c[i]>=(n+1)/2) an.f++;
        else if(c[i]>=n/2) an.s++;
    }
    if(an.f&&an.s) cout<<"yes\n";
    else cout<<"no\n";
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
