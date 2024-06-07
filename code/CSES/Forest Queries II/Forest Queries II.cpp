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
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
#define md(x) (x%mod+mod)%mod
#define op(x) cout<<#x<<"="<<x<<", ";
#define ope(x) cout<<#x<<"="<<x<<endl;
#define oparr(x) cout<<#x<<":";REP(i,x.size()) cout<<x[i]<<" ";cout<<" size="<<x.size()<<endl;
#define entr cout<<endl;
const int inf=(1ll<<62);
const int maxn=1e3+5;
const int mod=1e9+7;
struct BIT {
//    int b[maxn][maxn];
    int n;
    vector<vector<int>> b;
    void init(int _n) {
        n=_n;
//        memset(b,0,sizeof(b));
        b=vector<vector<int>>(n+1,vector<int>(n+1));
    }
    int ud(int x,int y,int v) {
        vector<int> xi,yi;
        for(int k=x;k<=n;k+=k&-k) xi.pb(k);
        for(int k=y;k<=n;k+=k&-k) yi.pb(k);
        REP(i,xi.size()) REP(j,yi.size()) b[xi[i]][yi[j]]+=v;
    }
    int qu(int x,int y) {
        vector<int> xi,yi;
        for(int k=x;k>0;k-=k&-k) xi.pb(k);
        for(int k=y;k>0;k-=k&-k) yi.pb(k);
        int an=0;
        REP(i,xi.size()) REP(j,yi.size()) an+=b[xi[i]][yi[j]];
        return an;
    }
    int q(int xx,int yy,int x,int y) {
        return qu(x,y)-qu(xx-1,y)-qu(x,yy-1)+qu(xx-1,yy-1);
    }
};
signed main() {
    IOS();
    int n,q;
    cin>>n>>q;
    BIT bit;
    bit.init(n);
    REP1(i,n) {
        REP1(j,n) {
            char c;
            cin>>c;
            if(c=='*') bit.ud(i,j,1);
        }
    }
    REP(i,q) {
        int opt;
        cin>>opt;
        if(opt==1) {
            int x,y;
            cin>>x>>y;
            if(bit.q(x,y,x,y)==1) bit.ud(x,y,-1);
            else bit.ud(x,y,1);
        }
        else {
            int x1,x2,y1,y2;
            cin>>x1>>y1>>x2>>y2;
            cout<<bit.q(x1,y1,x2,y2)<<"\n";
        }
    }
    return 0;
}
