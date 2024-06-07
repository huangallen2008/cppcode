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
struct DS {
    vector<int> v;
    multiset<int> se,sf;
    int se_sum=0,sf_sum=0;
    int mid=-1,sum=0,n=0,c,cnt_ful=0,vc=0;
    int an=0;
    int ren_an() {
        return (sf.size()*c-sf_sum+se_sum+(mid==-1?0:abs(mid-vc)))>>1;
    }

    void add(int x) {
        sum+=x;
        cnt_ful=sum/c,vc=sum%c;
        n++;
        if(mid==-1) {
            mid=x;
            return;
        }
        if(sf.size()<cnt_ful) {
            if(x>mid) {
                sf.insert(x); sf_sum+=x;
            }
            else if(x==mid){
                sf.insert(mid); sf_sum+=mid;
                mid=x;
            }
            else {
                sf.insert(mid); sf_sum+=mid;
                se.insert(x);se_sum+=x;
                mid=*se.rbegin();
                se.erase(se.find(*se.rbegin()));se_sum-=mid;
            }
        }
        else {
            if(!sf.size()) {
                if(x>mid) {
                    se.insert(mid);se_sum+=mid;
                    mid=x;
                }
                else {
                    se.insert(x);se_sum+=x;
                }
            }
            else if(x>*sf.begin()) {
                se.insert(mid); se_sum+=mid;
                mid=*sf.begin();
                sf.erase(sf.begin()); sf_sum+=x-mid;
                sf.insert(x);
            }
            else if(x>=mid){
                se.insert(mid); se_sum+=mid;
                mid=x;
            }
            else {
                se.insert(x); se_sum+=x;
            }
        }
        an=ren_an();
    }
    void del(int x) {
        sum-=x;
        cnt_ful=sum/c,vc=sum%c;
        if(x>mid) {
            sf.erase(sf.find(x));sf_sum-=x;
            if(sf.size()<cnt_ful) {
                sf.insert(mid); sf_sum+=mid;
                if(se.size()) {
                    mid=*se.rbegin();
                    se.erase(se.find(*se.rbegin())); se_sum-=mid;
                }
                else mid=-1;
            }
        }
        else {
            if(sf.size()>cnt_ful) {
                if(mid!=-1) {
                    se.insert(mid);se_sum+=mid;
                }
                mid=*sf.begin();
                sf.erase(sf.begin());sf_sum-=mid;
            }
            if(x==mid){
                if(se.size()) {
                    mid=*se.rbegin();
                    se.erase(se.find(*se.rbegin())); se_sum-=mid;
                }
                else mid=-1;
            }
            else {
                se.erase(se.find(x));se_sum-=x;
            }
        }
        an=ren_an();
    }
    void init(vector<int> &_v,int _c) {
        v=_v;
        c=_c;
//        op(c)oparr(v)
        for(int x:v) {
            add(x);
        }
    }
    void upd(int x,int val) {
        del(v[x]);
        v[x]=val;
        add(val);
    }
    int get_an() {
        return an;
    }
};
signed main() {
    IOS();
    int n,c,q;
    cin>>n>>c>>q;
    vector<int> a(n);
    REP(i,n) cin>>a[i];
    DS ds;
    ds.init(a,c);
    cout<<ds.get_an()<<'\n';
    REP(i,q) {
        int x,v;
        cin>>x>>v;
        x--;
        ds.upd(x,v);
        cout<<ds.get_an()<<'\n';
    }
    return 0;
}
