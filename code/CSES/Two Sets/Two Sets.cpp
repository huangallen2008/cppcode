#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,n+1)
#define RREP(i,n) for(int i=n-1;i>=0;i--)
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
signed main() {
    IOS();
    int n;
    cin>>n;
    if(n%4==0) {
        cout<<"YES\n";
        cout<<n/2<<"\n";
        for(int i=1;i<=n/4;i++) cout<<i<<" ";
        for(int i=n/4*3+1;i<=n;i++) cout<<i<<" ";
        cout<<"\n";
        cout<<n/2<<"\n";
        for(int i=n/4+1;i<=n/4*3;i++) cout<<i<<" ";
        cout<<"\n";
    }else if(n%4==3) {
        cout<<"YES\n";
        cout<<(n+1)/2<<"\n";
        for(int i=1;i<=(n+1)/4;i++) cout<<i<<" ";
        cout<<(n+1)/2<<" ";
        for(int i=(n+1)/4*3+1;i<=n;i++) cout<<i<<" ";
        cout<<"\n";
        cout<<(n-1)/2<<"\n";
        for(int i=(n+1)/4+1;i<(n+1)/2;i++) cout<<i<<" ";
        for(int i=(n+1)/2+1;i<=(n+1)/4*3;i++) cout<<i<<" ";
        cout<<"\n";
    }
    else cout<<"NO\n";
    return 0;
}
