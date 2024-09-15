#include <bits/stdc++.h>
using namespace std;
int n,h[100001];
int f(vector<int> v,int s,int b) {
    if(s==b) return 0;
    int m=(s+b)/2,c=0,a=0;
    memset(h,0,sizeof(h));
    vector<int> v1,v2;
    for(int t:v) {
        if(t<=m) {
            c++;
            v1.push_back(t);
        }
        else {
            if((h[t]++)==0) a-=c;
            else a+=c;
            v2.push_back(t);
        }
    }
    return f(v1,s,m)+f(v2,m+1,b)+a;
}
main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>n;
    vector<int> v(n*2);
    for(int i=0;i<n*2;i++) {
        cin>>v[i];
    }
    cout<<f(v,1,n)<<"\n";
    return 0;
}
