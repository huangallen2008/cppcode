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
signed main()
{
    IOS();
    int n,m;
    cin>>n>>m;
    vector<int> r(n),c(n);
    REP(i,m) {
        int l,x,y;
        cin>>l>>x>>y;
        x--,y--;
        r[x]=i+1;
        REP1(j,(l-1)/2) {
            if(x+j<n) r[x+j]=i+1;
            if(x-j>=0) r[x-j]=i+1;
        }
        c[y]=i+1;
        REP1(j,(l-1)/2) {
            if(y+j<n) c[y+j]=i+1;
            if(y-j>=0) c[y-j]=i+1;
        }
        int p,a,b,c2,d;
        cin>>p>>a>>b>>c2>>d;
        a--,b--,c2--,d--;
        int an=0,a1=0,a2=0,b1=0,b2=0;
        for(int j=b;j<=d;j++) {
            if(c[j]>0&&c[j]!=p&&c[j]>p) a2++;
            if(c[j]==p) a1++;
        }
        for(int j=a;j<=c2;j++) {
            if(r[j]>0&&r[j]!=p&&r[j]>p) b2++;
            if(r[j]==p) b1++;
        }
//        cout<<"r:";REP(j,n) cout<<r[j]<<" ";cout<<"\n";
//        cout<<"c:";REP(j,n) cout<<c[j]<<" ";cout<<"\n";
//        cout<<a1<<" "<<a2<<" "<<b1<<" "<<b2<<"\n";
        an=(d-b+1-a2)*b1+a1*(c2-a+1-b2)-a1*b1;
        cout<<an<<"\n";
    }
    return 0;
}
