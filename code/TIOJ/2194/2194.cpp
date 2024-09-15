#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
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
#ifdef LOCAL
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) cout<<(#x)<<":";REP(i,(x).size()) cout<<x[i]<<" ";cout<<" size="<<(x).size()<<endl;
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
//shuffle(a,a+n,rng)
int n,m;
vector<int> t,s,d;
int f(int o,int dd,int to) {
    int cnt=(o-to)/dd;
    int dis=cnt*dd;
    cnt++;//n=cnt  an-a1=dis
    return (cnt*(o+o-dis))>>1;
}
int check(int u,int mid) {//take time
    int ret=0;
//    op(u)ope(mid)
    REP(i,u+1) {
        if(mid>s[i]) continue;
        if(d[i]==0) return inf;
        ret+=(s[i]-mid)/d[i]+1;
        op(ret)
    }
    entr
    return ret;
}
int cal_v(int u,int mid,int time) {// get number of value
    int omid=mid;
    mid++;
    int ret=0;
//    op(u)op(mid)ope(time)
//    int zv=0;
    REP(i,u+1) {
        if(mid>s[i]) continue;
        if(d[i]==0) {
//            zv=max(zv,s[i]);
            continue;
        }
        ret+=f(s[i],d[i],mid);
        time-=(s[i]-mid)/d[i]+1;
        op(ret)
    }
    ope(111)
    assert(time>=0);
//    entr
//    op(time)
    return ret+time*omid;
}
int bin_ser(int u,int l,int r) {
//    ope(u)
    int base_time=t[u];
    int all_time=m-base_time;
//    op(u)ope(all_time)
    if(all_time<0) return 0;
    int mid;
    while(l<r) {
        mid=(l+r+1)>>1;
        int ret=check(u,mid);
        op(l)op(r)op(mid)ope(ret)
        if(ret<=all_time) r=mid-1;
        else l=mid;
    }
    ope(l)entr
    int ret=cal_v(u,l,all_time);
    return ret;
}
signed main() {
    IOS();
    cin>>n>>m;
    t=vector<int>(n);
    s=vector<int>(n);
    d=vector<int>(n);
    REP1(i,n-1) cin>>t[i];
    REP(i,n) cin>>s[i];
    REP(i,n) cin>>d[i];
    REP1(i,n-1) t[i]+=t[i-1];
//    oparr(t)
    int an=0,l=0,r=0;
    REP(i,n) {
        r=max(r,s[i]);
        if(d[i]==0) l=max(l,s[i]);
        int ret=bin_ser(i,l,r);
        an=max(an,ret);
        ope(ret)
    }
    cout<<an<<'\n';
    return 0;
}
