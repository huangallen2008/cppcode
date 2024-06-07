#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
//#define int long long
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
#define op(x) cout<<#x<<"="<<x<<", ";
#define ope(x) cout<<#x<<"="<<x<<endl;
#define oparr(x) cout<<#x<<":";REP(i,x.size()) cout<<x[i]<<" ";cout<<" size="<<x.size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=998244353;
const int maxn=2e6+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
bool gre(string a,string b) {
    reverse(ALL(a)),reverse(ALL(b));
    if(a.size()>b.size()) return 1;
    if(a.size()<b.size()) return 0;
    RREP(i,a.size()) {
        if(a[i]>b[i]) return 1;
        if(a[i]<b[i]) return 0;
    }
    return 1;
}
string add(string a,string b) {
    oparr(a)oparr(b)
    reverse(ALL(a)),reverse(ALL(b));
    string c="";
    int na=0;
    int n=max(a.size(),b.size());
    REP(i,n+3) {
        int r=na;
        if(i<a.size()) r+=a[i]-'0';
        if(i<b.size()) r+=b[i]-'0';
        na=r/10;
        c+='0'+(r%10);
        ope(r)
    }
    while(c.size()>1&&c.back()=='0') c.pop_back();
    reverse(ALL(c));
    return c;
}
string mi(string a,string b) {
    reverse(ALL(a)),reverse(ALL(b));
    string c="";
    int na=0;
    int n=max(a.size(),b.size());
    REP(i,n+3) {
        int r=na;
        if(i<a.size()) r+=a[i]-'0';
        if(i<b.size()) r-=b[i]-'0';
        if(r<0) na=floor((double)r/10);
        else na=r/10;
        c+='0'+((r%10+10)%10);
    }
    while(c.size()>1&&c.back()=='0') c.pop_back();
    reverse(ALL(c));
    op(a)op(b)ope(c)
    return c;
}
int n;
string a,b;
vector<int> cnta,cntb;
string itos(int x) {
    string s="";
    while(x>0) {
        s+=x%10;
        x/=10;
    }
    reverse(ALL(s));
    return s;
}
string f(int i) {
    ope(i)
    if(i==n) {
        return "0";
    }
    if(cntb[a[i]-'0']) {
        cntb[a[i]-'0']--;
        cnta[a[i]-'0']--;
        ope(i)oparr(cnta)oparr(cntb)entr
        string ret=f(i+1);
        op(i)oparr(ret)
        if(ret[0]=='-') {
            cnta[a[i]-'0']++;
            cntb[a[i]-'0']++;
            goto nook;
        }
        else {
            return ret;
        }
    }
    else {
        nook:
        int rr=-1;
        for(int j=a[i]-'0'+1;j<10;j++) {
            if(cntb[j]) {
                rr=j;
                cnta[a[i]-'0']--,cntb[j]--;
                break;
            }
        }
        if(rr==-1) return "-1";
        ope(rr)oparr(cnta)oparr(cntb)
        string dis;
        string ta;
        REP(ii,10) REP(j,cntb[ii]) ta.pb('0'+ii);
        string A=ta,B=a.substr(i+1,n-1-i);
        bool imi=0;
        if(gre(A,B)) {
            dis=mi(A,B);
        }
        else {
            dis=mi(B,A);
            imi=1;
        }
        oparr(A)oparr(B)oparr(dis)entr
        string dd="";
        dd+=(char)('0'+'0'+rr-a[i]);
        for(int j=i+1;j<n;j++) dd+='0';
        string cost;
        if(imi) cost=mi(dd,dis);
            else cost=add(dis,dd);
            op(dis)op(dd)ope(cost)
        return cost;
    }
    return "-1";
}
//bool isl(int x) {
//    if(x==1) return 0;
//    while(x%10==0&&x>0) x/=10;
//    if(x==1) return 1;
//    return 0;
//}
//bool isc(int a,int b) {
//    vector<int> c1(10),c2(10);
//    while(a>0) {
//        c1[a%10]++;
//        a/=10;
//    }
//    while(b>0) {
//        c2[b%10]++;
//        b/=10;
//    }
//    REP(i,10) {
//        if(c1[i]!=c2[i]) return 0;
//    }
//    return 1;
//}
signed main() {
    IOS();
    cin>>a>>b;
    n=a.size();
    cnta=vector<int>(10);
    cntb=vector<int>(10);
    REP(i,n) cnta[a[i]-'0']++;
    REP(i,n) cntb[b[i]-'0']++;
    oparr(cnta)oparr(cntb)
    string ans=f(0);
    cout<<ans<<'\n';
    return 0;
}
