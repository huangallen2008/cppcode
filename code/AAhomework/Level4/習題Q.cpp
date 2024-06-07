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
const int maxn=1e5+5;
const int maxv=(1ll<<30);
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
//shuffle(a,a+n,rng)
int f(int x) {
    int t=x>>1;
    if(x&1) return t*t+x;
    else return t*t+t;
}
int n,q;
void split(map<int,int> &mp,int x) {
    auto it=mp.lower_bound(x);
    if(it->f!=x) {
        mp[x]=prev(it)->s;
    }
}
int cal_prev(map<int,int> &mp,auto it) {
    if(it->f==1||prev(it)->s) return 0;
    return f(it->f-prev(it)->f);
}
int cal_it(map<int,int> &mp,auto it) {
    if(it->f==n||it->s) return 0;
    return f(next(it)->f-it->f);
}
void ins(map<int,int> &mp,int &ans,int l,int r,int v) {
    r++;
    int an_dif=0;
    auto l_lb=mp.lower_bound(l),r_ub=mp.upper_bound(r);
    for(auto it=prev(l_lb);it!=r_ub;it++)//delete original ans
        an_dif-=cal_it(mp,it);

    split(mp,l);
    auto it_l=mp.find(l);
    split(mp,r);
    auto it_r=mp.find(r);

    mp.erase(next(it_l),it_r);
    it_l->s=v;
    an_dif+=cal_prev(mp,it_l)+cal_it(mp,it_r)+cal_it(mp,it_l);//add new ans

    while(it_l!=mp.begin()&&it_l->s==prev(it_l)->s) {//go left
        it_l--;
        an_dif-=cal_it(mp,it_l)+cal_it(mp,next(it_l));//
        mp.erase(next(it_l));
        an_dif+=cal_it(mp,it_l);
    }

    while(next(it_l)!=mp.end()&&it_l->s==next(it_l)->s) {//go right
        an_dif-=cal_it(mp,it_l)+cal_it(mp,next(it_l));//
        mp.erase(next(it_l));
        an_dif+=cal_it(mp,it_l);
    }

    ans+=an_dif;//update ans
}
signed main()
{
    IOS();
    cin>>n>>q;
    map<int,int> mp;
    mp[1]=1,mp[n]=1;
    int ans=0;
    REP(i,q) {
        int t,l,r;
        cin>>t>>l>>r;
        ins(mp,ans,l,r,t-1);
        cout<<ans<<'\n';
    }
    return 0;
}
