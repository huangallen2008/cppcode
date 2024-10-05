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
const int inf=(1ll<<63)-1;
const int maxn=1e6+5;
const int mod=1e9+7;
signed main() {
    IOS();
    vector<int> a(maxn+1),b(maxn+1); //a:no,b:yes
    a[0]=1,b[0]=1;
    REP1(i,maxn) {
        a[i]=(a[i-1]*2+b[i-1])%mod;
        b[i]=(b[i-1]*4+a[i-1])%mod;
    }
    int T;
    cin>>T;
    while(T--) {
        int n;
        cin>>n;
        cout<<(a[n-1]+b[n-1])%mod<<"\n";
    }
    return 0;
}
