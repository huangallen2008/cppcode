#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define int long long
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,(n)+1)
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
#define md(x) ((x%(mod)+(mod))%(mod))
#define op(x) cout<<#x<<"="<<x<<", ";
#define ope(x) cout<<#x<<"="<<x<<endl;
#define oparr(x) cout<<#x<<":";REP(i,x.size()) cout<<x[i]<<" ";cout<<" size="<<x.size()<<endl;
#define entr cout<<endl;
const int inf=(1ll<<62);
const int maxn=1e6+5;
const int mod=998244353;
int pw(int x,int p) {
    int r=1;
    while(p>0) {
        if(p&1) {
            r*=x;r%=mod;
        }
        x*=x;
        x%=mod;
        p>>=1;
    }
    return r;
}
void solve() {
    int n;
    cin>>n;
    map<int,int> sm,m,us;
    m[n]++;
    sm[n]=1;
    queue<int> q;
    int an=0;
    q.push(n);
    while(q.size()) {
        int u=q.front();
        q.pop();
//        op(u) op(m[u]) ope(sm[u])
        if(u==1) {
            an=md(an+sm[u]);
            continue;
        }
        int cnt=m[u];
        if(u&1){
            an=md(an+sm[u]*md((pw(2,u/2)-1)*(pw(2,(u+1)/2)-1)));
            if(!us[(u+1)/2]) {
                    q.push((u+1)/2);
                    us[(u+1)/2]=1;

            }
            m[(u+1)/2]=md(m[(u+1)/2]+m[u]);
            sm[(u+1)/2]=md(sm[(u+1)/2]+sm[u]*2);
            if(!us[u/2]) {
                    q.push(u/2);
                    us[u/2]=1;

            }
            m[u/2]=md(m[u/2]+m[u]);
            sm[u/2]=md(sm[u/2]+sm[u]*2+m[u]);
        }
        else {
            an=md(an+sm[u]*md((pw(2,u/2)-1)*(pw(2,u/2)-1)));
            if(!us[u/2]) {
                    q.push(u/2);
                    us[u/2]=1;
//                    ope(u/2)
            }
            m[u/2]=md(m[u/2]+m[u]*2);
            sm[u/2]=md(sm[u/2]+2*sm[u]+2*sm[u]+m[u]);
        }
//        op(an) ope(u)
    }
    cout<<an<<'\n';
//    entr entr
}
signed main() {
    IOS();
    int T;
    cin>>T;
    while(T--) {
        solve();
    }
    return 0;
}
