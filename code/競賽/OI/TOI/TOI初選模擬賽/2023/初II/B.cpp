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
#define ld long double
#define pdd pair<ld,ld>
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
int n,m,l,e;
ld cal_v(int t,int x) {
    return (ld)x/(ld)t;
}
int check(ld bas,ld a,vector<int> &dx,vector<int> &dt) {
    int ret=0;
    REP(i,n-1) {
        if(bas<(ld)dx[i]/(ld)dt[i]-a) return -inf;
        int tt=(ld)((ld)((int)(bas/l))*(ld)dt[i]);//+((ld)((ld)((int)bas%l)+a-(ld)dx[i])/(ld)l);
        ret+=tt;
//        op(tt)
    }
    return ret;
}
int checki(int a,vector<int> &dx,vector<int> &dt) {
    int ret=0;
    REP(i,n-1) {
        if((ld)a<(ld)dx[i]/(ld)dt[i]) return -inf;
        int tt=(ld)a*(ld)((ld)dt[i]/(ld)l)-((ld)dx[i])/(ld)l;
        ret+=tt;
//        op(tt)
    }
    return ret;
}
signed main() {
    IOS();
    cin>>n>>m>>l>>e;
    vector<int> x(n+2),t(n+2);
    x[n+1]=l,t[n+1]=e;
    REP1(i,n) cin>>x[i]>>t[i];
    n+=2;
//    ope(n)
    int cnt=0;
    REP(i,n-1) cnt+=x[i]>x[i+1];
//    ope(cnt)
//    oparr(x)
    cnt=m-cnt-1;
    ope(cnt)
    vector<int> dx(n-1),dt(n-1);
    REP(i,n-1) {
        dx[i]=(x[i+1]-x[i]+l)%l;
        dt[i]=t[i+1]-t[i];
    }
//    oparr(dx)oparr(dt)
    int l=0,r=1e18,mid;
    while(l<r) {
        mid=l+(r-l>>1);
        int ret=checki(mid,dx,dt);
//        cout<<fixed<<setprecision(20)<<l<<' '<<r<<" tl+mid="<<tl+mid<<" ret="<<ret<<endl;
//        op(l)op(r)op(mid)ope(ret)
        if(ret>=cnt) r=mid;
        else l=mid+1;
    }
    ope(l)
    if(checki(l,dx,dt)>cnt) l--;
    ope(checki(l,dx,dt))
    ld dl=0,dr=1,dmid;
    int cnt_rd=200;
    while(cnt_rd--) {
        dmid=dl+(ld)(dr-dl)/(ld)2;
        int ret=check(l,mid,dx,dt);
        cout<<fixed<<setprecision(20)<<dl<<' '<<dr<<" mid="<<dmid<<" ret="<<ret<<endl;
//        op(l)op(r)op(mid)ope(ret)
        if(ret>=cnt) dr=dmid;
        else dl=dmid;
    }
    cout<<fixed<<setprecision(15)<<(ld)(l+dl)<<'\n';
    return 0;
}
