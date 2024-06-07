#include <bits/stdc++.h>
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
#define md(x) (x%mod+mod)%mod
#define IOS() cin.sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define op(x) cout<<#x<<"="<<x<<endl;
#define opa(x) cout<<#x<<": [";REP(i,x.size())cout<<x[i]<<" ";cout<<"] size:"<<x.size()<<endl;
const int inf=(1ll<<62)-1;
const int maxn=1e5+5;
const int mod=1e9+7;
main() {
    IOS();
    int n,m;
    cin>>n>>m;
    vector<int> t(n),w(n);
    REP(i,n) {
        int x,y;
        cin>>x>>y>>t[i]>>w[i];
    }
    int l=0,r=0;
    int p=0,c=0;
    int an=0;
    while(r<n) {
        while(r<n&&p+t[r]<m) {
            c+=w[r];
            p+=t[r];
            r++;
        }
        an=max(an,c);
        if(r==n) break;
        c-=w[l];
        p-=t[l];
        l++;
    }
    cout<<an<<"\n";
    return 0;
}
/*
7 15
0 0 3 1
0 0 2 3
0 0 3 1
0 0 1 4
0 0 5 5
0 0 4 3
0 0 2 5

*/
