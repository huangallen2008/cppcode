// #pragma GCC optimize("Ofast,fast-math,unroll-loops,no-stack-protector")
#include<bits/stdc++.h>
#define int long long
#define fastio ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;


int n;
// char c[30];
string s;
void f(int t,int l,int r)
{
    if(t==2*n)
    {
        cout<<s;
        cout<<'\n';
        return ;
    }
    if(l<n)
    {
        // c[t]='(';
        s+='(';
        f(t+1,l+1,r);
        s.pop_back();
    }
    if(r<l)
    {
        s+=')';
        // c[t]=')';
        f(t+1,l,r+1);
        s.pop_back();
    }
    return ;
}
signed main()
{
    while(cin>>n)
    {
        f(0,0,0);
        cout<<'\n';
    }
}