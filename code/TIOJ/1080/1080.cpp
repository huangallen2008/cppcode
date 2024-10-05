#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[100005]={},cases=1;
pair<vector<int>,long long> f(int l,int r) {
    if(r-l==0) return {{a[l]},0};
    pair<vector<int>,long long> x=f(l,(l+r)/2),y=f((l+r)/2+1,r);
    long long an=x.second+y.second,ca=0,cb=0;
    for(int i=l;i<=(l+r)/2;i++,ca++) {
        while(cb<y.first.size() && x.first[ca]>y.first[cb]) { cb++; }
        an+=cb;
    }
    vector<int> t;
    ca=0; cb=0;
    while(ca<x.first.size() || cb<y.first.size()) {
        if(ca==x.first.size()) t.push_back(y.first[cb++]);
        else if(cb==y.first.size() || x.first[ca]<y.first[cb]) t.push_back(x.first[ca++]);
        else t.push_back(y.first[cb++]);
    }
    return {t,an};
}
main()
{
    scanf("%lld",&n);
    while(n) {
        for(int i=0;i<n;i++) scanf("%lld",&a[i]);
        printf("Case #%lld: %lld\n",cases++,f(0,n-1).second);
        scanf("%lld",&n);
    }
    return 0;
}
