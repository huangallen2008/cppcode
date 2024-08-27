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
signed main() {
    IOS();
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    REP(i,n) cin>>a[i];
    bool isi=1;
    REP(i,n-1) if(a[i]>a[i+1]) isi=0;
    if(!isi) {
        REP(i,n) {
            int t=-1;
            for(int j=i+1;j<n;j++) {
                if(a[j]>=a[i]+k) {
                    t=j+1;
                    break;
                }
            }
            cout<<t<<" ";
        }
    }
    else {
        REP(i,n) {
            int an=lower_bound(ALL(a),a[i]+k)-a.begin()+1;
            cout<<(an<=n?an:-1)<<" ";
        }
    }
    cout<<"\n";
    return 0;
}
/*
7 3
4 5 3 2 6 8 7
*/
