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
int eval(vector<int> &a,int m) {//比m大的pair數量
    int n=a.size();
    int cnt=0;
    REP(i,n) {
        cnt+=upper_bound(ALL(a),m-a[i])-a.begin();
        if(a[i]*2<=m) cnt++;
    }
    cnt/=2;
    cnt=n*(n+1)/2-cnt;
    return cnt;
}
int solve(int n,int k,vector<int> &a) {
    int l=-2e9,h=2e9,m;//cnt(h)<k cnt(h-1)>=k
    while(l<h) {
        m=l+(h-l)/2;
        int cnt=eval(a,m);
        if(cnt<k) h=m;
        else l=m+1;
    }
    return h;
}
signed main()
{
    IOS();
    int n,k;
    cin>>n>>k;
    vector<int> a;
    REP(i,n) cin>>a[i];//(a[i]+a[i])
    sort(ALL(a));
    int an=solve(n,k,a);
    if(an%2==0) cout<<an/2<<"\n"<<1<<"\n";
    else cout<<an<<"\n"<<2<<"\n";
    return 0;
}
