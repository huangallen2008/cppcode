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
const int maxn=5000+5;
const int mod=1e9+7;
signed main() {
    IOS();
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    REP(i,n) cin>>a[i];
    int s=0;
    REP(i,n) s+=a[i];
    vector<int> isp(maxn+5,1);
    isp[0]=0,isp[1]=0;
    REP1(i,maxn) {
        if(isp[i]==1) {
            for(int j=2;i*j<maxn;j++) {
                isp[i*j]=0;
            }
        }
    }
    int mx=0;REP(i,n) mx=max(mx,a[i]);
    int an=0;
    for(int i=k;i<=mx;i++) {
        if(i==1) {
            an=s;
            break;
        }
        if(isp[i]) {
            int r=0;
            REP(j,n) r+=a[j]%i;
            an=max(an,s-r);
        }
    }
    cout<<an<<"\n";
    return 0;
}
