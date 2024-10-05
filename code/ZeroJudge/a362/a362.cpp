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
#define IOS() cin.sync_with_stdio(0),cin.tie(0),cout.tie(0)
const int inf=(1ll<<62)-1;
const int maxn=2e5+5;
const int mod=1e9+7;
struct st {
    int h,w,id;
};
bool so(st a,st b) {
    if(a.h==b.h) {
        if(a.w==b.w) return a.id<b.id;
        return a.w<b.w;
    }
    return a.h<b.h;
}
main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n;
    cin>>n;
    vector<st> a(n);
    REP(i,n) {
        int x,y;
        cin>>x>>y;
        a[i]={x,y,i};
    }
    sort(ALL(a),so);
    int an=0;
    REP(i,n) an+=abs(a[i].id-i);
    cout<<an<<"\n";
    return 0;
}
