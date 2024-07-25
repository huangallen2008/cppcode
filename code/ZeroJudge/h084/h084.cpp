#include<bits/stdc++.h>
using namespace std;
main()
{
    int n,k,d=1,u=1,m=1;
    scanf("%d%d",&n,&k);
    vector<int> a(n),h(k);
    for(int i=0;i<n;i++) {
        scanf("%d",&a[i]);
        if(a[i]>u) u=a[i];
    }
    for(int i=0;i<k;i++)
        scanf("%d",&h[i]);
    while(d<u) {
        vector<int> h2=h;
        m=(d+u+1)/2;
        int t=0;
        for(int i=0;i<n && h2.size();i++) {
            if(a[i]>=m)
                t++;
            else {
                while(h2.size() && t>=h2[0]) { t-=h2[0]; h2.erase(h2.begin()); }
                t=0;
            }
        }
        while(h2.size() && t>=h2[0]) { t-=h2[0]; h2.erase(h2.begin()); }
        if(h2.size())
            u=m-1;
        else
            d=m;
    }
    printf("%d\n",d);
    return 0;
}
