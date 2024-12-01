#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,(n)+1)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)(x.size())
#define SQ(x) (x)*(x)
#define pii pair<int,int>
#define Graph vector<vector<int>>
#define IOS() cin.sync_with_stdio(0),cin.tie(0),cout.tie(0)
const int inf=(1ll<<62);
const int maxn=6e5+5;
const int mod=1e9+7;
int id(int x) { return (x&~1)/2; }
vector<int> h,d0,d1;//0:(n+1)/2,1:n/2
struct seg {
    int l,r;
    int v;
};
seg s0[maxn*2],s1[maxn*2];//d[i]=abs([i+1]-[i])
void build0(int w,int l,int r) {
    s0[w]={l,r,0};
    if(l==r) {
        s0[w].v=d0[l];
        return;
    }
    int m=(l+r)/2;
    build0(w*2,l,m);
    build0(w*2+1,m+1,r);
    s0[w].v=max(s0[w*2].v,s0[w*2+1].v);
}
int qu0(int w,int ql,int qr) {
    if(ql>qr) return 0;
    if(ql<=s0[w].l&&s0[w].r<=qr) return s0[w].v;
    if(ql>s0[w].r||qr<s0[w].l) return 0;
    return max(qu0(w*2,ql,qr),qu0(w*2+1,ql,qr));
}
void build1(int w,int l,int r) {
    s1[w]={l,r,0};
    if(l==r) {
        s1[w].v=d1[l];
        return;
    }
    int m=(l+r)/2;
    build1(w*2,l,m);
    build1(w*2+1,m+1,r);
    s1[w].v=max(s1[w*2].v,s1[w*2+1].v);
}
int qu1(int w,int ql,int qr) {
    if(ql>qr) return 0;
    if(ql<=s1[w].l&&s1[w].r<=qr) return s1[w].v;
    if(ql>s1[w].r||qr<s1[w].l) return 0;
    return max(qu1(w*2,ql,qr),qu1(w*2+1,ql,qr));
}
signed main()
{
    IOS();
    int n,k,p;
    cin>>n>>k>>p;
    int n0=(n+1)/2-1,n1=n/2-1;
    h=vector<int>(n);
    d0=vector<int>(n);
    d1=vector<int>(n);
    REP(i,n) cin>>h[i];
    sort(ALL(h));
    cout<<"h:";REP(i,n) cout<<h[i]<<" ";cout<<endl;
    REP(i,n0) d0[i]=abs(h[i*2]-h[(i+1)*2]);
    REP(i,n1) d1[i]=abs(h[i*2+1]-h[(i+1)*2+1]);
//    REP(i,n0) cout<<d0[i]<<" ";cout<<endl;
//    REP(i,n1) cout<<d1[i]<<" ";cout<<endl;
    build0(1,0,n0-1);
    build1(1,0,n1-1);
    int an=inf;
    vector<int> d(n,inf);
    for(int i=0;i+k-1<n;i++) {
        int l=i,r=i+k-1;
        int l0=id(l+l%2),r0=id(r-r%2);
        int l1=id(l+(l+1)%2),r1=id(r-(r+1)%2);
//        cout<<l0<<" "<<r0<<"\n";
//        cout<<"Q"<<qu1(1,l1,r1-1)<<endl;
        int tt=max(max(qu0(1,l0,r0-1),qu1(1,l1,r1-1)),max(abs(h[i]-h[i+1]),abs(h[i+k-1]-h[i+k-2])));
        d[r]=tt;
        cout<<tt<<" ";
    }
    REP(rd,k-1) {
        int mt=inf;
        for(int i=0;i+k-1<n;i++) {
            mt=min(mt,d[i]);
            d[i+k-1]+=mt;
        }
    }
    cout<<endl;
    cout<<an<<"\n";
    return 0;
}
