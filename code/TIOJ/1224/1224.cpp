#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6;
int n,l,r,d,u,an=0,tt1=N,tt2=N;
vector<pair<int,array<int,3>>> v;
unordered_map<int,int> mx,my;
vector<int> x,y;
struct S {
    int m=0,c=0,t;
};
S s[800001]={};
void pull(S &s1,S s2,S s3) {
    s1.m=min(s2.m,s3.m);
    s1.c=s2.c*(s2.m==s1.m)+s3.c*(s3.m==s1.m);
}
void push(S &s1,S &s2,S &s3) {
    s2.m+=s1.t;
    s2.t+=s1.t;
    s3.m+=s1.t;
    s3.t+=s1.t;
    s1.t=0;
}
void ut(int l,int r,int ll,int rr,int p,int w) {
    if(ll<=l && rr>=r) {
        s[w].m+=p;
        s[w].t+=p;
        return;
    }
    if(ll>r || rr<l) return;
    int m=(l+r)/2;
    push(s[w],s[w*2],s[w*2+1]);
    ut(l,m,ll,rr,p,w*2);
    ut(m+1,r,ll,rr,p,w*2+1);
    pull(s[w],s[w*2],s[w*2+1]);
}
void ud(int l,int r,int w) {
    if(l==r) {
        s[w].c=y[l+1]-y[l];
        return;
    }
    int m=(l+r)/2;
    ud(l,m,w*2);
    ud(m+1,r,w*2+1);
    pull(s[w],s[w*2],s[w*2+1]);
}
main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>l>>r>>d>>u;
        v.push_back({l,{d,u,1}});
        v.push_back({r,{d,u,-1}});
        x.push_back(l);
        x.push_back(r);
        y.push_back(d);
        y.push_back(u);
    }
    sort(v.begin(),v.end());
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    for(int i=0;i<x.size();i++) {
        if(x[i]!=tt1) {
            mx[x[i]]=i;
            tt1=x[i];
        }
        if(y[i]!=tt2) {
            my[y[i]]=i;
            tt2=y[i];
        }
    }
    ud(0,n*2-2,1);
    for(int i=0;i<v.size();) {
        tt1=v[i].first;
        do {
            ut(0,n*2-2,my[v[i].second[0]],my[v[i].second[1]]-1,v[i].second[2],1);
            i++;
        }
        while(i<v.size() && v[i].first==tt1);
        an+=(y[y.size()-1]-y[0]-(s[1].m==0?s[1].c:0))*(*upper_bound(x.begin(),x.end(),tt1)-tt1);
    }
    cout<<an<<"\n";
    return 0;
}
