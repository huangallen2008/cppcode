#include<bits/stdc++.h>
using namespace std;
main() {
    int n,m;
    long long s[1005]={},t[1005]={},lc[1005]={};
    scanf("%d%d",&n,&m);
    vector<int> d(n);
    for(int i=0;i<n;i++)
        scanf("%d",&s[i]);
    for(int i=0;i<n;i++)
        scanf("%d",&t[i]);
    for(int i=0;i<n;i++) {
        scanf("%d",&d[i]); d[i]--;
    }
    while(d.size()>1) {
        vector<int> ww,ll;
        for(int i=0;i+1<d.size();i+=2) {
            int w=d[i],l=d[i+1];
            if(s[w]*t[w]<s[l]*t[l])
                swap(w,l);
            long long a=s[w],b=t[w],c=s[l],d1=t[l];
            s[w]+=c*d1/(2*b);
            t[w]+=c*d1/(2*a);
            s[l]+=c/2;
            t[l]+=d1/2;
            ww.push_back(w);
            if(++lc[l]<m)
                ll.push_back(l);
        }
        if(d.size()%2==1)
            ww.push_back(d[d.size()-1]);
        d=ww;
        d.insert(d.end(),ll.begin(),ll.end());
    }
    printf("%d",d[0]+1);
    return 0;
}
