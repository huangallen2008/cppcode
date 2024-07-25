#include<bits/stdc++.h>
using namespace std;
int n,m,p,k,x,y;
pair<int,int> d[10005][25]={};
vector<int> ans;
vector<vector<int>> v(20005);
bool ck(int s) {
    vector<vector<int>> t;
    t=v;
    for(int i=0;i<=s;i++) {
        for(int j=0;j<k;j++) {
            t[d[i][j].first].push_back(d[i][j].second);
            t[d[i][j].second].push_back(d[i][j].first);
        }
    }
    vector<pair<int,int>> a;
    int h[n+5]={},c[n+5]={};
    for(int j=0;j<n;j++) {
        if(h[j]==0) {
            a.push_back({j,1});
            h[j]=1;
            c[j]=1;
            while(a.size()) {
                x=a[0].first; y=a[0].second;
                a.erase(a.begin());
                for(int l : t[x]) {
                    if(h[l]) {
                        if(y%2+1!=c[l])
                            return false;
                    }
                    else {
                        a.push_back({l,y%2+1});
                        h[l]=1;
                        c[l]=y%2+1;
                    }
                }
            }
        }
    }
    return true;
}
main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++) {
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    scanf("%d%d",&p,&k);
    for(int i=0;i<p;i++)
        for(int j=0;j<k;j++)
            scanf("%d%d",&d[i][j].first,&d[i][j].second);
    int ll=-1;
    for(int i=0;i<3;i++) {
        int l=ll+1,h=p,m=-1;
        while(l<h) {
            m=(l+h)/2;
            if(ck(m))
                l=m+1;
            else
                h=m;
        }
        ll=l;
        if(l<p && m>=0) {
            for(int j=0;j<k;j++)
                d[l][j]={n+1,n+1};
            printf("%d\n",l+1);
        }
        else
            break;
    }
    return 0;
}
