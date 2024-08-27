#include<bits/stdc++.h>
using namespace std;
int m,n;
long long an=0;
unordered_map<long long,int> mp;
int f(char x) { if((int)x<=90) return x-'A'; else return x-'a'+26; }
main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>m>>n;
    for(int i=0;i<n;i++) {
        string s;
        cin>>s;
        int t[38]={};
        long long r=0;
        for(int j=0;j<s.size();j++) r|=1ll<<f(s[j]);
        mp[r]++;
        an+=mp[(1ll<<m)-1-r];
    }
    cout<<an<<"\n";
    return 0;
}
