#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
#pragma GCC target("avx2,bmi,popcnt")
// #define int long long
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
        n=_n+1;
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
    void del(int &x) {
        merge(x,x+1);
    }
};
signed main() {
    IOS();
    int n,q;
    cin>>n>>q;
    DSU dsu0,dsu1;
    dsu0.init(n);
    dsu1.init(n);
    vector<int> a(n);
    REP(i,n) cin>>a[i];
    REP(i,q) {
        char ch;
        cin>>ch;
        if(ch=='f') {
            int l,r,x;
            cin>>l>>r>>x;
            l--,r--;
            int t=dsu0.find(l);
            while(t<=r) {
                a[t]=a[t]/x;
                if(a[t]==0) {
                    dsu0.del(t);
                    dsu1.del(t);
                }
                t=dsu0.find(t+1);
            }
        }
        if(ch=='c') {
            int l,r,x;
            cin>>l>>r>>x;
            l--,r--;
            int t=dsu1.find(l);
            while(t<=r) {
                a[t]=(a[t]+x-1)/x;
                if(a[t]<=1) {
                    dsu1.del(t);
                }
                t=dsu1.find(t+1);
            }
        }
        if(ch=='?') {
            int x;
            cin>>x;
            x--;
            cout<<a[x]<<'\n';
        }
    }
    return 0;
}
