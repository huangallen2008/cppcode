#include<bits/stdc++.h>
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
const int inf=(1ll<<63)-1;
const int maxn=1e5+5;
const int mod=1e9+7;
vector<int> a;
int n,r;
bool f(int c) {
    if(c==0) return 1;
    REP(i,n) {
        c+=(c+r-1)/r-a[i];
        if(c>2e14) return 0;
        if(c<=0) return 1;
    }
    return 0;
}
signed main()
{
    IOS();
    cin>>n>>r;
    a=vector<int>(n);
    REP(i,n) cin>>a[i];
    int l=0,r=2e14+1,m;
    while(l<r) {
        m=(l+r+1)/2;
        if(f(m)) l=m;
        else r=m-1;
    }
    cout<<l<<endl;
    return 0;
}
