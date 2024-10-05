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
const int inf=(1ll<<63)-1;
const int maxn=2e5+5;
const int mod=998244353;
void solve() {
    int n;
    cin>>n;
    vector<vector<int>> c(50),a(n);
    vector<int> vi(50);
    REP(i,n) {
        int k;
        cin>>k;
        REP(j,k) {
            int x;
            cin>>x;
            x--;
            vi[x]=1;
            c[x].pb(i);
            a[i].pb(x);
        }
    }
    int an=0;
    REP(i,50) {
        if(vi[i]==0) continue;
        int ni=0;
        int cnt=0;
        vector<bool> v(50);
        REP(j,n) {
            if(ni<c[i].size()&&j==c[i][ni]) {
                ni++;
                continue;
            }
            for(int p:a[j]) {
                cnt+=(v[p]==0);
                v[p]=1;
            }
        }
//        cout<<i<<":"<<cnt<<"\n";
        an=max(an,cnt);
    }
    cout<<an<<"\n";
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
