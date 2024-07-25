#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
#pragma GCC target("avx2,bmi,popcnt")
#define int long long
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,n) for(int i=1;i<=(n);i++)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define RREP1(i,n) for(int i=(n);i>=1;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) (int)((x).size())
#define SQ(x) (x)*(x)
#define pii pair<int,int>
#define pipii pair<int,pii>
#define Graph vector<vector<int>>
#define Graphw vector<vector<pii>>
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
#define md(x) (((x)%(mod)+(mod))%(mod))
#define MD(x,M) (((x)%(M)+(M))%(M))
#define ld long double
#define pdd pair<ld,ld>
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
#define addmod(x,y) x=((x+(y))%mod)
#ifdef LOCAL
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) cout<<(#x)<<":";for(auto &allen:(x)) cout<<allen<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=1e9+7;
const int maxn=5e3+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
signed main() {
    IOS();
    int n,m;
    cin>>n>>m;
    bitset<maxn> a;
    vector<int> ms(m+1),sms(m+1),nms(m+1);
    REP1(i,n) {
        string s;
        cin>>s;
        reverse(ALL(s));s+='0';
        a=bitset<maxn>(s);
        vector<int> ms2(m+1),sms2(m+1),nms2(m+1);
        REP1(j,m) {
            if(!a[j]) {
                sms2[j]=min({sms[j-1],sms[j],sms2[j-1]})+1;
                ms2[j]=max({ms[j],ms2[j-1],sms2[j]});
            }
            else ms2[j]=max(ms2[j-1],ms[j]);
            nms2[j]=nms2[j-1]+nms[j]-nms[j-1]+sms2[j];
        }
        swap(ms2,ms);
        swap(sms2,sms);
        swap(nms2,nms);
    }
    cout<<nms[m]<<' '<<ms[m]<<'\n';
    return 0;
}