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
const int maxn=5e3+5;
const int mod=1e9+7;
main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    vector<int> a;
    int T;
    cin>>T;
    while(T--) {
        int an=0,n;
        cin>>n;
        a=vector<int>(n);
        REP(i,n) cin>>a[i];
        REP(l,n) {
            vector<int> mx(n),mn(n);
            mx[l]=a[l]; mn[l]=a[l];
            for(int r=l+1;r<n;r++) {
                mx[r]=max(mx[r-1],a[r]);
                mn[r]=min(mn[r-1],a[r]);
                if(r-l==abs(a[r]-a[l])&&mn[r]==min(a[l],a[r])&&mx[r]==max(a[l],a[r])) an++;
            }
        }
        cout<<an<<"\n";
    }
    return 0;
}
