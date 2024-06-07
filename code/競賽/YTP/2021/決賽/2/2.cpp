#include<bits/stdc++.h>
using namespace std;
int n,t,c=0;
string s,a[100001];
unordered_map<string,int> m;
stringstream ss;
int f(int x) {
    if(m[a[x]]==-1) return x+1;
    if(m[a[x]]==0) return c+1;
    int r=x+1;
    for(int i=0;i<m[a[x]];i++) {
        r=f(r);
    }
    return r;
}
main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>s>>t;
        if(t) m[s]=t;
        else m[s]=-1;
    }
    while(cin>>s) {
        a[c++]=s;
    }
    if(f(0)==c) cout<<"Accepted\n";
    else cout<<"Compilation Error\n";
    return 0;
}
