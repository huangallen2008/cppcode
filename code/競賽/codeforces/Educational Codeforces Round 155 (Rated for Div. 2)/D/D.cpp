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
    vector<int> a(n+1),s(n+1);
    REP1(i,n) cin>>a[i];
//    vector<int>
    REP1(i,n) s[i]=s[i-1]^a[i];
//    REP(i,n+1) cout<<s[i]<<" ";cout<<endl;
    vector<int> p0(32),p1(32),an(32),x0(32),x1(32);
    REP(i,n+1) {
        REP(j,32) {
            x0[j]+=p0[j];
            x1[j]+=p1[j];
            int r=((s[i]>>j)&1);
            if(r==0) {
                an[j]+=x1[j];
                p0[j]=p0[j]+1;
            }
            else {
                an[j]+=x0[j];
                p1[j]++;
            }
            an[j]%=mod;
        }
    }
//    REP(i,4) cout<<an[i]<<" ";cout<<endl;
    int an1=0;
    REP(i,32) an1=(an1+((1<<i)*an[i]))%mod;
    cout<<an1<<"\n";
}
signed main() {
    IOS();
    solve();
    return 0;
}
