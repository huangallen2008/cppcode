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
#define ld long double
const int mod=1e9+7;
const int maxn=1e6+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
//shuffle(a,a+n,rng)
bool greq(string a,string b) {
    if(a.size()>b.size()) return 1;
    if(a.size()<b.size()) return 0;
    RREP(i,a.size()) {
        if(a[i]>b[i]) return 1;
        if(a[i]<b[i]) return 0;
    }
    return 1;
}
bool gre(string a,string b) {
    if(a.size()>b.size()) return 1;
    if(a.size()<b.size()) return 0;
    RREP(i,a.size()) {
        if(a[i]>b[i]) return 1;
        if(a[i]<b[i]) return 0;
    }
    return 0;
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
string mul(string a,string b) {
    if(a.size()>b.size()) swap(a,b);
    int n=a.size()+b.size()+2;
    string c="";
    int na=0;
    REP(i,n) {
        int r=na;
        REP(j,i+1){
            if(j<a.size()&&i-j<b.size())r+=(a[j]-'0')*(b[i-j]-'0');
        }
//        ope(r)
        na=r/10;
        c+='0'+(r%10);
    }
    while(c.back()=='0'&&c.size()>1) c.pop_back();
    return c;
}
void solve() {
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    int ma=1,mb=1,mc=1,md=1;
    if(a=="0") ma=0;
    if(c=="0") mc=0;
    if(a[0]=='-') {
        a=a.substr(1,a.size()-1);
        ma=-1;
    }
    if(b[0]=='-') {
        b=b.substr(1,b.size()-1);
        mb=-1;
    }
    if(c[0]=='-') {
        c=c.substr(1,c.size()-1);
        mc=-1;
    }
    if(d[0]=='-') {
        d=d.substr(1,d.size()-1);
        md=-1;
    }
    reverse(ALL(a));
    reverse(ALL(b));
    reverse(ALL(c));
    reverse(ALL(d));
    if(ma*mb>mc*md) cout<<">\n";
    else if(ma*mb<mc*md) cout<<"<\n";
    else {
//            op(a)op(b)op(c)ope(d)
        string x=mul(a,d),y=mul(c,b);
//        op(x)ope(y)
        bool ac1=greq(x,y),ac2=gre(x,y);
        if(mb*ma==-1) {
            ac1^=1,ac2^=1;
            swap(ac1,ac2);
        }
//        op(ac1)ope(ac2)
        if(ac2) cout<<">\n";
        else if(!ac1) cout<<"<\n";
        else cout<<"=\n";
    }
}
signed main() {
    IOS();
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}
