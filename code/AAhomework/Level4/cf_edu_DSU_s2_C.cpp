#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define int long long
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
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
#define md(x) (((x)%(mod)+(mod))%(mod))
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) cout<<(#x)<<":";REP(idd,(x).size()) cout<<x[idd]<<" ";cout<<endl;
#define entr cout<<endl;
const int inf=(1ll<<62);
const int maxn=100+5;
const int mod=1e9+7;
struct DSU {
    vector<int> p;
    int n;
    void init(int _n) {
        n=_n;
        p=vector<int>(n);
        REP(i,n) p[i]=i;
    }
    int find(int u) {
        if(p[u]==u) return u;
        return p[u]=find(p[u]);
    }
    void merge(int a,int b) {
        int x=find(a),y=find(b);
        if(x==y) return;
        p[x]=y;
    }
};
signed main() {
    IOS();
    int n,q;
    cin>>n>>q;
    DSU dsu,dsu2;
    dsu.init(n);
    dsu2.init(n);
    REP(i,q) {
        int opt,x,y;
        cin>>opt>>x>>y;
        x--,y--;
        if(opt==1) {
            dsu.merge(x,y);
            if(x>0&&dsu.find(x)==dsu.find(x-1)) dsu2.merge(x-1,x);
            if(y>0&&dsu.find(y)==dsu.find(y-1)) dsu2.merge(y-1,y);
            if(x<n-1&&dsu.find(x)==dsu.find(x+1)) dsu2.merge(x,x+1);
            if(y<n-1&&dsu.find(y)==dsu.find(y+1)) dsu2.merge(y,y+1);
        }
        if(opt==2) {
            int t=dsu2.find(x)+1;
            while(t<=y) {
                dsu2.merge(t-1,t);
                dsu.merge(x,t);
                t=dsu2.find(x)+1;
            }
        }
        if(opt==3) {
            if(dsu.find(x)==dsu.find(y)) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
    return 0;
}
