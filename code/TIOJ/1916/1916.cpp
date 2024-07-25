#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
const int inf=(1ll<<62)-1;
const int maxn=2e3+5;
const int mod=1e9+7;
/*
struct node {
    int c=0,f=0;
};
struct seg {
    int r1,r2,c1,c2;
    node v;
};
vector<vector<seg>> s;
vector<vector<int>> a;
node merge(node a,node b) {
    if(a.c==b.c) return {a.c,a.f+b.f};
    else if(a.f>b.f) return {a.c,a.f-b.f};
    else return {b.c,b.f-a.f};
}
node merge(node a,node b,node c,node d) {
    return merge(merge(a,b),merge(c,d));
}
void build(int w1,int w2,int r1,int r2,int c1,int c2) {
    s[w1][w2].r1=r1;
    s[w1][w2].c1=c1;
    s[w1][w2].r2=r2;
    s[w1][w2].c2=c2;
    if(r1==r2&&c1==c2) {
        s[w1][w2].v={a[r1][c1],1};
        return;
    }
    if(r1>r2||c1>c2) return;
    int mr=(r1+r2)/2,mc=(c1+c2)/2;
    build(w1*2,w2*2,r1,mr,c1,mc);
    build(w1*2+1,w2*2,mr+1,r2,c1,mc);
    build(w1*2,w2*2+1,r1,mr,mc+1,c2);
    build(w1*2+1,w2*2+1,mr+1,r2,mc+1,c2);
    s[w1][w2].v=merge(s[w1*2][w2*2].v,s[w1*2+1][w2*2].v,s[w1*2][w2*2+1].v,s[w1*2+1][w2*2+1].v);
}
node query(int w1,int w2,int r1,int r2,int c1,int c2) {
    seg t=s[w1][w2];
    if(r1<=t.r1&&t.r2<=r2&&c1<=t.c1&&t.c2<=c2) return t.v;
    if(r1>t.r2||r2<t.r1||c1>t.c2||c2<t.c1||r1>r2||c1>c2) return {0,0};
    return merge(query(w1*2,w2*2,r1,r2,c1,c2),query(w1*2+1,w2*2,r1,r2,c1,c2),query(w1*2,w2*2+1,r1,r2,c1,c2),query(w1*2+1,w2*2+1,r1,r2,c1,c2));
}*/
struct am {
    int c,f;
};
struct node {
    int r1,r2,c1,c2;
    am v;
    node *ul=nullptr,*ur=nullptr,*bl=nullptr,*br=nullptr;
    node(int _r1,int _r2,int _c1,int _c2) {
        r1=_r1; r2=_r2;
        c1=_c1; c2=_c2;
    }
};
vector<vector<int>> a;
am merge(am a,am b) {
    if(a.c==b.c) return {a.c,a.f+b.f};
    else if(a.f>b.f) return {a.c,a.f-b.f};
    else return {b.c,b.f-a.f};
}
am merge(am a,am b,am c,am d) {
    return merge(merge(a,b),merge(c,d));
}
node* build(node* root,int r1,int r2,int c1,int c2) {
    cout<<r1<<" "<<r2<<" "<<c1<<" "<<c2<<endl;
    if(r1==r2&&c1==c2) {
        root->v={a[r1][c1],1};
//        cout<<"ok"<<endl;
        return root;
    }
    if(r1>r2||c1>c2) {
        root->v={0,0};
        return root;
    }
    int mr=(r1+r2)/2,mc=(c1+c2)/2;
    root->ul=new node(r1,mr,c1,mc);
    root->ul=build(root->ul,r1,mr,c1,mc);
    root->ur=new node(r1,mr,mc+1,c2);
    root->ur=build(root->ur,r1,mr,mc+1,c2);
    root->bl=new node(mr+1,r2,c1,mc);
    root->bl=build(root->bl,mr+1,r2,c1,mc);
    root->br=new node(mr+1,r2,mc+1,c2);
    root->br=build(root->br,mr+1,r2,mc+1,c2);
    root->v=merge(root->ul->v,root->ur->v,root->bl->v,root->br->v);
//    cout<<r1<<" "<<r2<<" "<<c1<<" "<<c2<<endl;
    return root;
}
am query(node* root,int r1,int r2,int c1,int c2) {
    if(r1<=root->r1&&root->r2<=r2&&c1<=root->c1&&root->c2<=c2) return root->v;
    if(r1>root->r2||r2<root->r1||c1>root->c2||c2<root->c1) return {0,0};
}
main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n;
    while(cin>>n) {
        if(n==0) break;
        a=vector<vector<int>> (n,vector<int>(n));
        REP(i,n) REP(j,n) cin>>a[i][j];
        node* root=nullptr;
        root=new node(0,n-1,0,n-1);
        root=build(root,0,n-1,0,n-1);
        int q;
        cin>>q;
        REP(i,q) {
            int r1,r2,c1,c2;
            cin>>r1>>r2>>c1>>c2;
            am t=query(root,r1,r2,c1,c2);
            if(t.f==0) cout<<"-1\n";
            else cout<<t.c<<"\n";
        }

    }
    return 0;
}
