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
bool gre(string a,string b) {
    if(a.size()>b.size()) return 1;
    if(a.size()<b.size()) return 0;
    RREP(i,a.size()) {
        if(a[i]>b[i]) return 1;
        if(a[i]<b[i]) return 0;
    }
    return 1;
}
string add(string a,string b) {
    string c="";
    int na=0;
    int n=max(a.size(),b.size());
    REP(i,n+3) {
        int r=na;
        if(i<a.size()) r+=a[i]-'0';
        if(i<b.size()) r+=b[i]-'0';
        na=r/10;
        c+='0'+(r%10);
    }
    while(c.back()=='0'&&c.size()>1) c.pop_back();
    return c;
}
string mi(string a,string b) {
//    op(a)ope(b)
    string c="";
    int na=0;
    int n=max(a.size(),b.size());
    REP(i,n+3) {
//        ope(na)
        int r=na;
        if(i<a.size()) r+=a[i]-'0';
        if(i<b.size()) r-=b[i]-'0';
        if(r<0) na=floor((double)r/10);
        else na=r/10;
        c+='0'+(r%10+10)%10;
    }
    while(c.back()=='0'&&c.size()>1) c.pop_back();
    return c;

}
signed main() {
    IOS();
    string a,b;
    cin>>a>>b;
    int am=1,bm=1;
    if(a[0]=='-') {
            a=a.substr(1,a.size()-1);
            am=-1;
    }
    if(b[0]=='-') {
            b=b.substr(1,b.size()-1);
            bm=-1;
    }
    reverse(ALL(a));
    reverse(ALL(b));
    if(am*bm==1) {
        string c=add(a,b);
        reverse(ALL(c));
        if(am==-1) cout<<"-";
        cout<<c<<'\n';
    }
    else {
        bool abc=gre(a,b);
        string c;
        if(abc) c=mi(a,b);
        else c=mi(b,a);
        reverse(ALL(c));
        if((am==-1&&abc)||(am==1&&!abc)) {
            cout<<'-';
        }
        cout<<c<<'\n';
    }
    return 0;
}
