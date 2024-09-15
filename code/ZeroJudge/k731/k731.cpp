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
signed main()
{
    IOS();
    int n;
    cin>>n;
    int d1=0,d2=0,d3=0,d=3;//0:u 1:d 2:l 3:r
    vector<pii> a(n);
    REP(i,n) cin>>a[i].f>>a[i].s;
    REP1(i,n-1) {
        int ld=d;
        if(a[i].f>a[i-1].f) d=3;
        else if(a[i].f<a[i-1].f) d=2;
        else if(a[i].s>a[i-1].s) d=0;
        else d=1;
        if(ld==0) {
            if(d==1) d3++;
            if(d==2) d1++;
            if(d==3) d2++;
        }else if(ld==1) {
            if(d==0) d3++;
            if(d==2) d2++;
            if(d==3) d1++;
        }else if(ld==2) {
            if(d==0) d2++;
            if(d==1) d1++;
            if(d==3) d3++;
        }else {
            if(d==0) d1++;
            if(d==1) d2++;
            if(d==2) d3++;
        }
    }
    cout<<d1<<" "<<d2<<" "<<d3<<"\n";
    return 0;
}
