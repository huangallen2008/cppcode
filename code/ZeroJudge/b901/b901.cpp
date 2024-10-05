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
#define b(x) ;
const int inf=(1ll<<62);
const int maxn=1e5+5;
const int mod=1e9+9;
int p2(int k) {
    return 2ll<<k;
}
int p5(int k) {
    int r=1,t=5;
    while(k>0) {
        if(k%2==1) r*=t;
        t*=t;
        k>>=1;
    }
    return r;
}
vector<vector<int>> h;
vector<int> a={1,1,1,3,2,2,2,4,2,8};
vector<int> a={};
int n;
int f(int i) {
    if(p2(i)>n) return 1;
    int np=n/(p2(i));
    int r=0;
    while(np>0) {
        r+=(p2(((int)(n/10))*3)*a[np%10])%10;
        np/=5;
    }
    return h[i][j]=((p2(((int)(n/10))*3)*a[n%10])%10*f(i+1))%10;
}
signed main()
{
    IOS();
    int T;
    cin>>T;
    while(T--) {
        h=vector<vector<int>>(50,vector<int>(22));

    }
    return 0;
}
