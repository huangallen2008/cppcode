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
const int inf=(1ll<<63)-1;
const int maxn=1e5+5;
const int mod=1e9+7;
int get_rand() { return rand(); }
struct node {
    int val;
    int pri;
    int sz=1;
    bool rev=0;
    int sum=0;
    node *lc=nullptr,*rc=nullptr;
    node(int val) : val(val) , pri(get_rand()) {
        sum=val;
    }
    void pull() {
        sz=1;
        if(lc) sz+=lc->sz;
        if(rc) sz+=rc->sz;
        sum=val;
        if(lc) sum+=lc->sum;
        if(rc) sum+=rc->sum;
    }
    void push() {
        if(rev) {
            swap(lc,rc);
            if(lc) lc->rev^=1;
            if(rc) rc->rev^=1;
            rev=0;
        }
    }
};
int sz(node* a) {
    if(a) return a->sz;
    return 0;
}
node* merge(node* A,node* B) {
    if(!A) return B;
    if(!B) return A;
    if(A->pri>B->pri) {
        A->push();
        A->rc=merge(A->rc,B);
        A->pull();
        return A;
    }
    else {
        B->push();
        B->lc=merge(A,B->lc);
        B->pull();
        return B;
    }
}
pair<node*,node*> split(node* root,int k) {
    if(!root) return {nullptr,nullptr};
    root->push();
    int le=sz(root->lc)+1;
    if(le<=k) {
        auto [A,B]=split(root->rc,k-le);
        root->rc=A;
        root->pull();
        return {root,B};
    }else {
        auto [A,B]=split(root->lc,k);
        root->lc=B;
        root->pull();
        return {A,root};
    }
}
signed main()
{
    IOS();
    node* root=nullptr;
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    REP(i,n) cin>>a[i];
    REP(i,n) root=merge(root,new node(a[i]));
    REP(i,m) {
        int l,r,x;
        cin>>x>>l>>r;
        auto [t,C]=split(root,r);
        auto [A,B]=split(t,l-1);
        if(x==1) B->rev^=1;
        else cout<<B->sum<<"\n";
        root=merge(A,merge(B,C));
    }
    return 0;
}
