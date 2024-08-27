#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
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
const ll inf=(1ll<<63)-1;
const int maxn=2e5+5;
const ll mod=1e9+7;
void solve() {
    int n;
    cin>>n;
    vector<int> k(n);
    REP(i,n) cin>>k[i];
    int l=0,r=0;
    map<int,int> m;
    int an=0;
    while(r<n) {
        while(r<n&&m[k[r]]==0) {
            m[k[r++]]=1;
//            r++;
        }
        an=max(an,r-l);
        m[k[l++]]=0;
//        l++;
    }
    cout<<an<<"\n";
}
signed main() {
    IOS();
    solve();
    return 0;
}
