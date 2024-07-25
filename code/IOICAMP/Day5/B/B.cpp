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
#define op(x) cout<<#x<<"="<<x<<", ";
#define ope(x) cout<<#x<<"="<<x<<endl;
#define oparr(x) cout<<#x<<":";REP(i,x.size()) cout<<x[i]<<" ";cout<<" size="<<x.size()<<endl;
#define entr cout<<endl;
const int mod=1e9+7;
const int maxn=1e6+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
//shuffle(a,a+n,rng)
struct BIT {
    vector<int> b;
    int n;
    void init(int _N) {
        n=_N;
        b=vector<int>(n+1);
    }
    void ud(int u,int v) {
        u++;
        for(;u<=n;u+=u&-u) b[u]+=v;
    }
    int qu(int u) {
        u++;
        int r=0;
        for(;u>0;u-=u&-u) r+=b[u];
        return r;
    }
};
signed main() {
    IOS();
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    vector<int> p1(k,-1),p2(k,-1);
    REP(i,n) {
        cin>>a[i];
        a[i]--;
        if(p1[a[i]]==-1) p1[a[i]]=i;
        else p2[a[i]]=i;
    }
    vector<int> cnt(k);
    REP(i,n) cnt[a[i]]++;
    vector<int> la,ra;
//    int cnt1=0;
    REP(i,n) {
        if(cnt[a[i]]==1) {
//            cnt1++;
        }
        if(cnt[a[i]]==2) {
            if(p1[a[i]]==i) {
                la.pb(a[i]);
            }
            else ra.pb(a[i]);
        }
    }
    int nn=la.size();
    vector<int> chid(k);
    REP(i,nn) {
        chid[la[i]]=i;
    }
    vector<int> nra(nn);
    REP(i,nn) nra[i]=chid[ra[i]];
    BIT bit;
    bit.init(k);
    int cntc=0;
//    oparr(a)oparr(la)oparr(ra)oparr(p2)
    REP(i,nn) {
        int ret=bit.qu(nra[i]);
        cntc+=i-ret;
        bit.ud(nra[i],1);
    }
//    ope(cntc)
    int an=cntc;
//    int firc=(n-cnt1)/2;
//    ope(firc)
    int cnt1=0,cnt1_2=0,cnt2=1,cnt2_2=1;
    REP(i,n) {
        if(cnt[a[i]]==1) cnt1++;
        if(cnt[a[i]]==2&&p1[a[i]]==i) {
            an+=abs(p1[a[i]]-(cnt1_2));
//            op(i)op(cnt1)op(cnt1_2)ope(an)
            cnt1++,cnt1_2++;
        }
    }
//    entr
    RREP(i,n) {
        if(cnt[a[i]]==1) cnt2++;
        if(cnt[a[i]]==2&&p2[a[i]]==i) {
            an+=abs(cnt2-cnt2_2);
//            op(i)op(cnt2)op(cnt2_2)ope(an)
            cnt2++,cnt2_2++;
        }
    }
    cout<<an<<'\n';
    return 0;
}
