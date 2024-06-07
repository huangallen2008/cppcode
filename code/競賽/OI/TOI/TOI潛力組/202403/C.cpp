#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")
#define int long long
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define RREP1(i,n) for(int i=(n);i>=1;i--)
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
#define MD(x,M) (((x)%(M)+(M))%(M))
#define ld long double
#define pdd pair<ld,ld>
#ifdef LOCAL
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) cout<<(#x)<<":";REP(allen,(x).size()) cout<<x[allen]<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=1e9+7;
const int maxn=2e5+5;
const int maxv=1e5+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
signed main() {
    IOS();
    int n;
    cin>>n;
    string s;
    cin>>s;
    if(s.back()!='R'||s[0]!='W') {
        REP(i,s.size()-1) {
            if(s[i]=='R'&&s[i+1]=='W') {
                s=s.substr(i+1,s.size()-i-1)+s.substr(0,i+1);
            }
        }
    }
    vector<int> v;
    int cs=1;
    REP1(i,s.size()-1) {
        if((s[i-1]=='R'&&s[i]=='W')) {
            v.pb(cs);
            cs=1;
        }
        else cs+=(s[i]=='W'?1:-1);
    }
    v.pb(cs);
//    oparr(v)
    n=v.size();
    vector<int> nxt(n),pre(n);
    REP(i,n-1) nxt[i]=i+1;
    nxt[n-1]=0;
    REP1(i,n-1) pre[i]=i-1;
    pre[0]=n-1;
    int an=n;
    vector<bool> vis(n);
    for(int i=0;;i=nxt[i]) {
        if(vis[i]) break;
        vis[i]=1;
        if(v[i]!=0) {
            while(v[i]!=0) {
                if(v[i]<0) {
                    if(pre[i]==i) break;
                    v[i]+=v[pre[i]];
                    pre[i]=pre[pre[i]];
                    nxt[pre[i]]=i;
                    an--;
                }
                if(v[i]>0) {
                    if(nxt[i]==i) break;
                    v[i]+=v[nxt[i]];
                    nxt[i]=nxt[nxt[i]];
                    pre[nxt[i]]=i;
                    an--;
                }
            }
        }
    }
    cout<<an<<'\n';
    return 0;
}
/*
3
0 0 1
0 -1 0
-1 1 0

*/
