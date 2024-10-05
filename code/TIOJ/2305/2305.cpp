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
const int inf=(1ll<<62);
const int maxn=1e5+5;
const int mod=1e9+9;
int lg(int x) {
    if(x==1) return 0;
    return lg(x>>1)+1;
}
signed main()
{
    IOS();
    int T;
    cin>>T;
    while(T--) {
        int n,m;
        cin>>n>>m;
        vector<int> t(m);
        t[0]=1;
        for(int i=1;i<m;i++) t[i]=(t[i-1]*i)%m;
        if(n>=2*m) cout<<"0\n";
        else if(n>=m) {
            cout<<(lg(m)*t[m-1]*t[n%m])%m<<"\n";
        }
        else {
            vector<int> rt(n+2);
            rt[n]=n;
            rt[n+1]=1;
            int an=0;
            for(int i=n-1;i>=0;i--) rt[i]=(rt[i+1]*i)%m;
            REP1(i,n) an=(an+(lg(i)*t[i-1]*rt[i+1])%m)%m;
            cout<<an<<"\n";
        }
    }
    return 0;
}
// 3 3 2 5 4 9982 10007
