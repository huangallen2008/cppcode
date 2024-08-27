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
const int maxn=255;
const int maxv=1e5+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
//shuffle(a,a+n,rng)
signed main() {
    IOS();
    int h,w,m;
    cin>>h>>w>>m;
    map<int,int> ro,co;
    map<int,int> ro0,co0;
    map<int,int> cnt;
    int cntr=0,cntc=0;
    int cnta=0;
    vector<pii> ros,cos;
    int rss=w,css=h;
    REP(i,m) {
        int t,a,x;
        cin>>t>>a>>x;
        if(t==1) {
            ros.pb({a,x});
            cos.pb({-1,-1});
            if(ro0[a]) {
                    cos[ro0[a]-1].f=-2;
            ro0[a]=cos.size();
                    continue;
            }
            cntr++;
            ro0[a]=cos.size();
            cnta+=w-cntc;
        }
        else {
            cos.pb({a,x});
            ros.pb({-1,-1});
            if(co0[a]) {
                ros[co0[a]-1].f=-2;
                co0[a]=ros.size();
                    continue;
            }

            cntc++;
            co0[a]=ros.size();
            cnta+=h-cntr;
        }
    }
    RREP(i,ros.size()) {
        ope(ros[i].f)
        if(ros[i].f==-1) rss--;
        else if(ros[i].f==-2) continue;
        else {
            if(ro[ros[i].f]) continue;
            ro[ros[i].f]=1;
            cnt[ros[i].s]+=rss;
        }
    }
    RREP(i,cos.size()) {
        if(cos[i].f==-1) css--;
        else if(cos[i].f==-2) continue;
        else {
                ope(i)
            if(co[cos[i].f]) continue;
            co[cos[i].f]=1;
            cnt[cos[i].s]+=css;
        }
        ope(css)
    }
    ope(cnta)
    cnt[0]+=w*h-cnta;
    vector<pii> an;
    for(auto [x,y]:cnt) {
        if(y==0) continue;
        an.pb({x,y});
    }
    cout<<an.size()<<'\n';
    for(auto [x,y]:an) cout<<x<<' '<<y<<'\n';
    return 0;
}
