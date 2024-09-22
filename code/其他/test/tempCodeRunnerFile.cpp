#pragma GCC optimize("Ofast,fast-math,unroll-loops,no-stack-protector")
#include<bits/stdc++.h>
#define int long long
#define fastio ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;


int n;
char c[30];
void f(int t,int l,int r)
{
    if(t==2*n)
    {
        for(int i=0;i<2*n;i++)
        {
            cout<<c[i];
        }
        cout<<'\n';
        return ;
    }
    if(l<n)
    {
        c[t]='(';
        f(t+1,l+1,r);
    }
    if(r<l)
    {
        c[t]=')';
        f(t+1,l,r+1);
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