#include<bits/stdc++.h>
using namespace std;
main()
{
    int n,a[25]={},x,c[25]={};
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%d",&x);
        a[x]=i;
    }
    while(cin>>c[0]) {
        for(int i=1;i<n;i++)
            scanf("%d",&c[i]);
        vector<int> v;
        v.push_back(c[a[1]]);
        for(int i=2;i<=n;i++) {
            x=c[a[i]];
            if(x>v[v.size()-1])
                v.push_back(x);
            else
                v[lower_bound(v.begin(),v.end(),x)-v.begin()]=x;
        }
        printf("%d\n",v.size());
    }
    return 0;
}
